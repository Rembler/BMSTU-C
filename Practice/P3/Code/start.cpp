#include "mainForm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);// создать приложение
    Window win;    // создать Главное окно
    win.show();   // показать на экране Главное окно
    return app.exec(); // запуск цикла обработки сообщений
}
