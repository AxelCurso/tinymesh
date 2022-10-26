// Cylinder

// Self include
#include "cylinder.h"

std::vector<Vector> Cylinder::getPoints() const {
    std::vector<Vector> toRes = Disc::getPoints();
    int                 discLength = toRes.size();

    for (int i = 0; i < discLength; i++) {
        toRes.push_back(Vector(toRes.at(i)[0], toRes.at(i)[1]+m_height, toRes.at(i)[2]));
    }
    return toRes;
}
