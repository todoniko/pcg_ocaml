#include <stdint.h>

/* XSH RS */
inline uint32_t pcg_output_xsh_rs_64_32(uint64_t state)
{
  return (uint32_t)(((state >> 22u) ^ state) >> ((state >> 61u) + 22u));
}

/* XSH RR */
inline uint32_t pcg_rotr_32(uint32_t value, unsigned int rot)
{
  asm ("rorl   %%cl, %0" : "=r" (value) : "0" (value), "c" (rot));
  return value;
  /* return (value >> rot) | (value << ((- rot) & 31)); */
}

inline uint32_t pcg_output_xsh_rr_64_32(uint64_t state)
{
  return pcg_rotr_32(((state >> 18u) ^ state) >> 27u, state >> 59u);
}

/* RXS M */
inline uint32_t pcg_output_rxs_m_64_32(uint64_t state)
{
  return (((state >> ((state >> 59u) + 5u)) ^ state)
	  * 12605985483714917081ull) >> 32u;
}

/* XSL RR (only defined for >= 64 bits) */
inline uint32_t pcg_output_xsl_rr_64_32(uint64_t state)
{
  return pcg_rotr_32(((uint32_t)(state >> 32u)) ^ (uint32_t)state,
		     state >> 59u);
}

/* XSL RR RR (only defined for >= 64 bits) */
inline uint64_t pcg_output_xsl_rr_rr_64_64(uint64_t state)
{
  uint32_t rot1 = (uint32_t)(state >> 59u);
  uint32_t high = (uint32_t)(state >> 32u);
  uint32_t low  = (uint32_t)state;
  uint32_t xored = high ^ low;
  uint32_t newlow  = pcg_rotr_32(xored, rot1);
  uint32_t newhigh = pcg_rotr_32(high, newlow & 31u);
  return (((uint64_t)newhigh) << 32u) | newlow;
}

/* RXS-M-SH TODO */
