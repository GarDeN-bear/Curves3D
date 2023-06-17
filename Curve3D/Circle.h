#pragma once
#include "Curve3D.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

namespace Curve3D {
    class Circle : public Curve3D{
    public:
        Circle(std::vector<float>, float);
        std::vector<float> getPoint3D(float) const override;
        std::vector<float> getVector3D(float) const override;
        float getR(){ return R; }
        Circle(Circle&) = delete;
        Circle& operator=(Circle&) = delete;
    private:
        std::vector<float> C; // center
        float R; // radious
    };
}
