#include "Ellipse.h"

namespace Curve3D{
    Ellipse::Ellipse(std::vector<float> C, float maxR, float minR) : C(C), maxR(maxR), minR(minR) {
        CurveType = "Ellipse";
    }
    std::vector<float> Ellipse::getPoint3D(float t) const{
        std::vector<float> result = C;
        result.at(0) += maxR*cos(t);
        result.at(1) += minR*sin(t);
        return result;
    }
    std::vector<float> Ellipse::getVector3D(float t) const{
        std::vector<float> result = C;
        result.at(0) = -maxR*sin(t);
        result.at(1) = minR*cos(t);
        result.at(2) = 0;
        return result;
    }
}