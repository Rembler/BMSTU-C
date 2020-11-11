#include <QVector>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cmath>
#include "calcDialog.h"
// �������������� ������
// ��� �������� ������ ������������� �������� ��������������� �����
#define DIV 10
#define MUL 11
#define MINUS 12
#define PLUS 13
#define INVERSE 15
#define DOT 16
#define EQ 20
#define BKSP 30
#define CLR 31
#define CLR_ALL 32

#define LOGX 61
#define EXPY 62
#define SINX 63
#define COSX 64

// ���������� ������ � ������, ������������ � ���� �����
#define GRID_KEYS 16
/// ��������� ������
struct BtnDescr{
 QString text; ///< ������������ �� ������ �����
 int id; ///< ������������� ������
 BtnDescr() { id=0;}; ///< ����������� �� ���������
 ///< ����������� ��� �������������
 BtnDescr( const QString & str, int i)
 { text = str; id = i; };
};
/// ������������ ������-������ ��������� ���������� ������
QVector<BtnDescr> _btnDescr;
/// ������������� ������� _btnDescr ����� ������������� ��������
void InitBtnDescrArray()
{
    _btnDescr.push_back( BtnDescr("7", 7) );
    _btnDescr.push_back( BtnDescr("8", 8) );
    _btnDescr.push_back( BtnDescr("9", 9) );
    _btnDescr.push_back( BtnDescr("/", DIV) );
    _btnDescr.push_back( BtnDescr("4", 4) );
    _btnDescr.push_back( BtnDescr("5", 5) );
    _btnDescr.push_back( BtnDescr("6", 6) );
    _btnDescr.push_back( BtnDescr("*", MUL) );
    _btnDescr.push_back( BtnDescr("1", 1) );
    _btnDescr.push_back( BtnDescr("2", 2) );
    _btnDescr.push_back( BtnDescr("3", 3) );
    _btnDescr.push_back( BtnDescr("-", MINUS) );
    _btnDescr.push_back( BtnDescr("0", 0) );
    _btnDescr.push_back( BtnDescr("-/+", INVERSE) );
    _btnDescr.push_back( BtnDescr(".", DOT) );
    _btnDescr.push_back( BtnDescr("+", PLUS) );

    _btnDescr.push_back( BtnDescr("<-",BKSP) );
    _btnDescr.push_back( BtnDescr("CE",CLR) );
    _btnDescr.push_back( BtnDescr("C", CLR_ALL) );

    _btnDescr.push_back( BtnDescr("log[y]x", LOGX) );
    _btnDescr.push_back( BtnDescr("x^y", EXPY) );
    _btnDescr.push_back( BtnDescr("sin(x)", SINX) );
    _btnDescr.push_back( BtnDescr("cos(x)", SINX) );

    _btnDescr.push_back( BtnDescr("=", EQ) );
}
/// ����������� ������ ������������
CalcDialog::CalcDialog( QWidget * parent)
{
 initNum(); // �������������� ������� ����������
 InitBtnDescrArray(); // �������������� ������ � ��������� ������
 // ������� �����
 m_pLineEdit = new QLineEdit(this);
 // ������������� ����� ������ ������ - ��������� ���� ������
 // � ������������ ������
 m_pLineEdit->setReadOnly ( true );
 m_pSignalMapper = new QSignalMapper(this);
 // ������� ����� ������������
 QVBoxLayout *extraLayout = new QVBoxLayout();
 QGridLayout *gridLayout = new QGridLayout();
 QHBoxLayout *bccKeysLayout = new QHBoxLayout();
 QHBoxLayout *mainKeysLayout = new QHBoxLayout();
 QVBoxLayout *dlgLayout = new QVBoxLayout();

 // ��������� ����� �������� �� _btnDescr
 for (int i = 0; i < _btnDescr.size(); i++) {
 // ������� ������ � ������� �� ���������� ���������
    QPushButton *button = new QPushButton(_btnDescr[i].text);
 // ���� ������ � �������� ����� �������� ��� "=" -
 // ��������� ��������� ���� ��������
    if( i >= GRID_KEYS + 3 || i < GRID_KEYS)
        button->setSizePolicy ( QSizePolicy::Expanding,
            QSizePolicy::Expanding);
 // ���� ������ �� �������� - ����������� ����� ������� �� 4 ������
    if( _btnDescr[i].id >= 10 ){
        QFont fnt = button->font();
        fnt.setPointSize( fnt.pointSize () + 4 );
        button->setFont( fnt );
    }
 // ��������� ������ ������� ������ � �������� m_pSignalMapper
    connect(button, SIGNAL(clicked()), m_pSignalMapper, SLOT(map()));
 // ������������ ������������ ������ � ��������������
    m_pSignalMapper->setMapping(button, _btnDescr[i].id);
 if(i<GRID_KEYS) // ���� ������ �� ������������ ����� - �������� � �����
    gridLayout->addWidget(button, i / 4, i % 4);
 else if( i < GRID_KEYS + 3) // ������ �� �������� ����� - � bccKeysLayout
    bccKeysLayout->addWidget(button);
 else if( i < GRID_KEYS + 3 + 4) // my buttons
    extraLayout->addWidget(button);
 else
 {
 // ������ "=" - �������� � ���� mainKeysLayout ����� gridLayout
mainKeysLayout->addLayout(extraLayout);
mainKeysLayout->addLayout(gridLayout);
mainKeysLayout->addWidget(button);
}
}
 // ��������� ������ �� m_pSignalMapper � ������� �� ������ clicked
 // ������ ������
connect(m_pSignalMapper, SIGNAL(mapped(int)),
    this, SLOT(clicked(int)));
 // ��������� ����� ������ � ����� ������������ ���� �����
dlgLayout->addWidget(m_pLineEdit);
dlgLayout->addLayout(bccKeysLayout);
dlgLayout->addLayout(mainKeysLayout);
 // ��������� ����� ������������ dlgLayout � ������
setLayout(dlgLayout);
// ���������� "0" � ���� ����� ����� m_pLineEdit
setNumEdit( 0 );
};
// ��������� ������� ������
void CalcDialog::clicked(int id)
{ // �� �������������� ������ ���� �������� ��� ����������
    switch(id)
    {
case SINX:
{
  setNumEdit(sin(getNumEdit()));
  break;
};
case COSX:
{
  setNumEdit(cos(getNumEdit()));
  break;
};
case INVERSE: // ������� �������� +/-
{
    setNumEdit( getNumEdit() * -1.0 ); break;
};
case DOT: // ���������� ���������� �����
{
 // ���� �� ������ ��������� ���������� �������� - ��������
 checkOpPerf();
 QString str = m_pLineEdit->text ();
 str.append( "." ); // ��������� ����� � ������
 bool ok = false;
 // ���������, �������� �� ��������� ������ (��������� 0.1. )
 str.toDouble(&ok);
 // ���� ������ �������� ������ - �������� �������� � m_pLineEdit
 if( ok ) m_pLineEdit->setText ( str );
 break;
};
case DIV: // �������� �������������� ��������
case MUL:
case PLUS:
case MINUS:
case LOGX:
case EXPY:
case EQ:{
    calcPrevOp( id );
    break;
}
case CLR_ALL: initNum();// ������� ��
case CLR:{
 setNumEdit( 0 ); // �������� � m_pLineEdit ����� 0
 break;
}
case BKSP:{ // ������� ��������� ������
 // ���� �� ������ ���������� ���������� �������� - ��������
    checkOpPerf();
    QString str = m_pLineEdit->text ();
    if( str.length() ){
 // ���� ������ � m_pLineEdit �� ������� - ������� ������
        str.remove( str.length()-1, 1 );
        m_pLineEdit->setText ( str );
    }
    break;
}
default:{ // ��������� �������� ������
 // ���� �� ������ ��������� ���������� �������� - ��������
    checkOpPerf();
    QString sId;
 // ������������ ������ �� �������������� ������� �������
    sId.setNum( id );
    QString str = m_pLineEdit->text ();
    if( str == "0" )
 str = sId; // �������� ���������� ����
else
 str.append( sId ); // �������� � m_pLineEdit ������� �����
m_pLineEdit->setText ( str );
}
};
};
// �������� ����� �� m_pLineEdit
double CalcDialog::getNumEdit()
{
    double result;
    QString str = m_pLineEdit->text ();
 result = str.toDouble(); // ������������� ������ � �����
 return result;
};
// �������� ����� � m_pLineEdit
void CalcDialog::setNumEdit( double num )
{
    QString str;
 str.setNum ( num, 'g', 25 ); // ������������� ������������ ����� � ������
 m_pLineEdit->setText ( str );
};
// ��������� ���������� �������� ��������
void CalcDialog::calcPrevOp( int curOp )
{
 // �������� ����� �� ������
 // m_Val ������ �����, ��������� �� ������� ������ ��������
    double num = getNumEdit();
    switch( m_Op )
    {
        case DIV:{
            if ( num != 0) m_Val /= num;
            else m_Val = 0;
            break;
        }
        case MUL:{
            m_Val *= num;
            break;
        }
        case PLUS:{
            m_Val += num;
            break;
        }
        case MINUS:{
            m_Val -= num;
            break;
        }
        case LOGX:{
            m_Val = log(m_Val) / log(num);
            break;
        }
        case EXPY:{
            m_Val = pow(m_Val, num);
            break;
        }
 case EQ: { // ���� ���� ������ ������ "=" - �� ������ ������
 m_Val = num;
 break; }
}
 m_Op = curOp; // ��������� ��������� ������� ��������
 setNumEdit( m_Val ); // ���������� ���������
 m_bPerf = true; // ��������� ���� ���������� ��������
};
void CalcDialog::checkOpPerf()
{
    if( m_bPerf ){
 // ���� ���-�� ����������� - �������� m_pLineEdit
        m_pLineEdit->clear();
        m_bPerf = false;
    };
};
void CalcDialog::initNum()
{
    m_bPerf = false; m_Val = 0; m_Op = EQ;
};
