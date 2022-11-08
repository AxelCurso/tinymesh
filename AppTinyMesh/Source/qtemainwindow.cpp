#include "qte.h"
#include "implicits.h"

#include "heightField.h"

#include <QFileDialog>

MainWindow::MainWindow()
{
	// Chargement de l'interface
	uiw.setupUi(this);

	// Chargement du GLWidget
	meshWidget = new MeshWidget;
	QGridLayout* GLlayout = new QGridLayout;
	GLlayout->addWidget(meshWidget, 0, 0);
	GLlayout->setContentsMargins(0, 0, 0, 0);
	uiw.widget_GL->setLayout(GLlayout);

	// Creation des connect
	CreateActions();

	meshWidget->SetCamera(Camera(Vector(10, 0, 0), Vector(0.0, 0.0, 0.0)));
    m_hf = HeightField(Vector(0,0,0), 0.1);
}

MainWindow::~MainWindow()
{
	delete meshWidget;
}

void MainWindow::CreateActions()
{
	// Buttons
	connect(uiw.boxMesh, SIGNAL(clicked()), this, SLOT(BoxMeshExample()));
	connect(uiw.sphereImplicit, SIGNAL(clicked()), this, SLOT(SphereImplicitExample()));
	connect(uiw.resetcameraButton, SIGNAL(clicked()), this, SLOT(ResetCamera()));
	connect(uiw.wireframe, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
	connect(uiw.radioShadingButton_1, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
	connect(uiw.radioShadingButton_2, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));

    connect(uiw.disc, SIGNAL(clicked()), this, SLOT(disc()));
    connect(uiw.cylinder, SIGNAL(clicked()), this, SLOT(cylinder()));
    connect(uiw.sphere, SIGNAL(clicked()), this, SLOT(sphere()));
    connect(uiw.capsule, SIGNAL(clicked()), this, SLOT(capsule()));

    connect(uiw.heightField, SIGNAL(clicked()), this, SLOT(heightField()));
    connect(uiw.loadHF, SIGNAL(clicked()), this, SLOT(loadHF()));

    connect(uiw.hf_up, SIGNAL(clicked()), this, SLOT(upHf()));
    connect(uiw.hf_down, SIGNAL(clicked()), this, SLOT(downHf()));
    connect(uiw.hf_distanceSlider, SIGNAL(sliderReleased()), this, SLOT(distanceSlider()));

	// Widget edition
	connect(meshWidget, SIGNAL(_signalEditSceneLeft(const Ray&)), this, SLOT(editingSceneLeft(const Ray&)));
	connect(meshWidget, SIGNAL(_signalEditSceneRight(const Ray&)), this, SLOT(editingSceneRight(const Ray&)));
}

void MainWindow::editingSceneLeft(const Ray&)
{
}

void MainWindow::editingSceneRight(const Ray&)
{
}

void MainWindow::BoxMeshExample()
{
	Mesh boxMesh = Mesh(Box(1.0));

	std::vector<Color> cols;
	cols.resize(boxMesh.Vertexes());
	for (int i = 0; i < cols.size(); i++)
		cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

	meshColor = MeshColor(boxMesh, cols, boxMesh.VertexIndexes());
	UpdateGeometry();
}

void MainWindow::SphereImplicitExample()
{
  AnalyticScalarField implicit;

  Mesh implicitMesh;
  implicit.Polygonize(31, implicitMesh, Box(2.0));

  std::vector<Color> cols;
  cols.resize(implicitMesh.Vertexes());
  for (int i = 0; i < cols.size(); i++)
    cols[i] = Color(0.8, 0.8, 0.8);

  meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
  UpdateGeometry();

}

void MainWindow::UpdateGeometry()
{
	meshWidget->ClearAll();
	meshWidget->AddMesh("BoxMesh", meshColor);

	uiw.lineEdit->setText(QString::number(meshColor.Vertexes()));
	uiw.lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::UpdateMaterial()
{
	meshWidget->UseWireframeGlobal(uiw.wireframe->isChecked());

	if (uiw.radioShadingButton_1->isChecked())
		meshWidget->SetMaterialGlobal(MeshMaterial::Normal);
	else
		meshWidget->SetMaterialGlobal(MeshMaterial::Color);
}

void MainWindow::ResetCamera()
{
	meshWidget->SetCamera(Camera(Vector(-10.0), Vector(0.0)));
}

void MainWindow::disc() {
    Mesh mesh = Mesh(Disc(Vector(0, 0, 0), 3.0, 250));

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::cylinder() {
    Mesh mesh = Mesh(Cylinder(Vector(0, 0, 0), 3.0, 100, 5.0));

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::sphere() {
    Mesh mesh = Mesh(Sphere(Vector(0,0,0), 3.0, 250));

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::capsule() {
    Mesh mesh = Mesh(Capsule(Vector(0,0,0), 3.0, 3.0, 10));

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::heightField() {
    m_hf.mediumExampleField();
    m_hf.setDistance((double)uiw.hf_distanceSlider->value()/100.0);
    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::loadHF() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "../");
    m_hf.loadField(fileName.toStdString());
    m_hf.setDistance((double)uiw.hf_distanceSlider->value()/100.0);

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::upHf() {
    std::cerr << "up hf" << std::endl;
    m_hf.upScale();

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::downHf() {
    std::cerr << "down hf" << std::endl;
    m_hf.downScale();

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::distanceSlider() {
    m_hf.setDistance((double)uiw.hf_distanceSlider->value()/100.0);

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}
