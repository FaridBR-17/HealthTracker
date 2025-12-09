#include <QApplication>
#include "LoginWindow.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager::instance().createTables();

    LoginWindow w;
    w.show();

    return a.exec();
}
