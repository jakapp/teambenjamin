#ifndef CARSEARCHDIALOG_H
#define CARSEARCHDIALOG_H

#include <QDialog>
#include "CarContainer.h"

namespace Ui {
class CarSearchDialog;
}

class CarSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarSearchDialog(QWidget *parent = 0);
    ~CarSearchDialog();
    CarContainer* GetContainer() { return m_container; }

private:
    Ui::CarSearchDialog *ui;
    CarContainer* m_container;
public slots:
    void FillContainer();

};

#endif // CARSEARCHDIALOG_H
