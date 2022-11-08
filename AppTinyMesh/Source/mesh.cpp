#include "mesh.h"

/*!
\class Mesh mesh.h

\brief Core triangle mesh class.
*/



/*!
\brief Initialize the mesh to empty.
*/
Mesh::Mesh()
{
}

/*!
\brief Initialize the mesh from a list of vertices and a list of triangles.

Indices must have a size multiple of three (three for triangle vertices and three for triangle normals).

\param vertices List of geometry vertices.
\param indices List of indices wich represent the geometry triangles.
*/
Mesh::Mesh(const std::vector<Vector>& vertices, const std::vector<int>& indices) :vertices(vertices), varray(indices)
{
  normals.resize(vertices.size(), Vector::Z);
}

/*!
\brief Create the mesh.

\param vertices Array of vertices.
\param normals Array of normals.
\param va, na Array of vertex and normal indexes.
*/
Mesh::Mesh(const std::vector<Vector>& vertices, const std::vector<Vector>& normals, const std::vector<int>& va, const std::vector<int>& na) :vertices(vertices), normals(normals), varray(va), narray(na)
{
}

/*!
\brief Reserve memory for arrays.
\param nv,nn,nvi,nvn Number of vertices, normals, vertex indexes and vertex normals.
*/
void Mesh::Reserve(int nv, int nn, int nvi, int nvn)
{
  vertices.reserve(nv);
  normals.reserve(nn);
  varray.reserve(nvi);
  narray.reserve(nvn);
}

/*!
\brief Empty
*/
Mesh::~Mesh()
{
}

/*!
\brief Smooth the normals of the mesh.

This function weights the normals of the faces by their corresponding area.
\sa Triangle::AreaNormal()
*/
void Mesh::SmoothNormals()
{
  // Initialize 
  normals.resize(vertices.size(), Vector::Null);

  narray = varray;

  // Accumulate normals
  for (int i = 0; i < varray.size(); i += 3)
  {
    Vector tn = Triangle(vertices[varray.at(i)], vertices[varray.at(i + 1)], vertices[varray.at(i + 2)]).AreaNormal();
    normals[narray[i + 0]] += tn;
    normals[narray[i + 1]] += tn;
    normals[narray[i + 2]] += tn;
  }

  // Normalize 
  for (int i = 0; i < normals.size(); i++)
  {
    Normalize(normals[i]);
  }
}

/*!
\brief Add a smooth triangle to the geometry.
\param a, b, c Index of the vertices.
\param na, nb, nc Index of the normals.
*/
void Mesh::AddSmoothTriangle(int a, int na, int b, int nb, int c, int nc)
{
  varray.push_back(a);
  narray.push_back(na);
  varray.push_back(b);
  narray.push_back(nb);
  varray.push_back(c);
  narray.push_back(nc);
}

/*!
\brief Add a triangle to the geometry.
\param a, b, c Index of the vertices.
\param n Index of the normal.
*/
void Mesh::AddTriangle(int a, int b, int c, int n)
{
  varray.push_back(a);
  narray.push_back(n);
  varray.push_back(b);
  narray.push_back(n);
  varray.push_back(c);
  narray.push_back(n);
}

/*!
\brief Add a smmoth quadrangle to the geometry.

Creates two smooth triangles abc and acd.

\param a, b, c, d  Index of the vertices.
\param na, nb, nc, nd Index of the normal for all vertices.
*/
void Mesh::AddSmoothQuadrangle(int a, int na, int b, int nb, int c, int nc, int d, int nd)
{
  // First triangle
  AddSmoothTriangle(a, na, b, nb, c, nc);

  // Second triangle
  AddSmoothTriangle(a, na, c, nc, d, nd);
}

/*!
\brief Add a quadrangle to the geometry.

\param a, b, c, d  Index of the vertices and normals.
*/
void Mesh::AddQuadrangle(int a, int b, int c, int d)
{
  AddSmoothQuadrangle(a, a, b, b, c, c, d, d);
}

