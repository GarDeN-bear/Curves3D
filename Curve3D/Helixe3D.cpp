#include "Helixe3D.h"

namespace Curve3D{
    Helixe3D::Helixe3D(std::vector<float> C, float R, float S) : C(C), R(R), S(S) {
        CurveType = "Helixe3D";
    }
    std::vector<float> Helixe3D::getPoint3D(float t) const{
        std::vector<float> result = C;
        result.at(0) += R*cos(t);
        result.at(1) += R*sin(t);
        result.at(2) += S*t;
        return result;
    }
    std::vector<float> Helixe3D::getVector3D(float t) const{
        std::vector<float> result = C;
        result.at(0) = -R*sin(t);
        result.at(1) = R*cos(t);
        result.at(2) = S;
        return result;
    }
}