// HeightField

// Self include
#include "heightField.h"

#include <iostream>
#include <fstream>

/*!
\class HeightField heightField.h
\brief An axis aligned height field.

The class stores the center of the field, as well as the points
of the field in a 2D-vector containing the height of each points.
A height field is a rectangular field with width*height values
between 0 and 255.

The vertices of a heightField can be obtained by the HeightField::getPoints()
member function which returns a vector of all the vertices.
*/

/*!
\brief Gives all the points of the height field.
*/
std::vector<Vector> HeightField::getPoints() const {
    std::vector<Vector> toRet;

    for (int i = 0; i < m_field.size(); i++) {
        for (int j = 0; j < m_field.at(i).size(); j++) {
            //toRet.push_back(Vector(j*m_distance, (double)m_field.at(i).at(j)/m_scale, i*m_distance));
            toRet.push_back(Vector(j*m_distance, i*m_distance, m_field.at(i).at(j)));
        }
    }
    return toRet;
}

void HeightField::exampleField() {
    m_field.clear();
    for (int i = 0; i < 255; i++) {
        std::vector<short>  tmp;
        for (int j = 0; j < 255; j++) {
            tmp.push_back((i+j)/2);
        }
        m_field.push_back(tmp);
    }
}

void HeightField::smallExampleField() {
    m_field.clear();
    std::vector<short>  one;
    std::vector<short>  two;

    one.push_back(0);
    one.push_back(5);
    two.push_back(5);
    two.push_back(10);
    m_field.push_back(one);
    m_field.push_back(two);
}

void HeightField::mediumExampleField() {
    m_field.clear();
    std::vector<std::vector<short>> tmp = {{0, 5, 0, 5, 0}, {5, 0, 5, 0, 5}, {0, 5, 0, 5, 0}};
    m_field = tmp;
}

void HeightField::loadField(const std::string &file) {
    m_field.clear();
    std::ifstream   stream;

    stream.open(file, std::ifstream::in);

    char c = stream.get();
    std::string tmpNb;
    while (stream.good()) {
        std::vector<short> tmp;
        tmpNb = "";
        while (c != '\n') {
            if (c != ' ') {
                tmpNb += c;
            }
            else {
                tmp.push_back(atoi(tmpNb.c_str()));
                tmpNb = "";
            }
            c = stream.get();
        }
        tmp.push_back(atoi(tmpNb.c_str()));
        m_field.push_back(tmp);
        c = stream.get();
    }
    stream.close();

    outputDebug();
}

void HeightField::outputDebug() const {
    for (int i = 0; i < m_field.size(); i++) {
        for (int j = 0; j < m_field[i].size(); j++) {
            std::cerr << m_field[i][j] << ", ";
        }
        std::cerr << std::endl;
    }
}
