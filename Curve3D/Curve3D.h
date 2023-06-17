#pragma once
#include <vector>
#include <string>
namespace Curve3D
{
    class Curve3D{
    public:
        virtual std::vector<float> getPoint3D(float) const = 0;
        virtual std::vector<float> getVector3D(float) const = 0;
        std::string getCurveType() const {
            return CurveType;
        }
        virtual ~Curve3D(){}
    protected:
        std::string CurveType;
    };
}
