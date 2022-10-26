#ifndef CYLINDER_H
#define CYLINDER_H

#include "disc.h"

class Cylinder : public Disc {
protected:
    double  m_height;

public:
    Cylinder() : Disc(Vector(0.0)) {} //do not use
    explicit Cylinder(const Vector &c = Vector(0.0), const double &r = 1.0, const int &p = 10, const double &h = 2.0) : Disc(c, r, p), m_height(h) {}
    ~Cylinder() {}

    std::vector<Vector> getPoints() const;
};

#endif // CYLINDER_H
