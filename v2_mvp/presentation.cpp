#include "presentation.h"
#include "lecteurvue.h"

Presentation::Presentation(Lecteur* m, QObject *parent)
    : QObject{parent}, _leModele(m)
{}

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

void Presentation::slotDemandeReculer()
{
    qDebug() << "[Presentation] Reception de la demande de recul d'image";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::slotDemandeAvancer()
{
    qDebug() << "[Presentation] Reception de la demande d'avancement d'image";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::slotDemandeLancer()
{
    qDebug() << "[Presentation] Reception de la demande de lancement du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::slotDemandeArreter()
{
    qDebug() << "[Presentation] Reception de la demande d'arret du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void Presentation::slotDemandeChargerDiapo()
{
    qDebug() << "[Presentation] Reception de la demande de chargement d'un diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::slotDemandeEnleverDiapo()
{
    qDebug() << "[Presentation] Reception de la demande d'enlevement du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

// Onglet "paramètres"

void Presentation::slotDemandeDefVitesse(unsigned int vitesse)
{
    qDebug() << "[Presentation] Reception de la demande de definition de vitesse de defilement a : " << vitesse;
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::realiserMajTexteLabelsVue() {

    if (_leModele->lecteurVide())
    {
        qDebug() << "Lecteur vide = pas de diaporama charge";
        return;
    }

        if (_leModele->nbImages() == 0)
        {
            qDebug() << "Diaporama vide";
        }
        else
        {
            mapTexteLabelsVue["intituleDiapoCourant"] = QString::fromStdString(_leModele->getDiaporama()->getTitre());

            mapTexteLabelsVue["numImageCourante"] = QString::number(_leModele->getDiaporama()->getImages()[_leModele->getPosImageCourante()]->getRangDansDiaporama());
            mapTexteLabelsVue["nbImages"] = QString::number(_leModele->getDiaporama()->getImages().size());

            mapTexteLabelsVue["titreImageCourante"] = QString::fromStdString(_leModele->getDiaporama()->getImages()[_leModele->getPosImageCourante()]->getTitre());
            mapTexteLabelsVue["categorieImage"] = QString::fromStdString(_leModele->getDiaporama()->getImages()[_leModele->getPosImageCourante()]->getCategorie());
        }


    _laVue->majInterface_texteLabels(mapTexteLabelsVue);
}
