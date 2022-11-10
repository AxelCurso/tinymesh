#ifndef HEIGHTFIELD_H
#define HEIGHTFIELD_H

#include <vector>

#include "mathematics.h"

class HeightField {
private:
    Vector  m_center;
    double  m_distance; //distance between points
    double  m_scale = 20.0;

    std::vector<std::vector<short>> m_field;

public:
    HeightField() : m_center(Vector(0, 0, 0)), m_distance(0) { exampleField(); }
    explicit HeightField(const Vector &c = Vector(0, 0, 0), const double &d = 1.0) : m_center(c), m_distance(d) { exampleField(); }
    ~HeightField() {}

    const int getWidth() const { return m_field.at(0).size(); }
    const int getHeight() const { return m_field.size(); }
    void setDistance(const double &d) { m_distance = d; }
    const double getDistance() const { return m_distance; }

    std::vector<Vector> getPoints() const;
    void upScale() { m_scale *= 0.9; }
    void downScale() { m_scale *= 1.1; }

    void loadField(const std::string &file);
    void exampleField();
    void smallExampleField();
    void mediumExampleField();

    void applyElevation(const double& x, const double &y, const double &radius, const double &percentage);

private:
    void outputDebug() const;
};

#endif // HEIGHTFIELD_H
