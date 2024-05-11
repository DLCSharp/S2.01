#include "modele.h"

Modele::Modele(Modes_Lecteur m, QObject *parent)
    : QObject{parent}, _mode(m)
{ }

Modele::Modes_Lecteur Modele::getMode()
{
    return _mode;
}
