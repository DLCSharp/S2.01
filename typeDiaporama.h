#ifndef TYPEDIAPORAMA_H
#define TYPEDIAPORAMA_H

#include <iostream>
#include "image.h"

using namespace std;

class ImageDansDiaporama {
private:
    unsigned int m_pos;  // rang de l'image dans le tableau d'images
    unsigned int m_rang; // rang de l'image dans le diaporama
    Image* m_image;

public:

    // Getters
    unsigned int getPos() const;

    unsigned int getRang() const;

    Image* getImage() const;

    // Setters
    void setPos(unsigned int pos);

    void setRang(unsigned int rang);

    void setImage(Image* image);

    // Constructeur par défaut
    ImageDansDiaporama();

    // Constructeur avec attributs
    ImageDansDiaporama(unsigned int pos, unsigned int rang, Image* image);

    // Destructeur
    ~ImageDansDiaporama();
};

class Diaporama {
private:
    string m_titre;
    unsigned int m_vitesse = 1;
    unsigned int m_nbImages;
    ImageDansDiaporama* m_tabImagesDansDiapo[];

public:

    void chargerImages();

    // Getters
    string getTitre() const;

    unsigned int getVitesse() const;

    unsigned int getNbImages() const;

    // Setters
    void setTitre(string titre);

    void setVitesse(unsigned int vitesse);

    void setNbImages(unsigned int nbImages);

    // Constructeur par défaut
    Diaporama();

    // Constructeur avec attributs
    Diaporama(string titre, unsigned int vitesse, unsigned int nbimages, ImageDansDiaporama* tabImagesDansDiapo[]);

    // Destructeur
    ~Diaporama();
};

#endif // TYPEDIAPORAMA_H
