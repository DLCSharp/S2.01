#ifndef LECTEUR_H
#define LECTEUR_H

#include <iostream>
#include <vector>
#include "typeDiaporama.h"

using namespace std;

// Sera utilisé lors de l'implémentation du mode automatique
enum modesLecteur {
    MANUEL,
    AUTOMATIQUE
};

/*
 * Classe Lecteur
 */

class Lecteur {
private:
    modesLecteur m_mode; // mode du lecteur, défini parmi une des valeurs de l'enum modesLecteur, le mode automatique sera implémenté dans une version future
    unsigned int m_imageCourante; //Position de l’image - représentée par une ImageDansDiapo dans chaque instance de Diaporama - dans m_tabImages
    unsigned int m_diaporamaCourant; // Position du diaporama courant dans le vecteur de diaporamas
    vector<Diaporama*> m_tabDiaporamas; // vecteur des diaporamas chargés dans le lecteur
    vector<Image*> m_tabImages; // vecteur des images chargées dans le lecteur

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
