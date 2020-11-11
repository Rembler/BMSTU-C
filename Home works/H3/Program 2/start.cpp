#include <QApplication>
#include "draw.h"

int main(int argc, char* argv[])
{
        QApplication app(argc, argv);
        Form* dialog = new Form();
        dialog->show();
        return app.exec();
}
