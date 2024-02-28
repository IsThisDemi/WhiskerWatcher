#include "MainWindow.h"
// #include "ui_mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QSplitter>
#include <QFileDialog>
#include <QStackedWidget>
#include <QScrollArea>

namespace View {

    MainWindow::MainWindow(Engine::IEngine &ricerca, QWidget *parent)
        : QMainWindow(parent), toolBar(nullptr), ricerca(ricerca)
    {
        setWindowTitle("WhiskerWatcher");

        //QT actions
        QAction *open = new QAction(
            QIcon(QPixmap((":/Assets/Icons/open.png"))),
            "Open");
        open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

        QAction *save = new QAction(
            QIcon(QPixmap((":/Assets/Icons/save.png"))),
            "Save");
        save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

        QAction *saveAs = new QAction(
            QIcon(QPixmap((":/Assets/Icons/save-as.png"))),
            "Save as");
        saveAs->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));

        QAction *add_sensor = new QAction(
            QIcon(QPixmap((":/Assets/Icons/add.png"))),
            "Add sensor");
        add_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

        //QT Menus
        QMenu *file = menuBar()->addMenu("&File");
        file->addAction(open);
        file->addAction(save);
        file->addAction(saveAs);

        QMenu *sensor_menu = menuBar()->addMenu("&Sensors");
        sensor_menu->addAction(add_sensor);

        // //QT ToolBar
        // toolbar = addToolBar("File Toolbar");
        // toolbar->setAllowedAreas(Qt::BottomToolBarArea);
        // toolbar->setObjectName("Toolbar");
        // toolbar->addAction(add_sensor);

        toolBar = new ToolBar();

        toolBar->setFixedSize(1024,30);
    }

    MainWindow::~MainWindow()
    {

    }

}
