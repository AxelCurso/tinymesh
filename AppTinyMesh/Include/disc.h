#ifndef DISC_H
#define DISC_H

#include <vector>

#include "mathematics.h"

class Disc {
protected:
    Vector  m_center;
    double  m_radius;
    int     m_precision; //!< Number of triangles

public:
    Disc() {} //do not use
    explicit Disc(const Vector &c = Vector(0.0), const double &r = 1.0, const int &p = 10) : m_center(c), m_radius(r), m_precision(p) {}
    ~Disc() {}

    const double getPrecision() const { return m_precision; }

    std::vector<Vector> getPoints() const;
};

#endif // DISC_H
