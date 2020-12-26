#include "Params.h"

Params::Params() {
  pixel_nx = 1920;
  pixel_ny = 1080;

  grid_nx = 1921;
  grid_ny = 1081;
  
  x_min = -2.5;
  x_max = 1.5;

  double ratio = 1.0*pixel_ny/pixel_nx;

  y_min = -(x_max-x_min)*ratio/2.;
  y_max = (x_max-x_min)*ratio/2.;
  
  max_iterations = 1000;
  max_modulus  = 2.0;

  refColor.init(0, 255, 0);

  outputImageName = "green.bmp";
}

#if 0
Params::Params(const Params& p) {
  pixel_nx = p.pixel_nx;
  pixel_ny = p.pixel_ny;

  x_min = p.x_min;
  x_max = p.x_max;

  y_min = p.y_min;
  y_max = p.y_max;
  
  max_iterations = p.max_iterations;
  max_modulus  = p.max_modulus;
};
#endif

void Params::show(){
  std::cout << "pixel nx        = " << pixel_nx << std::endl;
  std::cout << "pixel ny        = " << pixel_ny << std::endl;
  std::cout << "grid nx         = " << grid_nx << std::endl;
  std::cout << "grid ny         = " << grid_ny << std::endl;
  std::cout << "grid x_min      = " << x_min << std::endl;
  std::cout << "grid x_max      = " << x_max << std::endl;
  std::cout << "grid y_min      = " << y_min << std::endl;
  std::cout << "grid y_max      = " << y_max << std::endl;

  std::cout << "max iterations  = " << max_iterations << std::endl;
  std::cout << "max modulus     = " << max_modulus << std::endl;

  std::cout << "Reference color = " << refColor << std::endl;
};
