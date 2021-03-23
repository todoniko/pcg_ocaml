#include "generator.h"

#include <caml/mlvalues.h>

#define Val_uint(t) ((Val_int((uint64_t)t)))
#define Uint_val(V) ((uint64_t)(Int_val(V)))
 
#define DE_CAML(SEQ, OP, S, R)                         \
CAMLprim value                                         \
SEQ ##_## OP(value unit)                               \
{ return Val_uint(pcg_## SEQ ##_## S ##_## OP ##_## R ##_random_r(& SEQ)); }\
                                                       \
CAMLprim value                                         \
SEQ ##_## OP ##_bounded(value b)                       \
{ return Val_uint(pcg_## SEQ ##_## S ##_## OP ##_## R ##_boundedrand_r(& SEQ, Uint_val(b))); }

prng oneseq;

void
oneseq_seed(value s)
{
  pcg_oneseq_64_srandom_r(&oneseq, Uint_val(s));
}

DE_CAML(oneseq, xsh_rs, 64, 32)
DE_CAML(oneseq, xsh_rr, 64, 32)
DE_CAML(oneseq, rxs_m,  64, 32)
DE_CAML(oneseq, xsl_rr, 64, 32)
// DE_CAML(oneseq, xsl_rr_rr, 64, 64)
