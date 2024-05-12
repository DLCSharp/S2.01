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

void Presentation::demandeReculer()
{
    qDebug() << "[Presentation] Reception de la demande de recul d'image";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::demandeAvancer()
{
    qDebug() << "[Presentation] Reception de la demande d'avancement d'image";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::demandeLancer()
{
    qDebug() << "[Presentation] Reception de la demande de lancement du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::demandeArreter()
{
    qDebug() << "[Presentation] Reception de la demande d'arret du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void Presentation::demandeChargerDiapo()
{
    qDebug() << "[Presentation] Reception de la demande de chargement d'un diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

void Presentation::demandeEnleverDiapo()
{
    qDebug() << "[Presentation] Reception de la demande d'enlevement du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajTexteLabelsVue();
}

// Onglet "paramètres"

void Presentation::demandeDefVitesse(unsigned int vitesse)
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
