#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include "salescontainer.h"

namespace Ui {
class SearchDialog;
}

class SalesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SalesDialog(QWidget *parent = 0);
    ~SalesDialog();
    SalesContainer* GetSalesContainer() { return m_sales; }
private:
    Ui::SearchDialog *ui;
    SalesContainer* m_sales;
public slots:
    void FillContainer();
};

#endif // SEARCHDIALOG_H
