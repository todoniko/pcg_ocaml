let test_bits ~bits_f ~seed_f ~desc =
  seed_f 42;
  Printf.printf
    "# %s bits output:\n" desc;
  for i = 1 to 7 do
    Printf.printf "%i - 0x%016X\n" i (bits_f ())
  done

let _ =
  test_bits
    ~bits_f:Pcg.Oneseq.XSH_RS.bits
    ~seed_f:Pcg.Oneseq.seed
    ~desc:"XorShift High with Random Shift";
  test_bits
    ~bits_f:Pcg.Oneseq.XSH_RR.bits
    ~seed_f:Pcg.Oneseq.seed
    ~desc:"XorShift High with Random Rotate";
  test_bits
    ~bits_f:Pcg.Oneseq.RXS_M.bits
    ~seed_f:Pcg.Oneseq.seed
    ~desc:"Random XorShift with Multiplication";
  test_bits
    ~bits_f:Pcg.Oneseq.XSL_RR.bits
    ~seed_f:Pcg.Oneseq.seed
    ~desc:"XorShift Low with Random Rotate";
