#ifndef SEARCHMAINTENANCEDIALOG_H
#define SEARCHMAINTENANCEDIALOG_H

#include <QDialog>
#include "maintenancecontainer.h"

namespace Ui {
class SearchMaintenanceDialog;
}

class SearchMaintenanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchMaintenanceDialog(QWidget *parent = 0);
    ~SearchMaintenanceDialog();
     MaintenanceContainer* GetContainer() { return m_container; }

private:
    Ui::SearchMaintenanceDialog *ui;
    MaintenanceContainer* m_container;
public slots:
    void FillContainer();
};

#endif // SEARCHMAINTENANCEDIALOG_H
