#include "presentation.h"
#include "lecteurvue.h"

Presentation::Presentation(Lecteur* m, QObject *parent)
    : QObject{parent}, _leModele(m)
{
    _leModele->changerDiaporama(2, "Diaporama de Pantxika");
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

void Presentation::slotDemandeReculer()
{
    qDebug() << "[Presentation] Reception de la demande de recul d'image";

    _leModele->reculer();

    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

void Presentation::slotDemandeAvancer()
{
    qDebug() << "[Presentation] Reception de la demande d'avancement d'image";

    _leModele->avancer();

    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

void Presentation::slotDemandeLancer()
{
    qDebug() << "[Presentation] Reception de la demande de lancement du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

void Presentation::slotDemandeArreter()
{
    qDebug() << "[Presentation] Reception de la demande d'arret du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void Presentation::slotDemandeChargerDiapo()
{
    qDebug() << "[Presentation] Reception de la demande de chargement d'un diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

void Presentation::slotDemandeEnleverDiapo()
{
    qDebug() << "[Presentation] Reception de la demande d'enlevement du diaporama";
    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

// Onglet "paramètres"

void Presentation::slotDemandeDefVitesse(unsigned int vitesse)
{
    qDebug() << "[Presentation] Reception de la demande de definition de vitesse de defilement a : " << vitesse;
    _laVue->majInterface(_leModele->getMode());
    realiserMajLabelsVue();
}

void Presentation::realiserMajLabelsVue() {

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
            mapLabels["intituleDiapoCourant"] = QString::fromStdString(_leModele->getDiaporama()->getTitre());

            mapLabels["numImageCourante"] = QString::number(_leModele->getDiaporama()->getImages()[_leModele->getPosImageCourante()]->getRangDansDiaporama());
            mapLabels["nbImages"] = QString::number(_leModele->getDiaporama()->getImages().size());

            mapLabels["cheminImage"] = QString::fromStdString(_leModele->getImageCourante()->getChemin());
        }


    _laVue->majInterface_Labels(mapLabels);
}
