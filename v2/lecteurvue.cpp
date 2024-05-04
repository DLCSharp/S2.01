#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QObject>
#include <QDebug>

lecteurvue::lecteurvue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurvue)
{
    ui->setupUi(this);

    labelMode = new QLabel();
    labelMode->setVisible(false);
    labelVitesse = new QLabel();
    labelVitesse->setVisible(false);

    ui->statusbar->addWidget(labelMode);
    ui->statusbar->addPermanentWidget(labelVitesse);

/*
 * Connexion des actions de la barre de menu
 */

    // Onglet "fichier"
    connect(ui->actionFichierOuvrirDiapo, SIGNAL(triggered()), this, SLOT(fichierOuvrirDiapo_declenche()));
    connect(ui->actionFichierChangerDiapo, SIGNAL(triggered()), this, SLOT(fichierChangerDiapo_declenche()));
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

/*
 * Définition des sous-programmes slots pour les boutons du contenu de la fenêtre
*/

void lecteurvue::btnReculer_clic()
{
    qDebug() << "bouton reculer d'image clique";
}

void lecteurvue::btnAvancer_clic()
{
    qDebug() << "bouton avancer d'image clique";
}

void lecteurvue::btnLancer_clic()
{
    qDebug() << "bouton lancer le diaporama clique";
    ui->btnArreter->setDisabled(false);
}

void lecteurvue::btnArreter_clic()
{
    qDebug() << "bouton arreter le diaporama clique";
    ui->btnArreter->setDisabled(true);
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void lecteurvue::fichierOuvrirDiapo_declenche()
{
    qDebug() << "Action ouvrir un diaporama declenche";
}

void lecteurvue::fichierChangerDiapo_declenche()
{
    qDebug() << "Action changer de diaporama declenche";
}

void lecteurvue::fichierEnleverDiapo_declenche()
{
    qDebug() << "Action enlever le diaporama declenche";
}

void lecteurvue::fichierQuitter_declenche()
{
    qDebug() << "Action quitter declenche";
}

// Onglet "paramètres"

void lecteurvue::paramVitUn_declenche()
{
    qDebug() << "Action de definition de vitesse de defilement a 1 declenche";
}

void lecteurvue::paramVitDeux_declenche()
{
    qDebug() << "Action de definition de vitesse de defilement a 2 declenche";
}

void lecteurvue::paramVitTrois_declenche()
{
    qDebug() << "Action de definition de vitesse de defilement a 3 declenche";
}

void lecteurvue::paramVitPerso_declenche()
{
    qDebug() << "Action de definition de vitesse de defilement personnalise declenche";
}

// Onglet "aide"

void lecteurvue::aideAPropos_declenche()
{
    qDebug() << "Action A Propos De declenche";
}


lecteurvue::~lecteurvue()
{
    delete ui;
}
