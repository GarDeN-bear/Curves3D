#include "Circle.h"

namespace Curve3D{
    Circle::Circle(std::vector<float> C, float R) : C(C), R(R) {
        CurveType = "Circle";
    }
    std::vector<float> Circle::getPoint3D(float t) const{
        std::vector<float> result = C;
        result.at(0) += R*cos(t);
        result.at(1) += R*sin(t);
        return result;
    }
    std::vector<float> Circle::getVector3D(float t) const{
        std::vector<float> result = C;
        result.at(0) = -R*sin(t);
        result.at(1) = R*cos(t);
        result.at(2) = 0;
        return result;
    }

}