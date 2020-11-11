#include "tableFile.h"
#include "mainForm.h"

tableFile::tableFile()
{
    f = new QFile ("table.txt");
    f -> open(QFile::ReadWrite);
}

tableFile::~tableFile()
{
    f -> close();
    delete f;
}

void tableFile::addElem(elem a)
{
    f -> seek(f -> size());
    QDataStream out(f);
    out << a.number << a.name << a.weight << a.conduct;
}

bool tableFile::readElem()
{
    QDataStream in(f);
    if (in.atEnd())
        return false;
    else
    {
        in >> buf.number >> buf.name >> buf.weight >> buf.conduct;
        return true;
    }
}

void tableFile::delFile()
{
    f -> resize(0);
}
