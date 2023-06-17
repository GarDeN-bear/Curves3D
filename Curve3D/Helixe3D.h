#pragma once
#include "Curve3D.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

namespace Curve3D {
    class Helixe3D : public Curve3D{
    public:
        Helixe3D(std::vector<float>, float, float);
        std::vector<float> getPoint3D(float) const override;
        std::vector<float> getVector3D(float) const override;
        Helixe3D(Helixe3D&) = delete;
        Helixe3D& operator=(Helixe3D&) = delete;
    private:
        std::vector<float> C; // center
        float R; // radious
        float S; // step 
    };
}