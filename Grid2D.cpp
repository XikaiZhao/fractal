#include "Grid2D.h"

Grid2D::Grid2D(Params params) {
  pt_nx = params.pixel_nx+1;
  pt_ny = params.pixel_ny+1;
  x_min = params.x_min;
  x_max = params.x_max;
  y_min = params.y_min;
  y_max = params.y_max;
  dx = (x_max - x_min) / (pt_nx-1);
  dy = (y_max - y_min) / (pt_ny-1);
}

void Grid2D::setup() {
  grid.resize(pt_nx*pt_ny);
  for(int j = 0; j < pt_ny; j++) {
    for(int i = 0; i < pt_nx; i++){
      grid[i+j*pt_nx].real(x_min + i*dx);
      grid[i+j*pt_nx].imag(y_min + j*dy);
    }
  }
}

