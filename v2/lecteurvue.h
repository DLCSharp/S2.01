#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class lecteurvue;
}
QT_END_NAMESPACE

class lecteurvue : public QMainWindow
{
    Q_OBJECT

public:
    lecteurvue(QWidget *parent = nullptr);
    ~lecteurvue();

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
    void fichierOuvrirDiapo_declenche();
    void fichierChangerDiapo_declenche();
    void fichierEnleverDiapo_declenche();
    void fichierQuitter_declenche();

    // Onglet "paramètres"
    void paramVitUn_declenche();
    void paramVitDeux_declenche();
    void paramVitTrois_declenche();
    void paramVitPerso_declenche();

    // Onglet "aide"
    void aideAPropos_declenche();

};
#endif // LECTEURVUE_H
