#ifndef DISC_H
#define DISC_H

#include <vector>

#include "mathematics.h"

class Disc {
protected:
    Vector  center;
    double  radius;
    int     precision; //!< Number of triangles

public:
    Disc() {} //do not use
    explicit Disc(const Vector &c = Vector(0.0), const double &r = 1.0, const int &p = 10) : center(c), radius(r), precision(p) {}
    ~Disc() {}

    const double getPrecision() const { return precision; }

    std::vector<Vector> getPoints() const;
};

#endif // DISC_H
