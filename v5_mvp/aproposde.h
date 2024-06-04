#ifndef APROPOSDE_H
#define APROPOSDE_H

#include <QDialog>

namespace Ui {
class aproposde;
}

class aproposde : public QDialog
{
    Q_OBJECT

public:
    explicit aproposde(QWidget *parent = nullptr);
    ~aproposde();

private:
    Ui::aproposde *ui;
};

#endif // APROPOSDE_H
