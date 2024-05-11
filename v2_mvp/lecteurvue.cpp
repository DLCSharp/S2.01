#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QObject>
#include <QDebug>
#include <QInputDialog>

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurvue)
{
    ui->setupUi(this);

    // Création des labels affichant le mode du lecteur et la vitesse de défilement du diaporama courant
    labelMode = new QLabel("Mode : <mode du lecteur> ");
    labelVitesse = new QLabel("Vitesse : <vitesse défilement diapo courant>");

    // Ajout des labels à la barre d'état
    ui->statusbar->addWidget(labelMode);
    ui->statusbar->addPermanentWidget(labelVitesse);

    // Définition de la propriété d'alignement horizontal des éléments sur "centre" dans le layout de groupBoxImages
    QLayout* layoutGroupBoxImages = ui->groupBoxImages->layout();
    layoutGroupBoxImages->setAlignment(Qt::AlignCenter);
    ui->groupBoxImages->setLayout(layoutGroupBoxImages);

    /*
 * Connexion des actions de la barre de menu
 */

    // Onglet "fichier"
    connect(ui->actionFichierChargerDiapo, SIGNAL(triggered()), this, SLOT(fichierChargerDiapo_declenche()));
    connect(ui->actionFichierEnleverDiapo, SIGNAL(triggered()), this, SLOT(fichierEnleverDiapo_declenche()));
    connect(ui->actionFichierQuitter, SIGNAL(triggered()), this, SLOT(fichierQuitter_declenche()));

    // Onglet "paramètres"
    connect(ui->actionParamVitUn, SIGNAL(triggered()), this, SLOT(paramVitUn_declenche()));
    connect(ui->actionParamVitDeux, SIGNAL(triggered()), this, SLOT(paramVitDeux_declenche()));
    connect(ui->actionParamVitTrois, SIGNAL(triggered()), this, SLOT(paramVitTrois_declenche()));
    connect(ui->actionParamVitPerso, SIGNAL(triggered()), this, SLOT(paramVitPerso_declenche()));

    // Onglet "aide"
    connect(ui->actionAideAPropos, SIGNAL(triggered()), this, SLOT(aideAPropos_declenche()));

    /*
 * Connexion des boutons
 */

    connect(ui->btnReculer, SIGNAL(clicked()), this, SLOT(btnReculer_clic()));
    connect(ui->btnAvancer, SIGNAL(clicked()), this, SLOT(btnAvancer_clic()));
    connect(ui->btnLancer, SIGNAL(clicked()), this, SLOT(btnLancer_clic()));
    connect(ui->btnArreter, SIGNAL(clicked()), this, SLOT(btnArreter_clic()));
}

void LecteurVue::nvlleConnexion(QObject *c)
{
    // Pour se connecter avec la présentation
    QObject::connect(this, SIGNAL(demandeReculer()),
                     c, SLOT(demandeReculer()));

    QObject::connect(this, SIGNAL(demandeAvancer()),
                     c, SLOT(demandeAvancer()));

    QObject::connect(this, SIGNAL(demandeLancer()),
                     c, SLOT(demandeLancer()));

    QObject::connect(this, SIGNAL(demandeArreter()),
                     c, SLOT(demandeArreter()));

    QObject::connect(this, SIGNAL(demandeChargerDiapo()),
                     c, SLOT(demandeChargerDiapo()));

    QObject::connect(this, SIGNAL(demandeEnleverDiapo()),
                     c, SLOT(demandeEnleverDiapo()));

    QObject::connect(this, SIGNAL(demandeDefVitesse(unsigned int)),
                     c, SLOT(demandeDefVitesse(unsigned int)));
}

