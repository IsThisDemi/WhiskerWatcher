#include "MainWindow.h"
// #include "ui_mainwindow.h"

namespace View {

    MainWindow::MainWindow(Engine::IEngine &ricerca, QWidget *parent)
        : QMainWindow(parent), ricerca(ricerca)
    {
        
    }

    MainWindow::~MainWindow()
    {

    }

}
