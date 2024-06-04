#include "presentation.h"
#include "lecteurvue.h"

Presentation::Presentation(Lecteur* m, QObject *parent)
    : QObject{parent}, _leModele(m)
{
    _leModele->changerDiaporama(2, "Diaporama de Pantxika", 1);
    _leModele->setMode(Lecteur::MANUEL);

    timerModeAuto = new QTimer();
    QObject::connect(timerModeAuto, SIGNAL(timeout()),
                     this, SLOT(avancer()));
}

Lecteur* Presentation::getModele() const
{
    return _leModele;
}

LecteurVue* Presentation::getVue() const
{
    return _laVue;
}

void Presentation::setModele(Lecteur *m)
{
    _leModele = m;
}

void Presentation::setVue(LecteurVue *v)
{
    _laVue = v;
}

void Presentation::avancer()
{
    _leModele->avancer();
    realiserMajVue();
}

void Presentation::reculer()
{
    _leModele->reculer();
    realiserMajVue();
}

void Presentation::slotDemandeReculer()
{
    qDebug() << "[Presentation] Reception de la demande d'avancement d'image";

    if (_leModele->getMode() == Lecteur::AUTOMATIQUE)
    {
        timerModeAuto->stop();
        _leModele->setMode(Lecteur::MANUEL);
    }

    reculer();
}

void Presentation::slotDemandeAvancer()
{
    qDebug() << "[Presentation] Reception de la demande d'avancement d'image";

    if (_leModele->getMode() == Lecteur::AUTOMATIQUE)
    {
        timerModeAuto->stop();
        _leModele->setMode(Lecteur::MANUEL);
    }

    avancer();
}

void Presentation::slotDemandeLancer()
{
    qDebug() << "[Presentation] Reception de la demande de lancement du diaporama";

    switch (_leModele->getMode())
    {
        case Lecteur::VIDE:
            break;

        case Lecteur::MANUEL:
            timerModeAuto->setInterval(_leModele->getDiaporama()->getVitesseDefilement() * 1000);
            timerModeAuto->start();

            _leModele->setMode(Lecteur::AUTOMATIQUE);
            break;

        case Lecteur::AUTOMATIQUE:
            timerModeAuto->stop();

            _leModele->setPosImageCourante(0);

            timerModeAuto->setInterval(_leModele->getDiaporama()->getVitesseDefilement() * 1000);
            timerModeAuto->start();

            break;
    }

    realiserMajVue();
}

void Presentation::slotDemandeArreter()
{
    qDebug() << "[Presentation] Reception de la demande d'arret du diaporama";

    timerModeAuto->stop();
    _leModele->setMode(Lecteur::MANUEL);

    realiserMajVue();
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void Presentation::slotDemandeChargerDiapo()
{
    qDebug() << "[Presentation] Reception de la demande de chargement d'un diaporama";
    realiserMajVue();
}

void Presentation::slotDemandeEnleverDiapo()
{
    qDebug() << "[Presentation] Reception de la demande d'enlevement du diaporama";
    realiserMajVue();
}

// Onglet "paramètres"

void Presentation::slotDemandeDefVitesse(unsigned int vitesse)
{
    qDebug() << "[Presentation] Reception de la demande de definition de vitesse de defilement a : " << vitesse;
    realiserMajVue();
}

void Presentation::realiserMajVue() {

    Lecteur::modesLecteur modeDuLecteur =_leModele->getMode();

    if (_leModele->lecteurVide())
    {
        _laVue->majInterface(modeDuLecteur);
        return;
    }

    if (_leModele->nbImages() == 0)
    {
        qDebug() << "Diaporama vide";
        _laVue->majInterface(modeDuLecteur);
        return;
    }
    else
    {
        // Informations communes requises
        mapLabels["intituleDiapoCourant"] = QString::fromStdString(_leModele->getDiaporama()->getTitre());

        mapLabels["numImageCourante"] = QString::number(_leModele->getDiaporama()->getImages()[_leModele->getPosImageCourante()]->getRangDansDiaporama());
        mapLabels["nbImages"] = QString::number(_leModele->getDiaporama()->getImages().size());

        mapLabels["cheminImage"] = QString::fromStdString(_leModele->getImageCourante()->getChemin());


        // Informations requises seulement au mode auto
        if (modeDuLecteur == Lecteur::AUTOMATIQUE)
        {
            mapLabels["vitesseDefil"] = QString::number(_leModele->getDiaporama()->getVitesseDefilement());
        }
    }

     _laVue->majInterface(modeDuLecteur, mapLabels);
}
