#ifndef LECTEUR_H
#define LECTEUR_H

#include <iostream>
#include "typeDiaporama.h"

using namespace std;

enum modesLecteur {
    MANUEL,
    AUTOMATIQUE
};

class Lecteur {
private:
    modesLecteur m_mode = MANUEL;
    unsigned short int m_ImageCourante = 0;
    unsigned short int m_DiapoCourant = 0;
    Diaporama* m_tabDiapo[];

public:

    void suivant();
    void precedent();
    void supprimerDiapo();
    void changerDiapo();

    void triImageCroissant();
    void triImageDecroissant();

    void chargerDiapo();

    // Getters
    unsigned int getImageCourante() const;

    unsigned int getDiapoCourant() const;

    modesLecteur getMode() const;

    // Setters
    void setImageCourante(unsigned short int imageCourante);

    void setDiapoCourant(unsigned short int diapoCourant);

    modesLecteur setMode(modesLecteur mode);

    // Constructeur par défaut
    Lecteur();

    // Destructeur
    ~Lecteur();

};

#endif // LECTEUR_H
