#include <iostream>
#include "Fractal.h"
#include "Grid2D.h"
#include "BMPHandler.h"
#include "ColoringMethods.h"

using namespace std;

int main() {
  Params params;
  params.show();
  
  Grid2D grid(params);
  grid.setup();
  
  Mandelbrot mandelbrotSet;
  mandelbrotSet.init(params);
  
  std::vector<int> iterationCounts(grid.nPt());

  for (int i = 0; i < grid.nPt(); i++) {
    iterationCounts[i] = mandelbrotSet.compute(grid(i));
  }
  
  // coloring
  ColoringMethods colMethod(&params);
  Color* color = new Color[params.pixel_nx*params.pixel_ny];
  colMethod.simple(color, iterationCounts);

  // save
  saveBMP(params.outputImageName, color, params.pixel_nx, params.pixel_ny);
  
  delete[] color;

  return 0;
}