/*!
\brief Compute the bounding box of the object.
*/
Box Mesh::GetBox() const
{
  if (vertices.size() == 0)
  {
    return Box::Null;
  }
  return Box(vertices);
}

/*!
\brief Creates an axis aligned box.

The object has (disc.precision+2) vertices, disc.precision normals and disc.precision triangles.
\param box The box.
*/
Mesh::Mesh(const Box& box)
{
  // Vertices
  vertices.resize(8);

  for (int i = 0; i < 8; i++)
  {
    vertices[i] = box.Vertex(i);
  }

  // Normals
  normals.push_back(Vector(-1, 0, 0));
  normals.push_back(Vector(1, 0, 0));
  normals.push_back(Vector(0, -1, 0));
  normals.push_back(Vector(0, 1, 0));
  normals.push_back(Vector(0, 0, -1));
  normals.push_back(Vector(0, 0, 1));

  // Reserve space for the triangle array
  varray.reserve(12 * 3);
  narray.reserve(12 * 3);

  AddTriangle(0, 2, 1, 4);
  AddTriangle(1, 2, 3, 4);

  AddTriangle(4, 5, 6, 5);
  AddTriangle(5, 7, 6, 5);

  AddTriangle(0, 4, 2, 0);
  AddTriangle(4, 6, 2, 0);

  AddTriangle(1, 3, 5, 1);
  AddTriangle(3, 7, 5, 1);

  AddTriangle(0, 1, 5, 2);
  AddTriangle(0, 5, 4, 2);

  AddTriangle(3, 2, 7, 3);
  AddTriangle(6, 7, 2, 3);
}

/*!
\brief Creates an axis aligned disc.

The object has 8 vertices, 6 normals and 12 triangles.
\param disc The disc.
*/
Mesh::Mesh(const Disc &disc) {
    // Vertices
    //nb triangles + 1 point to complete de circle + 1 center point
    int prec = disc.getPrecision();
    vertices.resize(prec + 2);
    std::vector<Vector> points = disc.getPoints();
    for (int i = 0; i < prec + 2; i++) {
        vertices[i] = points[i];
    }

    // Normals
    for (int i = 0; i < prec; i++) {
        normals.push_back(Vector(0, -1, 0));
    }

    // Reserve space for the triangle and place them
    varray.reserve(prec * 3);
    narray.reserve(prec * 3);

    for (int i = 1; i < prec; i++) {
        AddTriangle(0, i, i+1, 0);
    }
    AddTriangle(0, prec, 1, 0);
}

Mesh::Mesh(const Cylinder &cylinder) {
    int     prec = cylinder.getPrecision();
    auto    points = cylinder.getPoints();

    // Vertices
    vertices.resize(points.size());
    for (int i = 0; i < points.size(); i++){
        vertices[i] = points[i];
    }

    // Normals
    //0->center base
    //1..n->points
    //n+1->center with height
    normals.push_back(Vector(0, -1, 0));
    for (int i = 1; i < points.size()/2; i++) {
        normals.push_back(Normalized(vertices[i]-vertices[0]));
    }
    normals.push_back(Vector(0, 1, 0));

    // Reserve space for the triangle and place them
    varray.reserve(prec*4*3);
    narray.reserve(prec*4*3);

    for (int i = 0; i < prec; i++) {
        AddTriangle(0, i, i+1, 0); //bottom
        AddTriangle(prec+1, i+prec+1, i+prec+2, prec+2); //top

        AddTriangle(i, i+1, i+prec+1, i);
        AddTriangle(i+prec+2, i+prec+1, i+1, (i+1)%prec);
    }
    AddTriangle(0, prec, 1, 0);
    AddTriangle(prec+1, (prec+1)*2, prec+2, prec+2);

    AddTriangle(prec, 1, (prec+1)*2, prec);
    AddTriangle(prec+1, (prec+1)*2, 1, 1);
}

