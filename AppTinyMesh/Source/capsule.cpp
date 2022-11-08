// Capsule

// Self include
#include "capsule.h"
#include "disc.h"

/*!
\class Capsule capsule.h
\brief An axis aligned capsule.

The class stores the center of the base of the capsule, as well as the radius,
the height and the precision we want.

The vertices of a capsule can be obtained by the Capsule::getPoints()
member function which returns a vector of all the vertices.
*/

/*!
\brief Gives all the points of the capsule.
*/
std::vector<Vector> Capsule::getPoints() const {
    // precision-1*[precision-1]->points from the lowest circle to the top one
    // (precision-1)²->lowest point
    // (precision-1)²+1->highest point
    std::vector<Vector> toRet;
    double              angle = 0;
    double              angleToAdd = (M_PI/2) / m_precision;
    Vector              topCenter = m_center + Vector(0, m_height, 0);

    //base of cylinder
    {
        Disc    currentDisc(m_center, m_radius, m_precision);
        auto    currentPoints = currentDisc.getPoints();

        for (int i = 1; i < currentPoints.size(); i++)
            toRet.push_back(currentPoints[i]);
    }
    //top of cylinder
    {
        Disc    currentDisc(topCenter, m_radius, m_precision);
        auto    currentPoints = currentDisc.getPoints();

        for (int i = 1; i < currentPoints.size(); i++)
            toRet.push_back(currentPoints[i]);
    }
    //bottom half sphere
    for (int i = 0; i < m_precision - 1; i++) {
        angle += angleToAdd;

        double  currentRadius = sin(angle) * m_radius;
        Vector  currentCenter = m_center - Vector(0, cos(angle) * m_radius, 0);
        Disc    currentDisc(currentCenter, currentRadius, m_precision);

        auto    currentPoints = currentDisc.getPoints();
        for (int j = 1; j < currentPoints.size(); j++)
            toRet.push_back(currentPoints[j]);
    }
    //top half sphere
    angle = 0;
    for (int i = 0; i < m_precision - 1; i++) {
        angle += angleToAdd;

        double  currentRadius = sin(angle) * m_radius;
        Vector  currentCenter = topCenter + Vector(0, cos(angle) * m_radius, 0);
        Disc    currentDisc(currentCenter, currentRadius, m_precision);

        auto    currentPoints = currentDisc.getPoints();
        for (int j = 1; j < currentPoints.size(); j++)
            toRet.push_back(currentPoints[j]);
    }

    toRet.push_back(m_center - Vector(0, m_radius, 0)); //bottom point
    toRet.push_back(topCenter + Vector(0, m_radius, 0)); //top point
    return toRet;
}
