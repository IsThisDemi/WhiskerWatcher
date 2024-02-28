#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QtCharts>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <vector>

#include "Utility/Repository/JsonRepository.h"
#include "Engine/IEngine.h"
#include "Engine/Query.h"
#include "ToolBar.h"
namespace View
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        private:
            bool has_unsaved_changes;
            QAction *create_item;

            QWidget *centralWidget;
            QVBoxLayout *mainLayout;
            QHBoxLayout *centralLayout;
            QVBoxLayout *chartLayout;

            // QToolBar *toolbar;
            ToolBar *toolBar;
            Engine::IEngine &ricerca;
            Utility::Repository::JsonRepository *repo;
            // ResultWidget*
            //
            //
            //
        public:
            MainWindow(Engine::IEngine& ricerca, QWidget *parent = nullptr);
            ~MainWindow();
    };
}
#endif // MAINWINDOW_H
