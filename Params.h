#ifndef __PARAMS_H__
#define __PARAMS_H__

#include <complex>
#include <vector>

class Params{
  public:
    Params();

    void show();

    int pixel_nx, pixel_ny;

    double x_min, x_max;
    double y_min, y_max;
    
    int max_iterations;
    double max_modulus;
};


#endif // PARAMS_H
