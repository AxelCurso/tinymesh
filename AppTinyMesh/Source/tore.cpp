// Tore

// Self include
#include "tore.h"

/*!
\class Tore tore.h
\brief An axis aligned tore.

The class stores the center of the tore, as well as the inner and outer
radius and the precision we want.

The vertices of a tore can be obtained by the Tore::getPoints()
member function which returns a vector of all the vertices.
*/

/*!
\brief Gives all the points of the tore.
*/
const std::vector<Vector> Tore::getPoints() const {
    std::vector<Vector>   toRet;
    double  one;
    double  two;
    double  toMul;

    toMul = (2*M_PI) / m_precision;
    toRet.resize(m_precision*m_precision);

    for (int i = 0; i < m_precision; i++) {
        one = toMul * i;
        for (int j = 0; j < m_precision; j++) {
            two = toMul * j;
            toRet[j+i*m_precision] = Vector(cos(one) * (m_extRadius + cos(two) * m_intRadius), sin(one) * (m_extRadius + cos(two) * m_intRadius), sin(two) * m_intRadius);
        }
    }
    return toRet;
}
