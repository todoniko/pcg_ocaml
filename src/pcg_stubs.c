#include "generator.h"

#include <caml/mlvalues.h>

#define Val_uint(t) ((Val_int((uint64_t)t)))
#define Uint_val(V) ((uint64_t)(Int_val(V)))
 
prng t;

void
oneseq_seed(value s)
{
  pcg_oneseq_64_srandom_r(&t,Uint_val(s));
}

CAMLprim value
oneseq_xsh_rs(value unit)
{
  return Val_uint(pcg_oneseq_64_xsh_rs_32_random_r(&t));
}
