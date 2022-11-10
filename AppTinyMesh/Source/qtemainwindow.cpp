#include "qte.h"
#include "implicits.h"

#include "heightField.h"

#include <QFileDialog>
#include <QElapsedTimer>

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
    connect(uiw.tore, SIGNAL(clicked()), this, SLOT(tore()));

    connect(uiw.heightField, SIGNAL(clicked()), this, SLOT(heightField()));
    connect(uiw.loadHF, SIGNAL(clicked()), this, SLOT(loadHF()));

    connect(uiw.hf_up, SIGNAL(clicked()), this, SLOT(upHf()));
    connect(uiw.hf_down, SIGNAL(clicked()), this, SLOT(downHf()));
    connect(uiw.hf_distanceSlider, SIGNAL(sliderReleased()), this, SLOT(distanceSlider()));
    connect(uiw.hf_elevation_button, SIGNAL(clicked()), this, SLOT(applyElevation()));

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
    QElapsedTimer   timer;
    timer.start();

    Disc disc(Vector(0, 0, 0), 3.0, 250);

    uiw.stats_precision->setText(QString::number(disc.getPrecision()));
    Mesh mesh = Mesh(disc);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::cylinder() {
    QElapsedTimer   timer;
    timer.start();

    Cylinder cylinder(Vector(0, 0, 0), 3.0, 100, 5.0);

    uiw.stats_precision->setText(QString::number(cylinder.getPrecision()));
    Mesh mesh = Mesh(cylinder);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::sphere() {
    QElapsedTimer   timer;
    timer.start();

    Sphere sphere(Vector(0,0,0), 3.0, 250);

    uiw.stats_precision->setText(QString::number(sphere.getPrecision()));
    Mesh mesh = Mesh(Sphere(Vector(0,0,0), 3.0, 250));

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::capsule() {
    QElapsedTimer   timer;
    timer.start();

    Capsule capsule(Vector(0,0,0), 3.0, 7.0, 100);

    uiw.stats_precision->setText(QString::number(capsule.getPrecision()));
    Mesh mesh = Mesh(capsule);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::tore() {
    QElapsedTimer   timer;
    timer.start();

    Tore tore(Vector(0,0,0), 1.0, 2.0, 10);

    uiw.stats_precision->setText(QString::number(tore.getPrecision()));
    Mesh mesh = Mesh(tore);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::heightField() {
    QElapsedTimer   timer;
    timer.start();

    m_hf.mediumExampleField();
    m_hf.setDistance((double)uiw.hf_distanceSlider->value()/100.0);

    uiw.hf_elevation_x->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getWidth()*m_hf.getDistance()));
    uiw.hf_elevation_y->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getHeight()*m_hf.getDistance()));

    uiw.stats_precision->setText(QString());

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::loadHF() {
    QElapsedTimer   timer;
    timer.start();

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "../");
    m_hf.loadField(fileName.toStdString());
    m_hf.setDistance((double)uiw.hf_distanceSlider->value()/100.0);

    uiw.hf_elevation_x->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getWidth()*m_hf.getDistance()));
    uiw.hf_elevation_y->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getHeight()*m_hf.getDistance()));

    uiw.stats_precision->setText(QString());

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();

    uiw.stats_time->setText(QString::number(timer.elapsed()) + QString::fromUtf8(" ms."));
}

void MainWindow::upHf() {
    std::cerr << "up hf" << std::endl;
    m_hf.upScale();

    uiw.hf_elevation_x->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getWidth()*m_hf.getDistance()));
    uiw.hf_elevation_y->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getHeight()*m_hf.getDistance()));

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

    uiw.hf_elevation_x->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getWidth()*m_hf.getDistance()));
    uiw.hf_elevation_y->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getHeight()*m_hf.getDistance()));

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

    uiw.hf_elevation_x->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getWidth()*m_hf.getDistance()));
    uiw.hf_elevation_y->setPlaceholderText(QString::fromUtf8("0 -> ") + QString::number(m_hf.getHeight()*m_hf.getDistance()));

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::applyElevation() {
    //we display a height field at the moment
    if (m_hf.getWidth()*m_hf.getDistance() < uiw.hf_elevation_x->text().toDouble()
            || uiw.hf_elevation_x->text().toDouble() < 0
            || m_hf.getHeight()*m_hf.getDistance() < uiw.hf_elevation_y->text().toDouble()
            || uiw.hf_elevation_y->text().toDouble() < 0)
        return; //checks the center point is in the field

    if (uiw.hf_elevation_percentage->text().toDouble() < -100
            || uiw.hf_elevation_percentage->text().toDouble() > 100)
        return; //checks the percentage

    m_hf.applyElevation(uiw.hf_elevation_x->text().toDouble(), uiw.hf_elevation_y->text().toDouble(),
                        uiw.hf_elevation_radius->text().toDouble(), uiw.hf_elevation_percentage->text().toDouble());

    Mesh mesh = Mesh(m_hf);

    std::vector<Color> cols;
    cols.resize(mesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(mesh, cols, mesh.VertexIndexes());
    UpdateGeometry();
}