void LecteurVue::supprConnexion(QObject *c)
{
    // Pour se déconnecter de la présentation
    QObject::disconnect(this, SIGNAL(demandeReculer()),
                        c, SLOT(demandeReculer()));

    QObject::disconnect(this, SIGNAL(demandeAvancer()),
                        c, SLOT(demandeAvancer()));

    QObject::disconnect(this, SIGNAL(demandeLancer()),
                        c, SLOT(demandeLancer()));

    QObject::disconnect(this, SIGNAL(demandeArreter()),
                        c, SLOT(demandeArreter()));

    QObject::disconnect(this, SIGNAL(demandeChargerDiapo()),
                        c, SLOT(demandeChargerDiapo()));

    QObject::disconnect(this, SIGNAL(demandeEnleverDiapo()),
                        c, SLOT(demandeEnleverDiapo()));

    QObject::disconnect(this, SIGNAL(demandeDefVitesse(unsigned int)),
                        c, SLOT(demandeDefVitesse(unsigned int)));
}

void LecteurVue::majInterface(Lecteur::modesLecteur m)
{
    switch (m) {

    case Lecteur::MANUEL :

        break;

    case Lecteur::AUTOMATIQUE :

        break;

    default: break;
    }
}

/*
 * Définition des sous-programmes slots pour les boutons du contenu de la fenêtre
*/

void LecteurVue::btnReculer_clic()
{
    qDebug() << "[Vue] Bouton reculer d'image clique";
    qDebug() << "[Vue] Envoi de la demande de recul d'image";

    emit demandeReculer();

}

void LecteurVue::btnAvancer_clic()
{
    qDebug() << "[Vue] Bouton avancer d'image clique";
    qDebug() << "[Vue] Envoi de la demande d'avancement d'image";

    emit demandeAvancer();
}

void LecteurVue::btnLancer_clic()
{
    qDebug() << "[Vue] Bouton lancer le diaporama clique";
    qDebug() << "[Vue] Envoi de la demande de lancement du diaporama ";

    emit demandeLancer();
}

void LecteurVue::btnArreter_clic()
{
    qDebug() << "[Vue] Bouton arreter le diaporama clique";
    qDebug() << "[Vue] Envoi de la demande d'arret du diaporama ";

    emit demandeArreter();
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void LecteurVue::fichierChargerDiapo_declenche()
{
    qDebug() << "[Vue] Action charger un diaporama declenche";
    qDebug() << "[Vue] Envoi de la demande de chargement d'un diaporama";

    emit demandeChargerDiapo();
}

void LecteurVue::fichierEnleverDiapo_declenche()
{
    qDebug() << "[Vue] Action enlever le diaporama declenche";
    qDebug() << "[Vue] Envoi de la demande d'enlevement du diaporama";

    emit demandeEnleverDiapo();
}

void LecteurVue::fichierQuitter_declenche()
{
    qDebug() << "[Vue] Action quitter declenche";
}

// Onglet "paramètres"

void LecteurVue::paramVitUn_declenche()
{
    qDebug() << "[Vue] Action de definition de vitesse de defilement a 1 declenche";
    qDebug() << "[Vue] Envoi de la demande de definition de vitesse de defilement  a : 1";

    emit demandeDefVitesse(1);
}

void LecteurVue::paramVitDeux_declenche()
{
    qDebug() << "[Vue] Action de definition de vitesse de defilement a 2 declenche";
    qDebug() << "[Vue] Envoi de la demande de definition de vitesse de defilement a : 2";

    emit demandeDefVitesse(2);
}

void LecteurVue::paramVitTrois_declenche()
{
    qDebug() << "[Vue] Action de definition de vitesse de defilement a 3 declenche";
    qDebug() << "[Vue] Envoi de la demande de definition de vitesse de defilement a : 3";

    emit demandeDefVitesse(3);
}

void LecteurVue::paramVitPerso_declenche()
{
    // Implémentation temporaire pré-V3 de test

    qDebug() << "[Vue] Action de definition de vitesse de defilement personnalise declenche";
    qDebug() << "[Vue] Envoi de la demande de definition de vitesse de defilement a : 0 (placeholder)";

    emit demandeDefVitesse(0); // Valeur placeholder en attendant l'implémentation réelle de la V3
}

// Onglet "aide"

void LecteurVue::aideAPropos_declenche()
{
    qDebug() << "[Vue] Action A Propos De declenche";

}

LecteurVue::~LecteurVue()
{
    delete ui;
}

