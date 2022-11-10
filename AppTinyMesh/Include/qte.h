#ifndef __Qte__
#define __Qte__

#include "ui-interface.h"
#include "realtime.h"
#include "meshcolor.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
  Ui::Assets uiw;				//!< Interface

  MeshWidget* meshWidget;		//!< Viewer
  MeshColor meshColor;		//!< Mesh.

public:
  MainWindow();
  ~MainWindow();
  void CreateActions();
  void UpdateGeometry();

public slots:
  void editingSceneLeft(const Ray&);
  void editingSceneRight(const Ray&);
  void BoxMeshExample();
  void SphereImplicitExample();
  void ResetCamera();
  void UpdateMaterial();

  void disc();
  void cylinder();
  void sphere();
  void capsule();
  void tore();

  void heightField();
  void loadHF();

  void upHf();
  void downHf();

  void distanceSlider();

private:
  HeightField   m_hf = HeightField(Vector(0,0,0), 0.1);
};

#endif
