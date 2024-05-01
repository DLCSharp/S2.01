#include <iostream>
#include "sousprogrammes.h"

void testClasseImage();

void testImageDansDiapo();

void testCopieDiaporama();

int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/

    Lecteur* lecteurDiaporama = new Lecteur();

    // Chargement des urls des images, chargement des diaporamas

    chargerImagesFactices(lecteurDiaporama);
    chargerDiaporamasFactices(lecteurDiaporama);


    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles

    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran
        lecteurDiaporama->afficherImageCouranteDansDiaporamaCourant();


        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        saisieVerifChoixActionSurImageCourante(choixAction);
        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
        declencherAction(choixAction, lecteurDiaporama);
    }

    /* Fin
       --------------*/
      cout << "Au revoir " << endl;
      return 0;
}
