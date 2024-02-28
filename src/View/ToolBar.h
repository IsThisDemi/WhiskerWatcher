#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QToolButton>
#include <string>

#include "../Utility/Repository/JsonRepository.h"

namespace View
{
    class ToolBar : public QToolBar
    {
        Q_OBJECT
    private:
        QAction *openAction;
        QAction *saveAction;
        QAction *saveAsAction;
    
    signals:
        void openSignal();
        void saveSignal();
        void saveAsSignal();
        void fileOpenedSignal();
        void setIsSavedSignal(const bool& value);
    
    public slots:
        void openSlot();
        void saveSlot();
        void saveAsSlot();

    public:
        ToolBar(QToolBar *parent = nullptr);

        void enableSaveAction();
        void disableSaveAction();
        void enableSaveAsAction();
        void disableSaveAsAction();
        void openJsonFile(Utility::Repository::JsonRepository*& repository);
        void saveJsonFile(const std::vector<Sensor::AbstractSensor*> &sensors, Utility::Repository::JsonRepository*& repository);
        void saveAsJsonFile(const std::vector<Sensor::AbstractSensor*> &sensors, Utility::Repository::JsonRepository* &repository);

        ~ToolBar();
    };
}

#endif