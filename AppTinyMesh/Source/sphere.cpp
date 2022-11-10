// Sphere

// Self include
#include "sphere.h"
#include "disc.h"
#include <iostream>

/*!
\class Sphere sphere.h
\brief An axis aligned sphere.

The class stores the center of the sphere, as well as the radius
and the precision we want.

The vertices of a sphere can be obtained by the Sphere::getPoints()
member function which returns a vector of all the vertices.
*/

/*!
\brief Gives all the points of the sphere.
*/
std::vector<Vector> Sphere::getPoints() const {
    // precision-1*[precision-1]->points from the lowest circle to the top one
    // (precision-1)²->lowest point
    // (precision-1)²+1->highest point
    std::vector<Vector> toRet;
    double              angle = 0;
    double              angleToAdd = M_PI / m_precision;

    for (int i = 0; i < m_precision - 1; i++) {
        angle += angleToAdd;

        double  currentRadius = sin(angle) * m_radius;
        std::cerr << i << "-" << currentRadius << std::endl;
        Vector  currentCenter = m_center - Vector(0, cos(angle) * m_radius, 0);
        Disc    currentDisc(currentCenter, currentRadius, m_precision);

        auto    currentPoints = currentDisc.getPoints();
        for (int j = 1; j < currentPoints.size(); j++)
            toRet.push_back(currentPoints[j]);
    }

    toRet.push_back(m_center - Vector(0, m_radius, 0));
    toRet.push_back(m_center + Vector(0, m_radius, 0));
    return toRet;
}
