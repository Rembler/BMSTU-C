#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>
// ����������� ������� ������������������ �������� � ��������� UNICODE
#define RUS( str ) codec->toUnicode(str)
int main(int argc, char *argv[])
{
 QApplication app(argc, argv);
 // ������������ ������������� ������� ���� �� ���������,
 // � ������� �������� ���������.
 // "Windows-1251" - ��� Windows, "KOI8-R" - Linux � �.�.
 QTextCodec * codec = QTextCodec::codecForName("Windows-1251");
 // ������� ������� ����
 QWidget *hbox = new QWidget();
 hbox->setWindowTitle( RUS("������� ��� �������") );
 QSpinBox *spinBox = new QSpinBox( hbox );
 QSlider *slider = new QSlider(Qt::Horizontal, hbox );
 spinBox->setRange(0, 130);
 slider->setRange(0, 130);
 slider->setValue(35);
 spinBox->setValue(35);
 QPushButton * btn = new QPushButton( RUS("����������"), hbox );
//***************************************************************************
 QHBoxLayout *layout = new QHBoxLayout; // ������������ �� �����������
 //QVBoxLayout *layout = new QVBoxLayout; // ������������ �� ���������
 layout->setContentsMargins(5,5,5,5); // ������������� ������� �������
 layout->setSpacing(5); // ������������� �������� ��������� ������
 hbox->setLayout(layout); // ��������� layout � hbox
 // ������������� ������� ���������� ���������
 layout->addWidget(spinBox);
 layout->addWidget(slider);
 layout->addWidget(btn);
//***************************************************************************
 // ��������� ������ ��������� spinBox �� ������ slider
 QObject::connect(spinBox, SIGNAL(valueChanged(int)),
 slider, SLOT(setValue(int)));
 // ��������� ������ ��������� slider �� ������ spinBox
 QObject::connect(slider, SIGNAL(valueChanged(int)),
 spinBox, SLOT(setValue(int)));
 // ��������� ������ ������� btn �� ������ close �������� ����
 QObject::connect(btn, SIGNAL(clicked(bool)),
 hbox, SLOT(close()));
 hbox->show(); // ���������� ����
 return app.exec(); // ��������� ���� ��������� ���������
}