#ifndef GRAPH_H
#define GRAPH_H
#include <QDialog>
#include "ui_graph.h"

class FormDialog :public QDialog, public Ui::GraphQueue
{
	Q_OBJECT
public:
	FormDialog(QWidget* parent = 0);
private slots:
    void adder();
    void remover();
    void sorter();
	void allremover();
};
#endif
