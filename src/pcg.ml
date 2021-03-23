(* 
"The generation of random numbers is too important to be left to chance." – Robert R. Coveyou
*)
let pp_int out s =
  Format.fprintf out "%016X" s

external seed : int -> unit = "oneseq_seed"
external xsh_rs : unit -> int = "oneseq_xsh_rs"
external xsh_rs_bound : int -> int = "oneseq_xsh_rs_bounded"
