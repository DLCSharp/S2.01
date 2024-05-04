#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QObject>
#include <QDebug>

lecteurvue::lecteurvue(QWidget *parent)
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

/*
 * Définition des sous-programmes slots pour les boutons du contenu de la fenêtre
*/

void lecteurvue::btnReculer_clic()
{
    qDebug() << "Bouton reculer d'image clique";
    ui->btnArreter->setDisabled(true);
}

void lecteurvue::btnAvancer_clic()
{
    qDebug() << "Bouton avancer d'image clique";
    ui->btnArreter->setDisabled(true);
}

void lecteurvue::btnLancer_clic()
{
    qDebug() << "Bouton lancer le diaporama clique";
    ui->btnArreter->setDisabled(false);
}

void lecteurvue::btnArreter_clic()
{
    qDebug() << "Bouton arreter le diaporama clique";
    ui->btnArreter->setDisabled(true);
}

/*
 * Définition des sous-programmes slots pour les actions du menu de la fenêtre
*/

// Onglet "fichier"

void lecteurvue::fichierChargerDiapo_declenche()
{
    qDebug() << "Action charger un diaporama declenche";
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
