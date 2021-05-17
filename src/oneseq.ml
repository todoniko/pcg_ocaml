(* 
"The generation of random numbers is too important to be left to chance." – Robert R. Coveyou
*)

external seed : int -> unit = "oneseq_seed" [@@noalloc]

module XSH_RS = struct
  external bits : unit -> int = "oneseq_xsh_rs" [@@noalloc]
  external int : int -> int = "oneseq_xsh_rs_bounded" [@@noalloc]
end

module XSH_RR = struct
  external bits : unit -> int = "oneseq_xsh_rr" [@@noalloc]
  external int : int -> int = "oneseq_xsh_rr_bounded" [@@noalloc]
end

module RXS_M = struct
  external bits : unit -> int = "oneseq_rxs_m" [@@noalloc]
  external int : int -> int = "oneseq_rxs_m_bounded" [@@noalloc]
end

module XSL_RR = struct
  external bits : unit -> int = "oneseq_xsl_rr" [@@noalloc]
  external int : int -> int = "oneseq_xsl_rr_bounded" [@@noalloc]
end

let pp_int out s =
  Format.fprintf out "%016X" s
