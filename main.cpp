#include "Curve3D/Circle.h"
#include "Curve3D/Ellipse.h"
#include "Curve3D/Helixe3D.h"
#include <algorithm>
#include <memory>

int main(){
    std::vector<std::shared_ptr<Curve3D::Curve3D>> curves; // container of objects
    srand(time(NULL));
    int count = 3; // counter of population
    // Population a container (e.g. vector or list) of objects of these types created in random manner with random parameters.
    for(int i = 0; i < count; ++i){
        std::vector<float> C;
        C.push_back(rand() % 10);
        C.push_back(rand() % 10);
        C.push_back(rand() % 10);
        float R = rand() % 100;
        float k = rand() % 10;
        float S = rand() % 10;
        curves.push_back(std::make_shared<Curve3D::Circle>(C, R));
        curves.push_back(std::make_shared<Curve3D::Ellipse>(C, R, R / k));
        curves.push_back(std::make_shared<Curve3D::Helixe3D>(C, R, S));
    }
    // Output of coordinates of points and derivatives of all curves in the container at t=PI/4.
    float t = M_PI / 4;
    for(int i = 0; i < curves.size(); ++i){
        std::cout << curves.at(i)->getCurveType() + "_" << i << ":\n" 
        << "x = " << curves.at(i)->getPoint3D(t).at(0) << " "
        << "y = " << curves.at(i)->getPoint3D(t).at(1) << " "
        << "z = " << curves.at(i)->getPoint3D(t).at(2) << '\n'
        << "dx = " << curves.at(i)->getVector3D(t).at(0) << " "
        << "dy = " << curves.at(i)->getVector3D(t).at(1) << " "
        << "dz = " << curves.at(i)->getVector3D(t).at(2) << '\n'
        << std::endl;
    }
    std::cout << std::endl;
    // Population a second container that would contain only circles from the first container.
    std::vector<std::shared_ptr<Curve3D::Circle>> circles; // second container with only circles
    for(int i = 0; i < curves.size(); ++i){
        if (auto circle = std::dynamic_pointer_cast<Curve3D::Circle>(curves.at(i))) {
            circles.push_back(circle);
        }
    }
    std::cout << std::endl;
    // Sorting the second container in the ascending order of circles’ radii.
    std::sort(circles.begin(), circles.end(), [](auto c1, auto c2) {
        return c1->getR() < c2->getR();
    });
    // Check order of circles in the second container
    for(int i = 0; i < circles.size(); ++i){
        std::cout << "R = " << circles.at(i)->getR() << std::endl;
    }
    // Computing the total sum of radii of all curves in the second container.
    float sum = 0;
    for (auto& c : circles) {
        sum += c->getR();
    }
    std::cout << "Sum =" << sum << std::endl;

}