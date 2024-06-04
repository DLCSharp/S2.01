#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "lecteur.h"

class LecteurVue;

class Presentation : public QObject
{
    Q_OBJECT
public:
    explicit Presentation(Lecteur* m, QObject *parent = nullptr);

public:
    Lecteur* getModele() const;
    LecteurVue* getVue() const;
    void setModele(Lecteur* m);
    void setVue(LecteurVue* v);

    void realiserMajVue();

public slots:
    void reculer();
    void avancer();

// Slots pour les signaux de lecteurvue

/*
 * Déclaration des sous-programmes slots pour les boutons du contenu de la fenêtre
*/

    void slotDemandeReculer();
    void slotDemandeAvancer();
    void slotDemandeLancer();
    void slotDemandeArreter();

/*
 * Déclaration des sous-programmes slots pour les actions du menu de la fenêtre
*/

    // Onglet "fichier"
    void slotDemandeChargerDiapo();
    void slotDemandeEnleverDiapo();

    // Onglet "paramètres"
    void slotDemandeDefVitesse(unsigned int vitesse);

private:
    Lecteur* _leModele;
    LecteurVue* _laVue;

    QMap<QString, QString> mapLabels;

    QTimer* timerModeAuto;
};

#endif // PRESENTATION_H
