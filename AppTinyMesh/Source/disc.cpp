// Disc

// Self include
#include "disc.h"

/*!
\class Disc disc.h
\brief An axis aligned disc.

The class stores the center of the disc, as well as the radius
and the precision we want.

The vertices of a disc can be obtained by the Box::getPoints()
member function which returns a vector of all the vertices.
*/

/*!
\brief Gives all the points of the circle of the disc.
*/
std::vector<Vector> Disc::getPoints() const {
    std::vector<Vector> toRes;
    double              angleToAdd;
    double              angle;

    angleToAdd = 2 * M_PI / precision;
    angle = 0;
    toRes.push_back(center);
    for (int i = 0; i < precision+1; i++) {
        toRes.push_back(Vector(cos(angle) * radius, center[1], sin(angle) * radius));
        angle += angleToAdd;
    }
    return toRes;
}
