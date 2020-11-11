#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>
// ѕреобразуем входную последовательность символов в кодировку UNICODE
#define RUS( str ) codec->toUnicode(str)
int main(int argc, char *argv[])
{
 QApplication app(argc, argv);
 // ќбеспечиваем перекодировку русских букв из кодировки,
 // в которой написана программа.
 // "Windows-1251" - дл€ Windows, "KOI8-R" - Linux и т.д.
 QTextCodec * codec = QTextCodec::codecForName("Windows-1251");
 // —оздаем главное окно
 QWidget *hbox = new QWidget();
 hbox->setWindowTitle( RUS("¬ведите ¬аш ¬озраст") );
 QSpinBox *spinBox = new QSpinBox( hbox );
 QSlider *slider = new QSlider(Qt::Horizontal, hbox );
 spinBox->setRange(0, 130);
 slider->setRange(0, 130);
 slider->setValue(35);
 spinBox->setValue(35);
 QPushButton * btn = new QPushButton( RUS("«авершение"), hbox );
//***************************************************************************
 QHBoxLayout *layout = new QHBoxLayout; // выравнивание по горизонтали
 //QVBoxLayout *layout = new QVBoxLayout; // выравнивание по вертикали
 layout->setContentsMargins(5,5,5,5); // устанавливаем внешние границы
 layout->setSpacing(5); // устанавливаем интервал элементов внутри
 hbox->setLayout(layout); // св€зываем layout с hbox
 // устанавливаем пор€док следовани€ элементов
 layout->addWidget(spinBox);
 layout->addWidget(slider);
 layout->addWidget(btn);
//***************************************************************************
 // св€зываем сигнал изменени€ spinBox со слотом slider
 QObject::connect(spinBox, SIGNAL(valueChanged(int)),
 slider, SLOT(setValue(int)));
 // св€зываем сигнал изменени€ slider со слотом spinBox
 QObject::connect(slider, SIGNAL(valueChanged(int)),
 spinBox, SLOT(setValue(int)));
 // св€зываем сигнал нажати€ btn со слотом close главного окна
 QObject::connect(btn, SIGNAL(clicked(bool)),
 hbox, SLOT(close()));
 hbox->show(); // отображаем окно
 return app.exec(); // запускаем цикл обработки сообщений
}