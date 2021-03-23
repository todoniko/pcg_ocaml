(lang dune 2.0)
(generate_opam_files true)

(name pcg_ocaml)
(license "MIT")
(source (github todoniko/pcg_ocaml))
(authors "Nicola Todorov")
(maintainers "Nicola Todorov <nmtodorov@gmail.com")
(homepage "https://www.pcg-random.org")

(package
 (name pcg_ocaml)
 (synopsis "PCG - better random number generator")
 (description "PCG is a family of simple, fast, space-efficient and
 statistically good algorithms for random number generation.")
 
 (depends
  (ocaml (>= 4.07))
  (dune (>= 2.0)))
  (tags ("pcg" "random" "prng")))
