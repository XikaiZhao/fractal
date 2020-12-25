#include "Params.h"

Params::Params() {
  pixel_nx = 1920;
  pixel_ny = 1080;

  x_min = -2.0;
  x_max = 2.0;
  y_min = -2.0;
  y_max = 2.0;
  
  max_iterations = 1000;
  max_modulus  = 2.0;
};

void Params::show(){
  printf("pixel nx     = %10d\n", pixel_nx);
  printf("pixel ny     = %10d\n", pixel_ny);
  printf("grid x_min   = %10.5f\n", x_min);
  printf("grid x_max   = %10.5f\n", x_max);
  printf("grid y_min   = %10.5f\n", y_min);
  printf("grid y_max   = %10.5f\n", y_max);

  printf("max iterations = %10d\n", max_iterations);
  printf("max modulus    = %10.5f\n", max_modulus);
};
