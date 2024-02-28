#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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
