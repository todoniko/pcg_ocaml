(* 
"The generation of random numbers is too important to be left to chance." – Robert R. Coveyou
*)


external seed : int -> unit = "oneseq_seed"

module XSH_RS = struct
  external bits : unit -> int = "oneseq_xsh_rs"
  external int : int -> int = "oneseq_xsh_rs_bounded"
end

module XSH_RR = struct
  external bits : unit -> int = "oneseq_xsh_rr"
  external int : int -> int = "oneseq_xsh_rr_bounded"
end

module RXS_M = struct
  external bits : unit -> int = "oneseq_rxs_m"
  external int : int -> int = "oneseq_rxs_m_bounded"
end

module XSL_RR = struct
  external bits : unit -> int = "oneseq_xsl_rr"
  external int : int -> int = "oneseq_xsl_rr_bounded"
end

let pp_int out s =
  Format.fprintf out "%016X" s
