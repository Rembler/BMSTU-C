#include <QApplication>
#include "textfunc.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FormDialog *dialog = new FormDialog();
    dialog->show(); // ���������� ����
    return app.exec(); // ��������� ���� ��������� ���������
}
