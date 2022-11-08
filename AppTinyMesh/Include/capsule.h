#ifndef CAPSULE_H
#define CAPSULE_H

#include <vector>

#include "mathematics.h"

class Capsule {
protected:
    Vector  m_center;
    double  m_radius;
    double  m_height;
    int     m_precision; //!< Number of triangles

public:
    Capsule() {} //do not use
    explicit Capsule(const Vector &c = Vector(0.0), const double &r = 1.0, const double &h = 1.0, const int &p = 10) : m_center(c), m_radius(r), m_height(h), m_precision(p) {}
    ~Capsule() {}

    const double getPrecision() const { return m_precision; }
    const Vector getCenter() const { return m_center; }
    const double getHeight() const { return m_height; }

    std::vector<Vector> getPoints() const;
};

#endif // CAPSULE_H
