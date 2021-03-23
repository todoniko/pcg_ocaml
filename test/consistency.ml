let test_output ~f ~seed ~name =
  Pcg.seed seed;
  Printf.printf "# Few results of Pcg.%s with seed 0x%X\n" name seed;
  for i = 1 to 7 do
    Printf.printf "%i - 0x%016X\n" i (f ())
  done

let _ = test_output ~f:Pcg.xsh_rs ~seed:42 ~name:"xsh_rs"