Mesh::Mesh(const Sphere &sphere) {
    int     prec = sphere.getPrecision();
    auto    points = sphere.getPoints();
    Vector  center = sphere.getCenter();

    // Vertices
    vertices.resize(points.size());
    for (int i = 0; i < points.size(); i++)
        vertices[i] = points[i];

    // Normals
    for (auto p : points)
        normals.push_back(Normalized(p - center));

    // Reserve space for the triangle and place them
    varray.reserve((prec-1)*prec*2);
    narray.reserve((prec-1)+prec*2);

    // the center divisions
    for (int i = 0; i < prec - 2; i++) {
        // the triangles in a row
        for (int j = 0; j < prec; j++) {
            AddTriangle((i*(prec+1))+j, (i*(prec+1))+(j+1), ((i+1)*(prec+1))+j, (i*(prec+1))+j);
            AddTriangle(((i+1)*(prec+1))+j, (i*(prec+1))+(j+1), ((i+1)*(prec+1))+(j+1), ((i+1)*(prec+1))+j);
        }
    }
    // top and bottom row
    for (int i = 0; i < prec; i++) {
        //bottom
        AddTriangle(points.size()-2, i, (i+1)%(prec+1), points.size()-2);
        //top
        AddTriangle(points.size()-1, i+(prec-2)*(prec+1), ((i+1)%(prec+1))+(prec-2)*(prec+1), points.size()-1);
    }
}

Mesh::Mesh(const Capsule &capsule) {
    int     prec = capsule.getPrecision();
    auto    points = capsule.getPoints();
    Vector  center = capsule.getCenter();
    double  height = capsule.getHeight();
    Vector  topCenter = center + Vector(0, height, 0);

    // Vertexes
    vertices.resize(points.size());
    for (int i = 0; i < points.size(); i++)
        vertices[i] = points[i];

    // Normals
    for (auto p : points)
        normals.push_back(Normalized(p - center));
    /*for (int i = 0; i < prec; i++)
        normals.push_back(Normalized(p - center)); // for top and base of the cylinder
    for ()*/

    // Reserve sapce for the triangles and place them
    varray.reserve((prec-1)*2 + 3*prec);
    narray.reserve((prec-1)*2 + 3*prec);

    //cylinder
    for (int i = 0; i < prec; i++) {
        AddTriangle(i, (i+1)%(prec+1), prec+1+i, i);
        AddTriangle(prec+1+i, (i+1)%(prec+1), prec+1+(i%(prec+1)), prec+1+i);
    }
}

Mesh::Mesh(const HeightField &hf) {
    auto    points = hf.getPoints();
    auto    height = hf.getHeight();
    auto    width = hf.getWidth();

    // Vertexes
    vertices.resize(points.size());
    for (int i = 0; i < points.size(); i++)
        vertices[i] = points[i];

    // Normals
    for (auto p : points) {
        normals.push_back(Vector(0, -1, 0));
    }

    // Reserve space for the triangles and place them
    varray.reserve(((height-1)*(width-1)) * 2);
    narray.reserve(((height-1)*(width-1)) * 2);

    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width - 1; j++) {
            /*
                1 -- 2
                |    |
                |    |
                3 -- 4
            */
            int p1, p2, p3, p4;
            p1 = (i * width) + j;
            p2 = (i*width) + j + 1;
            p3 = ((i+1) * width) + j;
            p4 = ((i+1) * width) + j + 1;
            //std::cerr << p1 << ", " << p2 << ", " << p3 << ", " << p4 << std::endl;

            AddSmoothTriangle(p1, p1, p3, p3, p4, p4);
            AddSmoothTriangle(p1, p1, p4, p4, p2, p2);
        }
    }
}

