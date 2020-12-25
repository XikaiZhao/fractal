#ifndef __FRACTAL_H__
#define __FRACTAL_H__

#include <complex>
#include "Params.h"

class Fractal;
class Mandelbrot;

//////////////////////////////////////////////////////////////
class Fractal {
  public:
    Fractal() {
      max_iterations = 1000;
      max_modulus = 1.0;
    }

    void init(Params params) {
      max_iterations = params.max_iterations;
      max_modulus = params.max_modulus;
    }
    
    // return number of iterations to diverge
    int compute(std::complex<double> z_0);
  
    virtual std::complex<double> iteration_func(std::complex<double> z_k, 
                                                std::complex<double> z_0) {
      return z_0;
    }
    
  private:
    int max_iterations;
    double max_modulus;

}; 


//////////////////////////////////////////////////////////////
class Mandelbrot : public Fractal {
  public:
    std::complex<double> iteration_func(std::complex<double> z_k, std::complex<double> z_0) {
      return z_k*z_k + z_0;
    }
}; 


#endif // FRACTAL_H
