#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>

#include "View/MainWindow.h"
#include "Engine/Memory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":Assets/appIcon.png"));

    QFile stylesheet(":/Assets/style.qss");
    stylesheet.open(QFile::ReadOnly);
    a.setStyleSheet(stylesheet.readAll());

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "WhiskerWatcher_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Engine::Memory library;
    View::MainWindow w(library);
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
