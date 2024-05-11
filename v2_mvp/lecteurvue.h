#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QLabel>
#include "lecteur.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class lecteurvue;
}
QT_END_NAMESPACE

class Presentation;

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

    // pour créer une connexion avec la présentation
    void nvlleConnexion(QObject *c);
    void supprConnexion(QObject *c);

    // ordre de la Présentation de MAJ de l’interface en fonction
    // de l’état du modèle
    void majInterface (Lecteur::modesLecteur m);

private:
    Ui::lecteurvue *ui;
    QLabel* labelMode;
    QLabel* labelVitesse;

private slots:

    /*
 * Déclaration des sous-programmes slots pour les boutons du contenu de la fenêtre
*/

    void btnReculer_clic();
    void btnAvancer_clic();
    void btnLancer_clic();
    void btnArreter_clic();

    /*
 * Déclaration des sous-programmes slots pour les actions du menu de la fenêtre
*/

    // Onglet "fichier"
    void fichierChargerDiapo_declenche();
    void fichierEnleverDiapo_declenche();
    void fichierQuitter_declenche();

    // Onglet "paramètres"
    void paramVitUn_declenche();
    void paramVitDeux_declenche();
    void paramVitTrois_declenche();
    void paramVitPerso_declenche();

    // Onglet "aide"
    void aideAPropos_declenche();

signals:

    /*
 * Déclaration des sous-programmes signaux pour les boutons du contenu de la fenêtre
*/

    void demandeReculer();
    void demandeAvancer();
    void demandeLancer();
    void demandeArreter();

    /*
 * Déclaration des sous-programmes signaux pour les actions du menu de la fenêtre
*/

    // Onglet "fichier"
    void demandeChargerDiapo();
    void demandeEnleverDiapo();

    // Onglet "paramètres"
    void demandeDefVitesse(unsigned int vitesse);
};

#endif // LECTEURVUE_H
