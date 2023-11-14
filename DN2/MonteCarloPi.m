(* ::Package:: *)

MonteCarloPi[n_] := Module[{x, y, krogTocke, steviloTock, razmerje, priblizekPi},
  krogTocke = Select[RandomReal[{-1, 1}, {n, 2}], Norm[#] <= 1 &];
  steviloTock = Length[krogTocke];
  razmerje = steviloTock/n;
  priblizekPi = razmerje*4;
  Return[priblizekPi];
]


