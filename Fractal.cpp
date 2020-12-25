#include "Fractal.h"
#include <iostream>

int Fractal :: compute(std::complex<double> z_0) {
  int iter = 1;
  std::complex<double> z_k = z_0;
  while (iter < max_iterations){
    z_k = iteration_func(z_k, z_0);
//    std::cout<<z_k.real()<<std::endl;
    if (std::norm(z_k) > max_modulus) {
      return iter;
    }
    iter++;
  }
  return iter;
}
