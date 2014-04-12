#ifndef SEARCHCUSTOMERDIALOG_H
#define SEARCHCUSTOMERDIALOG_H

#include <QDialog>
#include "CustomerContainer.h"

namespace Ui {
class SearchCustomerDialog;
}

class SearchCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchCustomerDialog(QWidget *parent = 0);
    ~SearchCustomerDialog();
    CustomerContainer* GetContainer() { return m_container; }
private:
    Ui::SearchCustomerDialog *ui;
    CustomerContainer* m_container;
public slots:
    void FillContainer();
};

#endif // SEARCHCUSTOMERDIALOG_H
