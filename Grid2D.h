#ifndef __GRID2D_H__
#define __GRID2D_H__

#include <complex>
#include <vector>

#include "Params.h"

class Grid2D{
  public:
    Grid2D() {
      pt_nx = 1001;
      pt_ny = 1001;
      x_min = -1.0;
      x_max = 1.0;
      y_min = -1.0;
      y_max = 1.0;
      dx = (x_max - x_min) / (pt_nx-1);
      dy = (y_max - y_min) / (pt_ny-1);
    }
    
    Grid2D(Params params); 

    void setup();
    
    int nxPt() { return pt_nx; };
    int nyPt() { return pt_ny; };
    int nPt()  { return pt_nx*pt_ny; };

    std::complex<double> operator()(int i) { 
      return grid[i];
    }
    
    std::complex<double> operator()(int i, int j) { 
      return grid[i + j*pt_nx];
    }
    
    std::complex<double> center(int i, int j) { 
      return (  grid[i     + j    *pt_nx]
              + grid[(i+1) + j    *pt_nx]
              + grid[i     + (j+1)*pt_nx]
              + grid[(i+1) + (j+1)*pt_nx]
             )/4.0; 
    }

  private:
    int pt_nx, pt_ny;
    
    double x_min, x_max;
    double y_min, y_max;

    double dx, dy;

    // x direction first then y direction
    std::vector<std::complex<double> > grid;

};


#endif // GRID2D_H
