#include "ColoringMethods.h"

void ColoringMethods::simple(Color* color, const std::vector<int>& iterCounts){
  for(int j = 0; j < params->pixel_ny; j++){
    for(int i = 0; i < params->pixel_nx; i++){
      double avgIter = averageIterations(i,j, iterCounts);
      double intensity = std::sqrt(avgIter/params->max_iterations);
      color[i+j*(params->pixel_nx)] = params->refColor*intensity;
    }
  }
}

double ColoringMethods::averageIterations(int i, int j, const std::vector<int>& iterCounts){
      return  
        ( iterCounts[i + j * params->grid_nx]
        + iterCounts[(i+1) + j * params->grid_nx]
        + iterCounts[i + (j+1) * params->grid_nx]
        + iterCounts[(i+1) + (j+1) * params->grid_nx]
        )/4.0; 
}
