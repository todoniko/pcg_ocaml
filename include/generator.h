#include <stdint.h>
#include "output.h"

/* Low Level PCG */
#define PCG_DEFAULT_MULTIPLIER_64  6364136223846793005ULL
#define PCG_DEFAULT_INCREMENT_64   1442695040888963407ULL

typedef struct pcg_state_64 {
  uint64_t state;
} prng;

inline void pcg_oneseq_64_step_r(struct pcg_state_64* rng)
{
  rng->state = rng->state * PCG_DEFAULT_MULTIPLIER_64
    + PCG_DEFAULT_INCREMENT_64;
}

/* PCG API */
// ONESEQ
inline void pcg_oneseq_64_srandom_r(struct pcg_state_64* rng,
                                    uint64_t initstate)
{
  rng->state = 0U;
  pcg_oneseq_64_step_r(rng);
  rng->state += initstate;
  pcg_oneseq_64_step_r(rng);
}

inline uint32_t pcg_oneseq_64_xsh_rs_32_random_r(struct pcg_state_64* rng)
{
  uint64_t oldstate = rng->state;
  pcg_oneseq_64_step_r(rng);
  return pcg_output_xsh_rs_64_32(oldstate);
}

inline uint32_t pcg_oneseq_64_xsh_rs_32_boundedrand_r(struct pcg_state_64* rng,
                                                      uint32_t bound)
{
  uint32_t threshold = -bound % bound;
  for (;;) {
    uint32_t r = pcg_oneseq_64_xsh_rs_32_random_r(rng);
    if (r >= threshold)
      return r % bound;
  }
}
