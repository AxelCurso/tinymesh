#ifndef SPHERE_H
#define SPHERE_H

#include <vector>

#include "mathematics.h"

class Sphere {
protected:
    Vector  m_center;
    double  m_radius;
    int     m_precision; //!< Number of triangles

public:
    Sphere() {} //do not use
    explicit Sphere(const Vector &c = Vector(0.0), const double &r = 1.0, const int &p = 10) : m_center(c), m_radius(r), m_precision(p) {}
    ~Sphere() {}

    const double getPrecision() const { return m_precision; }
    const Vector getCenter() const { return m_center; }

    std::vector<Vector> getPoints() const;
};

#endif // SPHERE_H
