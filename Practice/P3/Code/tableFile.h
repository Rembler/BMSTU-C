#ifndef TABLEFILE_H
#define TABLEFILE_H
#include <QFile>

struct elem
{
    QString name, conduct, number, weight;
};

class tableFile
{
    QFile *f;
public:
    elem buf;
    tableFile();
    ~tableFile();
    void addElem(elem a);
    bool readElem();
    void delFile();
};

#endif // TABLEFILE_H
