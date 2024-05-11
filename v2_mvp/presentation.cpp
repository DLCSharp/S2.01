#include "presentation.h"

Presentation::Presentation(Lecteur* m, QObject *parent)
    : QObject{parent}, _leModele(m)
{}

Lecteur* Presentation::getModele()
{
    return _leModele;
}

LecteurVue* Presentation::getVue()
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
}

void Presentation::demandeAvancer()
{
    qDebug() << "[Presentation] Reception de la demande d'avancement d'image";
}

void Presentation::demandeLancer()
{
    qDebug() << "[Presentation] Reception de la demande de lancement du diaporama";
}

void Presentation::demandeArreter()
{
    qDebug() << "[Presentation] Reception de la demande d'arret du diaporama";
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void Presentation::demandeChargerDiapo()
{
    qDebug() << "[Presentation] Reception de la demande de chargement d'un diaporama";
}

void Presentation::demandeEnleverDiapo()
{
    qDebug() << "[Presentation] Reception de la demande d'enlevement du diaporama";
}

// Onglet "paramètres"

void Presentation::demandeDefVitesse(unsigned int vitesse)
{
    qDebug() << "[Presentation] Reception de la demande de definition de vitesse de defilement a : " << vitesse;
}
