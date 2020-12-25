#include <iostream>
#include "Fractal.h"
#include "Grid2D.h"
#include "BMPHandler.h"
#include "Color.h"

using namespace std;

int main() {
  Params params;
  params.show();
  
  Grid2D grid(params);
  grid.setup();
  
  Mandelbrot set;
  set.init(params);
  
  std::vector<int> iterations(grid.nPt());

  for (int i = 0; i < grid.nPt(); i++) {
    iterations[i] = set.compute(grid(i));
  }
  
  Color* color = new Color[params.pixel_nx*params.pixel_ny];
  for(int j = 0; j < grid.nxPt()-1; j++) {
    for(int i = 0; i < grid.nyPt()-1; i++){
      color[i+j*grid.nxPt()].init(255, 255, 255);
      if ( (iterations[i + j * grid.nxPt()] < params.max_iterations)
          || (iterations[(i+1) + j * grid.nxPt()] < params.max_iterations)
          || (iterations[i + (j+1) * grid.nxPt()] < params.max_iterations)
          || (iterations[(i+1) + (j+1) * grid.nxPt()] < params.max_iterations)
         ) {
     //   std::cout<<"(" << grid(i,j).real()<<", "<<grid(i,j).imag() <<")" << ": " << iterations[i + j * grid.nxPt()]<<std::endl;
        color[i+j*grid.nxPt()].init(0, 0, 0);
      }
    }
  }
  
  string filename = "test.bmp";
  //string filename = "/mnt/c/Users/Ahmad/Dropbox/ray-tracer-master/test.bmp";
  saveBMP(filename, color, params.pixel_nx, params.pixel_ny);
  
  delete color;

  return 0;
}
