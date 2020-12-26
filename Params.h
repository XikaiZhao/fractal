#ifndef __PARAMS_H__
#define __PARAMS_H__

#include <complex>
#include <vector>
#include <string>
#include "Color.h"

class Params{
  public:
    Params();
    //Params(const Params& p);

    void show();

    int pixel_nx, pixel_ny;
    int grid_nx, grid_ny;

    double x_min, x_max;
    double y_min, y_max;
    
    int max_iterations;
    double max_modulus;

    Color refColor;

    std::string outputImageName;
};


#endif // PARAMS_H
