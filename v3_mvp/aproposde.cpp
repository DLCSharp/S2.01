#include "aproposde.h"
#include "ui_aproposde.h"

aproposde::aproposde(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aproposde)
{
    ui->setupUi(this);
}

aproposde::~aproposde()
{
    delete ui;
}
