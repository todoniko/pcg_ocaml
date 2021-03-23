#include <stdint.h>
#include "output.h"

/* Low Level PCG */
#define PCG_DEFAULT_MUL_64 6364136223846793005ULL
#define PCG_DEFAULT_INC_64 1442695040888963407ULL

typedef struct pcg_state_64 {
  uint64_t state;
} prng;

inline void pcg_oneseq_64_step_r(struct pcg_state_64* rng)
{
  rng->state = rng->state * PCG_DEFAULT_MUL_64
                          + PCG_DEFAULT_INC_64;
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

#define DE_OUTPUT(SEQ, OP, S, R)                           \
inline uint ## R ## _t                                     \
pcg_ ## SEQ ## _ ## S ## _ ## OP ## _ ## R ## _random_r(struct  pcg_state_ ## S * rng) \
{                                                          \
  uint ## S ## _t oldstate = rng->state;                   \
  pcg_ ## SEQ ## _ ## S ## _step_r(rng);                   \
  return pcg_output_ ## OP ## _ ## S ## _ ## R (oldstate); \
}                                                          \
                                                           \
inline uint ## R ## _t                                     \
pcg_ ## SEQ ## _ ## S ## _ ## OP ## _ ## R ## _boundedrand_r(struct pcg_state_ ## S * rng, uint ## R ## _t bound)             \
{                                                          \
  uint ## R ## _t threshold = -bound % bound;              \
  for (;;) {                                               \
    uint ## R ## _t r = pcg_ ## SEQ ## _ ## S ## _ ## OP ## _ ## R ## _random_r(rng);                                         \
    if (r >= threshold) return r % bound;                  \
  }                                                        \
}  

DE_OUTPUT(oneseq, xsh_rs, 64, 32)
DE_OUTPUT(oneseq, xsh_rr, 64, 32)
DE_OUTPUT(oneseq, rxs_m,  64, 32)
DE_OUTPUT(oneseq, xsl_rr, 64, 32)
// DE_OUTPUT(oneseq, xsl_rr_rr, 64, 64)
