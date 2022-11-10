#ifndef TORE_H
#define TORE_H

#include <vector>

#include "mathematics.h"

class Tore {
protected:
    Vector  m_center;
    double  m_intRadius;
    double  m_extRadius;
    int     m_precision;

public:
    Tore() {} //do not use
    explicit Tore(const Vector &c = Vector(0.0), const double &ir = 1.0, const double &er = 2.0, const int &p = 10) : m_center(c), m_intRadius(ir), m_extRadius(er), m_precision(p) {}
    ~Tore() {}

    const std::vector<Vector> getPoints() const;
    const int getPrecision() const { return m_precision; }
};

#endif // TORE_H
