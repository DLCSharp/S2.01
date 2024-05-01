#include "sousprogrammes.h"

void saisieVerifChoixActionSurImageCourante(char& pChoixAction)
{
    cout << endl << endl;
    while (true)
    {
        cout  << endl ;
        cout << "ACTIONS :" << "  A-vancer" << "  R-eculer" << "  C-hanger de diaporama " << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}
unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas)
{
    unsigned int choixSaisi;
    unsigned int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
         cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < pDiaporamas.size(); num++)
        {
            cout << num << ": " << pDiaporamas[num]->getTitre();
            if (num != pDiaporamas.size()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(pDiaporamas.size())))
        {
            break;
        }
    }
    return choixDiaporama;
}

void declencherAction(char pChoixAction, Lecteur* lecteur)
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */
{
    unsigned int choixDiaporama;

    switch (pChoixAction)
    {
        case 'A':
            lecteur->avancer();
            lecteur->afficherImageCouranteDansDiaporamaCourant();
            break;
        case 'R':
            lecteur->reculer();
            lecteur->afficherImageCouranteDansDiaporamaCourant();
            break;
        case 'C' :
            cout << "Choisissez un Diaporama " << endl;
            choixDiaporama = saisieVerifChoixDiaporama(lecteur->getTabDiaporamas());
            // Changer de diaporama
            lecteur->changerDiaporama(choixDiaporama);
            break;

        default : break;
    }
}

void chargerImagesFactices(Lecteur* lecteur)
{
    // Charger en mémoire des instances de la classe Image représentant les informations d'images fictives

    vector<Image*> imagesACharger;

    // Création des instances d'Image
    Image* imageUne = new Image("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    Image* imageDeux = new Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    Image* imageTrois = new Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    Image* imageQuatre = new Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    Image* imageCinq = new Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    Image* imageSix = new Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    Image* imageSept = new Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");

    // Ajout dans le vecteur d'images
    imagesACharger.push_back(imageUne);
    imagesACharger.push_back(imageDeux);
    imagesACharger.push_back(imageTrois);
    imagesACharger.push_back(imageQuatre);
    imagesACharger.push_back(imageCinq);
    imagesACharger.push_back(imageSix);
    imagesACharger.push_back(imageSept);

    lecteur->chargerImages(imagesACharger);
}

void chargerDiaporamasFactices(Lecteur* lecteur)
{
    // Charger en mémoire des instances de la classe Diaporama représentant les informations de diaporamas fictifs

    vector<Diaporama*> diaporamasACharger;

    // Diaporama par défaut
    vector<ImageDansDiaporama*> imagesDiapoParDefaut;
    ImageDansDiaporama* imageDiapoParDefaut = new ImageDansDiaporama(0, 1);
    imagesDiapoParDefaut.push_back(imageDiapoParDefaut);

    Diaporama* diaporamaParDefaut = new Diaporama("Diaporama par defaut", 1, imagesDiapoParDefaut);
    triCroissantRang(diaporamaParDefaut);
    diaporamasACharger.push_back(diaporamaParDefaut);

    // Diaporama de Pantxika
    vector<ImageDansDiaporama*> imagesDiapoPantxika;
    imagesDiapoPantxika.push_back(new ImageDansDiaporama(4, 3));
    imagesDiapoPantxika.push_back(new ImageDansDiaporama(1, 2));
    imagesDiapoPantxika.push_back(new ImageDansDiaporama(2, 4));
    imagesDiapoPantxika.push_back(new ImageDansDiaporama(3, 1));

    Diaporama* diaporamaPantxika = new Diaporama("Diaporama Pantxika", 2, imagesDiapoPantxika);
    triCroissantRang(diaporamaPantxika);
    diaporamasACharger.push_back(diaporamaPantxika);

    // Diaporama de Thierry
    vector<ImageDansDiaporama*> imagesDiapoThierry;
    imagesDiapoThierry.push_back(new ImageDansDiaporama(4, 1));
    imagesDiapoThierry.push_back(new ImageDansDiaporama(1, 2));
    imagesDiapoThierry.push_back(new ImageDansDiaporama(2, 3));
    imagesDiapoThierry.push_back(new ImageDansDiaporama(3, 4));

    Diaporama* diaporamaThierry = new Diaporama("Diaporama Thierry", 4, imagesDiapoThierry);
    triCroissantRang(diaporamaThierry);
    diaporamasACharger.push_back(diaporamaThierry);

    // Diaporama de Yann
    vector<ImageDansDiaporama*> imagesDiapoYann;
    imagesDiapoYann.push_back(new ImageDansDiaporama(4, 2));
    imagesDiapoYann.push_back(new ImageDansDiaporama(1, 1));
    imagesDiapoYann.push_back(new ImageDansDiaporama(2, 4));
    imagesDiapoYann.push_back(new ImageDansDiaporama(3, 3));

    Diaporama* diaporamaYann = new Diaporama("Diaporama Yann", 3, imagesDiapoYann);
    triCroissantRang(diaporamaYann);
    diaporamasACharger.push_back(diaporamaYann);

    // Diaporama de Manu
    vector<ImageDansDiaporama*> imagesDiapoManu;
    imagesDiapoManu.push_back(new ImageDansDiaporama(4, 4));
    imagesDiapoManu.push_back(new ImageDansDiaporama(1, 3));
    imagesDiapoManu.push_back(new ImageDansDiaporama(2, 2));
    imagesDiapoManu.push_back(new ImageDansDiaporama(3, 1));

    Diaporama* diaporamaManu = new Diaporama("Diaporama Manu", 1, imagesDiapoManu);
    triCroissantRang(diaporamaManu);
    diaporamasACharger.push_back(diaporamaManu);

    lecteur->chargerDiaporamas(diaporamasACharger);
}

void triCroissantRang (Diaporama* pDiaporama)
{   // par la méthode du triBulle

    vector<ImageDansDiaporama*> localImages = pDiaporama->getLocalisationImages();
    unsigned int taille = localImages.size();

    ImageDansDiaporama* imageDansDiapo;

    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (localImages[i]->getRang() > localImages[i+1]->getRang())
            {
                // echanger les 2 éléments
                imageDansDiapo = localImages[i];
                localImages[i] = localImages[i+1];
                localImages[i+1] = imageDansDiapo;
            }
        }
    }

    pDiaporama->setLocalisationImages(localImages);
}


