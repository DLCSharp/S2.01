#ifndef LECTEUR_H
#define LECTEUR_H

#include <iostream>
#include <vector>
#include "typeDiaporama.h"

using namespace std;

enum modesLecteur {
    MANUEL,
    AUTOMATIQUE
};

class Lecteur {
private:
    modesLecteur m_mode;
    unsigned int m_imageCourante;
    unsigned int m_diaporamaCourant;
    vector<Diaporama*> m_tabDiaporamas;
    vector<Image*> m_tabImages;

public:
    // Méthodes temporaires pré-implémentation de la base de données
    // Permettent de charger respectivement les images et les diaporamas
    // En mémoire puis de garder un pointeur de ceux-ci dans des tableaux associés
    void chargerImages(vector<Image*> imagesACharger);
    void chargerDiaporamas(vector<Diaporama*> diaporamasACharger);

    void avancer();
    void reculer();
    void afficherImageCouranteDansDiaporamaCourant();

    void triCroissantRang (Diaporama& pDiaporama);
    /* Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
       A garder aussi lors de l'implémentation de la BD */

    // Getters
    unsigned int getImageCourante() const;

    unsigned int getDiapoCourant() const;

    modesLecteur getMode() const;

    vector<Diaporama*> getTabDiaporamas() const;

    // Setters
    void changerImage(unsigned int pNumImage);

    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité

    void definirMode(modesLecteur mode);

    // Constructeur par défaut
    Lecteur();

    // Constructeur de copie
    Lecteur(const Lecteur&);

    // Destructeur
    ~Lecteur();

};

#endif // LECTEUR_H
