(* 
"The generation of random numbers is too important to be left to chance." – Robert R. Coveyou
*)
let pp_int out s =
  Format.fprintf out "%016X" s

external seed : int -> unit = "oneseq_seed"
external xsh_xs : unit -> int = "oneseq_xsh_rs"
