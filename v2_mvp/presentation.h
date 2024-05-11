#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include <QDebug>
#include "lecteur.h"

class LecteurVue;

class Presentation : public QObject
{
    Q_OBJECT
public:
    explicit Presentation(Lecteur* m, QObject *parent = nullptr);

public:
    Lecteur* getModele();
    LecteurVue* getVue();
    void setModele(Lecteur* m);
    void setVue(LecteurVue* v);

public slots:

// Slots pour les signaux de lecteurvue

/*
 * Déclaration des sous-programmes slots pour les boutons du contenu de la fenêtre
*/

    void demandeReculer();
    void demandeAvancer();
    void demandeLancer();
    void demandeArreter();

/*
 * Déclaration des sous-programmes slots pour les actions du menu de la fenêtre
*/

    // Onglet "fichier"
    void demandeChargerDiapo();
    void demandeEnleverDiapo();

    // Onglet "paramètres"
    void demandeDefVitesse(unsigned int vitesse);


private:
    Lecteur* _leModele;
    LecteurVue* _laVue;

};

#endif // PRESENTATION_H
