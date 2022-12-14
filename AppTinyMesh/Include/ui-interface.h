/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2D_INTERFACE_H
#define UI_2D_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Assets
{
public:
    QAction *actionExit;
    QAction *actionNew_Scene;
    QAction *actionExport_obj;
    QAction *actionExport_ma;
    QAction *actionLoad_ma;
    QAction *actionGL;
    QAction *actionVectorized;
    QAction *actionExport_svg;
    QAction *actionSphere_Tracing_png;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *Objects_groupBox;
    QPushButton *boxMesh;
    QPushButton *resetcameraButton;
    QPushButton *sphereImplicit;

    QPushButton *disc;
    QPushButton *cylinder;
    QPushButton *sphere;
    QPushButton *capsule;
    QPushButton *tore;
    QPushButton *heightField;
    QPushButton *loadHF;

    QWidget *widget_GL;
    QGroupBox *Parameters_groupBox;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_13;
    QRadioButton *radioShadingButton_1;
    QCheckBox *wireframe;
    QRadioButton *radioShadingButton_2;
    QMenuBar *menubar;
    QMenu *menuFile;

    QGroupBox   *gb_hf;
    QPushButton *hf_up;
    QPushButton *hf_down;
    QLabel      *hf_distanceLabel;
    QSlider     *hf_distanceSlider;
    QGroupBox   *hf_gb_elevation;
    QLabel      *hf_elevation_x_label;
    QLabel      *hf_elevation_y_label;
    QLineEdit   *hf_elevation_x;
    QLineEdit   *hf_elevation_y;
    QLabel      *hf_elevation_radius_label;
    QLineEdit   *hf_elevation_radius;
    QLabel      *hf_elevation_percentage_label;
    QLineEdit   *hf_elevation_percentage;
    QPushButton *hf_elevation_button;

    QGroupBox   *gb_stats;
    QLabel      *stats_precision_label;
    QLineEdit   *stats_precision;
    QLabel      *stats_time_label;
    QLineEdit   *stats_time;

    void setupUi(QMainWindow *Assets)
    {
        if (Assets->objectName().isEmpty())
            Assets->setObjectName(QString::fromUtf8("Assets"));
        Assets->resize(1200, 1000);
        Assets->setMinimumSize(QSize(420, 300));
        actionExit = new QAction(Assets);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew_Scene = new QAction(Assets);
        actionNew_Scene->setObjectName(QString::fromUtf8("actionNew_Scene"));
        actionExport_obj = new QAction(Assets);
        actionExport_obj->setObjectName(QString::fromUtf8("actionExport_obj"));
        actionExport_ma = new QAction(Assets);
        actionExport_ma->setObjectName(QString::fromUtf8("actionExport_ma"));
        actionLoad_ma = new QAction(Assets);
        actionLoad_ma->setObjectName(QString::fromUtf8("actionLoad_ma"));
        actionGL = new QAction(Assets);
        actionGL->setObjectName(QString::fromUtf8("actionGL"));
        actionVectorized = new QAction(Assets);
        actionVectorized->setObjectName(QString::fromUtf8("actionVectorized"));
        actionExport_svg = new QAction(Assets);
        actionExport_svg->setObjectName(QString::fromUtf8("actionExport_svg"));
        actionSphere_Tracing_png = new QAction(Assets);
        actionSphere_Tracing_png->setObjectName(QString::fromUtf8("actionSphere_Tracing_png"));
        centralwidget = new QWidget(Assets);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        Objects_groupBox = new QGroupBox(centralwidget);
        Objects_groupBox->setObjectName(QString::fromUtf8("Objects_groupBox"));
        Objects_groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Objects_groupBox->sizePolicy().hasHeightForWidth());
        Objects_groupBox->setSizePolicy(sizePolicy);
        Objects_groupBox->setMinimumSize(QSize(350, 250));
        boxMesh = new QPushButton(Objects_groupBox);
        boxMesh->setObjectName(QString::fromUtf8("boxMesh"));
        boxMesh->setGeometry(QRect(20, 20, 101, 23));
        boxMesh->setCheckable(false);
        resetcameraButton = new QPushButton(Objects_groupBox);
        resetcameraButton->setObjectName(QString::fromUtf8("resetcameraButton"));
        resetcameraButton->setGeometry(QRect(140, 20, 81, 23));
        resetcameraButton->setCheckable(true);
        resetcameraButton->setAutoDefault(false);
        resetcameraButton->setFlat(false);
        sphereImplicit = new QPushButton(Objects_groupBox);
        sphereImplicit->setObjectName(QString::fromUtf8("sphereImplicit"));
        sphereImplicit->setGeometry(QRect(20, 50, 101, 23));
        sphereImplicit->setCheckable(false);

        disc = new QPushButton(Objects_groupBox);
        disc->setObjectName(QString::fromUtf8("sphere"));
        disc->setGeometry(QRect(140, 50, 81, 23));
        disc->setCheckable(false);
        cylinder = new QPushButton(Objects_groupBox);
        cylinder->setObjectName(QString::fromUtf8("cylinder"));
        cylinder->setGeometry(QRect(20, 80, 101, 23));
        cylinder->setCheckable(false);
        sphere = new QPushButton(Objects_groupBox);
        sphere->setObjectName(QString::fromUtf8("cylinder"));
        sphere->setGeometry(QRect(140, 80, 81, 23));
        sphere->setCheckable(false);
        capsule = new QPushButton(Objects_groupBox);
        capsule->setObjectName(QString::fromUtf8("capsule"));
        capsule->setGeometry(QRect(20, 110, 101, 23));
        capsule->setCheckable(false);
        tore = new QPushButton(Objects_groupBox);
        tore->setObjectName(QString::fromUtf8("tore"));
        tore->setGeometry(QRect(140, 110, 81, 23));
        tore->setCheckable(false);
        heightField = new QPushButton(Objects_groupBox);
        heightField->setObjectName(QString::fromUtf8("heightField"));
        heightField->setGeometry(QRect(20, 140, 101, 23));
        heightField->setCheckable(false);
        loadHF = new QPushButton(Objects_groupBox);
        loadHF->setObjectName(QString::fromUtf8("load hf"));
        loadHF->setGeometry(QRect(140, 140, 81, 23));
        loadHF->setCheckable(false);

        hboxLayout->addWidget(Objects_groupBox);

        widget_GL = new QWidget(centralwidget);
        widget_GL->setObjectName(QString::fromUtf8("widget_GL"));

        hboxLayout->addWidget(widget_GL);

        Parameters_groupBox = new QGroupBox(centralwidget);
        Parameters_groupBox->setObjectName(QString::fromUtf8("Parameters_groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Parameters_groupBox->sizePolicy().hasHeightForWidth());
        Parameters_groupBox->setSizePolicy(sizePolicy1);
        Parameters_groupBox->setMinimumSize(QSize(450, 141));
        groupBox_4 = new QGroupBox(Parameters_groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 171, 121));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 61, 21));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 50, 81, 20));
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 61, 21));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 20, 81, 20));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_13 = new QGroupBox(Parameters_groupBox);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(190, 20, 251, 121));
        radioShadingButton_1 = new QRadioButton(groupBox_13);
        radioShadingButton_1->setObjectName(QString::fromUtf8("radioShadingButton_1"));
        radioShadingButton_1->setGeometry(QRect(20, 20, 61, 20));
        radioShadingButton_1->setChecked(true);
        wireframe = new QCheckBox(groupBox_13);
        wireframe->setObjectName(QString::fromUtf8("wireframe"));
        wireframe->setGeometry(QRect(90, 20, 81, 17));
        wireframe->setChecked(true);
        radioShadingButton_2 = new QRadioButton(groupBox_13);
        radioShadingButton_2->setObjectName(QString::fromUtf8("radioShadingButton_2"));
        radioShadingButton_2->setGeometry(QRect(20, 50, 61, 20));
        radioShadingButton_2->setChecked(false);

        gb_hf = new QGroupBox(Parameters_groupBox);
        gb_hf->setObjectName(QString::fromUtf8("gb_hf"));
        gb_hf->setGeometry(QRect(10, 150, 430, 370));
        hf_up = new QPushButton(gb_hf);
        hf_up->setObjectName(QString::fromUtf8("upButton"));
        hf_up->setGeometry(QRect(10, 20, 200, 30));
        hf_up->setChecked(false);
        hf_down = new QPushButton(gb_hf);
        hf_down->setObjectName(QString::fromUtf8("downButton"));
        hf_down->setGeometry(QRect(220, 20, 200, 30));
        hf_down->setChecked(false);
        hf_distanceLabel = new QLabel(gb_hf);
        hf_distanceLabel->setObjectName(QString::fromUtf8("distanceLabel"));
        hf_distanceLabel->setGeometry(QRect(10, 60, 100, 30));
        hf_distanceSlider = new QSlider(gb_hf);
        hf_distanceSlider->setObjectName(QString::fromUtf8("distanceSlider"));
        hf_distanceSlider->setGeometry(QRect(120, 60, 300, 30));
        hf_distanceSlider->setOrientation(Qt::Orientation::Horizontal);
        hf_distanceSlider->setMinimum(1);
        hf_distanceSlider->setMaximum(1000);
        hf_distanceSlider->setSingleStep(1);
        hf_distanceSlider->setValue(50);

        hf_gb_elevation = new QGroupBox(gb_hf);
        hf_gb_elevation->setObjectName(QString::fromUtf8("hfElevationGb"));
        hf_gb_elevation->setGeometry(10, 100, 420, 260);
        hf_elevation_x_label = new QLabel(hf_gb_elevation);
        hf_elevation_x_label->setObjectName(QString::fromUtf8("xlabel"));
        hf_elevation_x_label->setGeometry(10, 20, 60, 30);
        hf_elevation_x = new QLineEdit(hf_gb_elevation);
        hf_elevation_x->setObjectName(QString::fromUtf8("xValue"));
        hf_elevation_x->setGeometry(75, 20, 130, 30);
        hf_elevation_y_label = new QLabel(hf_gb_elevation);
        hf_elevation_y_label->setObjectName(QString::fromUtf8("xlabel"));
        hf_elevation_y_label->setGeometry(215, 20, 60, 30);
        hf_elevation_y = new QLineEdit(hf_gb_elevation);
        hf_elevation_y->setObjectName(QString::fromUtf8("xValue"));
        hf_elevation_y->setGeometry(280, 20, 130, 30);
        hf_elevation_radius_label = new QLabel(hf_gb_elevation);
        hf_elevation_radius_label->setObjectName(QString::fromUtf8("radiusLabel"));
        hf_elevation_radius_label->setGeometry(10, 60, 400, 30);
        hf_elevation_radius = new QLineEdit(hf_gb_elevation);
        hf_elevation_radius->setObjectName(QString::fromUtf8("radiusValue"));
        hf_elevation_radius->setGeometry(10, 100, 400, 30);
        hf_elevation_percentage_label = new QLabel(hf_gb_elevation);
        hf_elevation_percentage_label->setObjectName(QString::fromUtf8("percentageLabel"));
        hf_elevation_percentage_label->setGeometry(10, 140, 400, 30);
        hf_elevation_percentage = new QLineEdit(hf_gb_elevation);
        hf_elevation_percentage->setObjectName(QString::fromUtf8("percentageValue"));
        hf_elevation_percentage->setGeometry(10, 180, 400, 30);
        hf_elevation_percentage->setPlaceholderText(QString::fromUtf8("-100% -> +100%"));
        hf_elevation_button = new QPushButton(hf_gb_elevation);
        hf_elevation_button->setObjectName(QString::fromUtf8("elevationButton"));
        hf_elevation_button->setGeometry(QRect(10, 220, 400, 30));
        hf_elevation_button->setChecked(false);

        gb_stats = new QGroupBox(Parameters_groupBox);
        gb_stats->setObjectName(QString::fromUtf8("gb_stats"));
        gb_stats->setGeometry(QRect(10, 530, 430, 100));
        stats_precision_label = new QLabel(gb_stats);
        stats_precision_label->setObjectName(QString::fromUtf8("statsPrecisionLabel"));
        stats_precision_label->setGeometry(10, 20, 200, 30);
        stats_precision = new QLineEdit(gb_stats);
        stats_precision->setObjectName(QString::fromUtf8("statsPrecisionValue"));
        stats_precision->setGeometry(220, 20, 200, 30);
        stats_time_label = new QLabel(gb_stats);
        stats_time_label->setObjectName(QString::fromUtf8("statsTimeLabel"));
        stats_time_label->setGeometry(10, 60, 200, 30);
        stats_time = new QLineEdit(gb_stats);
        stats_time->setObjectName(QString::fromUtf8("statsTimeValue"));
        stats_time->setGeometry(220, 60, 200, 30);

        hboxLayout->addWidget(Parameters_groupBox);

        Assets->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Assets);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Assets->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(Assets);

        resetcameraButton->setDefault(false);


        QMetaObject::connectSlotsByName(Assets);
    } // setupUi

    void retranslateUi(QMainWindow *Assets)
    {
        Assets->setWindowTitle(QCoreApplication::translate("Assets", "Implicit heightField", nullptr));
        actionExit->setText(QCoreApplication::translate("Assets", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Assets", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Scene->setText(QCoreApplication::translate("Assets", "New Scene", nullptr));
        actionExport_obj->setText(QCoreApplication::translate("Assets", "OBJ File (.obj)", nullptr));
        actionExport_ma->setText(QCoreApplication::translate("Assets", "Maya File (.ma)", nullptr));
        actionLoad_ma->setText(QCoreApplication::translate("Assets", "Load", nullptr));
        actionGL->setText(QCoreApplication::translate("Assets", "GL", nullptr));
        actionVectorized->setText(QCoreApplication::translate("Assets", "Vectorized", nullptr));
        actionExport_svg->setText(QCoreApplication::translate("Assets", "SVG File (.svg)", nullptr));
        actionSphere_Tracing_png->setText(QCoreApplication::translate("Assets", "Sphere Tracing (.png)", nullptr));
        Objects_groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        boxMesh->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        boxMesh->setText(QCoreApplication::translate("Assets", "Box Mesh", nullptr));
#if QT_CONFIG(tooltip)
        resetcameraButton->setToolTip(QCoreApplication::translate("Assets", "<html><head/><body><p><span style=\" color:#5500ff;\">Callback #03</span></p><p><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bird</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        resetcameraButton->setText(QCoreApplication::translate("Assets", "Reset Camera", nullptr));
#if QT_CONFIG(tooltip)
        sphereImplicit->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sphereImplicit->setText(QCoreApplication::translate("Assets", "Sphere Implicit", nullptr));

        disc->setText(QCoreApplication::translate("Assets", "Disc", nullptr));
        cylinder->setText(QCoreApplication::translate("Assets", "Cylinder", nullptr));
        sphere->setText(QCoreApplication::translate("Assets", "Sphere", nullptr));
        capsule->setText(QCoreApplication::translate("Assets", "Capsule", nullptr));
        tore->setText(QCoreApplication::translate("Assets", "Tore", nullptr));
        heightField->setText(QCoreApplication::translate("Assets", "HeightField", nullptr));
        loadHF->setText(QCoreApplication::translate("Assets", "Load HeightField", nullptr));

        Parameters_groupBox->setTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("Assets", " Statistics", nullptr));
        label_2->setText(QCoreApplication::translate("Assets", "Vertex", nullptr));
        label_3->setText(QCoreApplication::translate("Assets", "Triangles", nullptr));
        lineEdit->setText(QString());
        groupBox_13->setTitle(QCoreApplication::translate("Assets", "Shading", nullptr));
        radioShadingButton_1->setText(QCoreApplication::translate("Assets", "Normal", nullptr));
        wireframe->setText(QCoreApplication::translate("Assets", "Wireframe", nullptr));
        radioShadingButton_2->setText(QCoreApplication::translate("Assets", "Color", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Assets", "File", nullptr));

        gb_hf->setTitle(QCoreApplication::translate("Assets", "Height Field manipulations", nullptr));
        hf_up->setText(QCoreApplication::translate("Assets", "Up elevation", nullptr));
        hf_down->setText(QCoreApplication::translate("Assets", "Down elevation", nullptr));
        hf_distanceLabel->setText(QCoreApplication::translate("Assets", "Distance label", nullptr));

        hf_gb_elevation->setTitle(QCoreApplication::translate("Assets", "Height Field elevation", nullptr));
        hf_elevation_x_label->setText(QCoreApplication::translate("Assets", "x position", nullptr));
        hf_elevation_x->setText(QString());
        hf_elevation_y_label->setText(QCoreApplication::translate("Assets", "y position", nullptr));
        hf_elevation_y->setText(QString());
        hf_elevation_radius_label->setText(QCoreApplication::translate("Assets", "Radius to affect", nullptr));
        hf_elevation_radius->setText(QString());
        hf_elevation_percentage_label->setText(QCoreApplication::translate("Assets", "Percentage of elevation", nullptr));
        hf_elevation_percentage->setText(QString());
        hf_elevation_button->setText(QCoreApplication::translate("Assets", "Apply", nullptr));

        gb_stats->setTitle(QCoreApplication::translate("Assets", "Mesh stats", nullptr));
        stats_precision_label->setText(QCoreApplication::translate("Assets", "Precision of the mesh: ", nullptr));
        stats_precision->setText(QString());
        stats_time_label->setText(QCoreApplication::translate("Assets", "Generation time: ", nullptr));
        stats_time->setText(QString());

    } // retranslateUi

};

namespace Ui {
    class Assets: public Ui_Assets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2D_INTERFACE_H
