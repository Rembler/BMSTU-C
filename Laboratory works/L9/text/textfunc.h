#ifndef BACK_H_
#define BACK_H_
#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>
#include <QTextEdit>
#include <QString>
/// �����, ����������� ��������
class FormDialog: public QDialog
{
    Q_OBJECT
public:
    FormDialog( QWidget * parent = 0);
    virtual ~FormDialog(){};

protected:    
    QLineEdit *lineEdit1;
    QTextEdit *field1;
    bool lower, isOut;

    
private slots:
    void swapper();
    void newQs();
};
#endif