/*!
\brief Scale the mesh.
\param s Scaling factor.
*/
void Mesh::Scale(double s)
{
    // Vertexes
    for (int i = 0; i < vertices.size(); i++)
    {
        vertices[i] *= s;
    }

    if (s < 0.0)
    {
        // Normals
        for (int i = 0; i < normals.size(); i++)
        {
            normals[i] = -normals[i];
        }
    }
}



#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QRegularExpression>
#include <QtCore/qstring.h>

/*!
\brief Import a mesh from an .obj file.
\param filename File name.
*/
void Mesh::Load(const QString& filename)
{
  vertices.clear();
  normals.clear();
  varray.clear();
  narray.clear();

  QFile data(filename);

  if (!data.open(QFile::ReadOnly))
    return;
  QTextStream in(&data);

  // Set of regular expressions : Vertex, Normal, Triangle
  QRegularExpression rexv("v\\s*([-|+|\\s]\\d*\\.\\d+)\\s*([-|+|\\s]\\d*\\.\\d+)\\s*([-|+|\\s]\\d*\\.\\d+)");
  QRegularExpression rexn("vn\\s*([-|+|\\s]\\d*\\.\\d+)\\s*([-|+|\\s]\\d*\\.\\d+)\\s*([-|+|\\s]\\d*\\.\\d+)");
  QRegularExpression rext("f\\s*(\\d*)/\\d*/(\\d*)\\s*(\\d*)/\\d*/(\\d*)\\s*(\\d*)/\\d*/(\\d*)");
  while (!in.atEnd())
  {
    QString line = in.readLine();
    QRegularExpressionMatch match = rexv.match(line);
    QRegularExpressionMatch matchN = rexn.match(line);
    QRegularExpressionMatch matchT = rext.match(line);
    if (match.hasMatch())//rexv.indexIn(line, 0) > -1)
    {
      Vector q = Vector(match.captured(1).toDouble(), match.captured(2).toDouble(), match.captured(3).toDouble()); vertices.push_back(q);
    }
    else if (matchN.hasMatch())//rexn.indexIn(line, 0) > -1)
    {
      Vector q = Vector(matchN.captured(1).toDouble(), matchN.captured(2).toDouble(), matchN.captured(3).toDouble());  normals.push_back(q);
    }
    else if (matchT.hasMatch())//rext.indexIn(line, 0) > -1)
    {
      varray.push_back(matchT.captured(1).toInt() - 1);
      varray.push_back(matchT.captured(3).toInt() - 1);
      varray.push_back(matchT.captured(5).toInt() - 1);
      narray.push_back(matchT.captured(2).toInt() - 1);
      narray.push_back(matchT.captured(4).toInt() - 1);
      narray.push_back(matchT.captured(6).toInt() - 1);
    }
  }
  data.close();
}

/*!
\brief Save the mesh in .obj format, with vertices and normals.
\param url Filename.
\param meshName %Mesh name in .obj file.
*/
void Mesh::SaveObj(const QString& url, const QString& meshName) const
{
  QFile data(url);
  if (!data.open(QFile::WriteOnly))
    return;
  QTextStream out(&data);
  out << "g " << meshName << Qt::endl;
  for (int i = 0; i < vertices.size(); i++)
    out << "v " << vertices.at(i)[0] << " " << vertices.at(i)[1] << " " << vertices.at(i)[2] << QString('\n');
  for (int i = 0; i < normals.size(); i++)
    out << "vn " << normals.at(i)[0] << " " << normals.at(i)[1] << " " << normals.at(i)[2] << QString('\n');
  for (int i = 0; i < varray.size(); i += 3)
  {
    out << "f " << varray.at(i) + 1 << "//" << narray.at(i) + 1 << " "
      << varray.at(i + 1) + 1 << "//" << narray.at(i + 1) + 1 << " "
      << varray.at(i + 2) + 1 << "//" << narray.at(i + 2) + 1 << " "
      << "\n";
  }
  out.flush();
  data.close();
}

