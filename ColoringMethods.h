#ifndef __COLORINGMETHODS_H__
#define __COLORINGMETHODS_H__

#include "Params.h"

class ColoringMethods {
  public:
    ColoringMethods(Params* p) : params(p){};

    void simple(Color* color, const std::vector<int>& iterCounts);

    double averageIterations(int i, int j, const std::vector<int>& iterCounts);

  private:
    Params* params; 
};

#endif // COLORINGMETHODS_H
