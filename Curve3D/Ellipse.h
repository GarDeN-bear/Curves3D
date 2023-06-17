#pragma once
#include "Curve3D.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

namespace Curve3D {
    class Ellipse : public Curve3D{
    public:
        Ellipse(std::vector<float>, float, float);
        std::vector<float> getPoint3D(float) const override;
        std::vector<float> getVector3D(float) const override;
        Ellipse(Ellipse&) = delete;
        Ellipse& operator=(Ellipse&) = delete;
    private:
        std::vector<float> C; // center
        float minR; // minimum radious
        float maxR; // maximum radious
    };
}