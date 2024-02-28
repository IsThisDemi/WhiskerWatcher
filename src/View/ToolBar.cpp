#include "ToolBar.h"

namespace View {
    ToolBar::ToolBar(QToolBar *parent) : QToolBar(parent)
    {
        //Definizione delle azioni della toolbar
        openAction = new QAction(
            QIcon(QPixmap((":/Assets/Icons/open.png"))),
            tr("Open"), this);

        saveAction = new QAction(
            QIcon(QPixmap((":/Assets/Icons/save.png"))),
            tr("Save"), this);

        saveAsAction = new QAction(
            QIcon(QPixmap((":/Assets/Icons/save-as.png"))),
            tr("Save as"), this);

        //Aggiunta delle azioni alla toolbar
        addAction(openAction);
        addAction(saveAction);
        addAction(saveAsAction);

        //Collenamento delle azioni alle shortcut
        openAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
        saveAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
        saveAsAction->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));

        //Di default all'inizio non si può salvare
        saveAction->setEnabled(false);
        saveAsAction->setEnabled(false);

        //Collegamento delle azioni ai rispettivi slot
        connect(openAction, &QAction::triggered, this, &ToolBar::openSlot);
        connect(saveAction, &QAction::triggered, this, &ToolBar::saveSlot);
        connect(saveAsAction, &QAction::triggered, this, &ToolBar::saveAsSlot);
    }

    void ToolBar::openSlot()
    {
        emit openSignal();
    }

    void ToolBar::saveSlot()
    {
        emit saveSignal();
    }

    void ToolBar::saveAsSlot()
    {
        emit saveAsSignal();
    }

    void ToolBar::enableSaveAction()
    {
        saveAction->setEnabled(true);
    }

    void ToolBar::disableSaveAction()
    {
        saveAction->setEnabled(false);
    }

    void ToolBar::enableSaveAsAction()
    {
        saveAsAction->setEnabled(true);
    }

    void ToolBar::disableSaveAsAction()
    {
        saveAsAction->setEnabled(false);
    }

    void ToolBar::openJsonFile(Utility::Repository::JsonRepository*& repository)
    {
        QString defaultFolder = QDir::currentPath();
        QFileDialog dialog(this);
        dialog.setDirectory(defaultFolder);
        QString fileName = dialog.getOpenFileName(this, "Open JSON file", defaultFolder, "JSON Files (*.json)");
        if (!fileName.isEmpty()){
            delete repository;
            repository = new Utility::Repository::JsonRepository(Utility::Repository::JsonRepository::fromPath(fileName.toStdString()));
            repository->load();
            emit fileOpenedSignal();
        }
    }

    void ToolBar::saveJsonFile(const std::vector<Sensor::AbstractSensor*> &sensors, Utility::Repository::JsonRepository*& repository)
    {
        if(repository == nullptr){
            saveAsJsonFile(sensors, repository);
        } else {
            repository->overwrite(sensors);
            repository->store();
            emit setIsSavedSignal(true);
        
        }
    }

    void ToolBar::saveAsJsonFile(const std::vector<Sensor::AbstractSensor*> &sensors, Utility::Repository::JsonRepository*& repository)
    {
        QString defaultFolder = QDir::currentPath();
        QFileDialog dialog(this);
        dialog.setDirectory(defaultFolder);

        QString fileName = dialog.getSaveFileName(this, "Save JSON file", defaultFolder, "JSON Files (*.json)");

        if (!fileName.isEmpty()){
            if (!fileName.endsWith(".json", Qt::CaseSensitive))
            {
                fileName += ".json";
            }

            if (repository == nullptr)
                repository = new Utility::Repository::JsonRepository(Utility::Repository::JsonRepository::fromPath(fileName.toStdString()));
            else
                repository->setPath(fileName.toStdString());
            
            repository->overwrite(sensors);
            repository->store();

            emit setIsSavedSignal(true);
        }
    }

    ToolBar::~ToolBar()
    {
        delete openAction;
        delete saveAction;
        delete saveAsAction;
    }
}