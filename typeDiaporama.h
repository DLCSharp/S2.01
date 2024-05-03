#ifndef TYPEDIAPORAMA_H
#define TYPEDIAPORAMA_H

#include "image.h"
#include <iostream>
#include <vector>

using namespace std;

class ImageDansDiaporama
{
private:
    unsigned int m_pos;  // rang de l'image dans le tableau d'images
    unsigned int m_rang; // rang de l'image dans le diaporama

public:
    // Getters
    unsigned int getPos() const;

    unsigned int getRang() const;

    // Setters
    void setPos(unsigned int pos);

    void setRang(unsigned int rang);

    // Constructeur par défaut
    ImageDansDiaporama();

    // Constructeur de copie
    ImageDansDiaporama(const ImageDansDiaporama&);

    // Constructeur avec attributs
    ImageDansDiaporama(unsigned int pos, unsigned int rang);

    // Destructeur
    ~ImageDansDiaporama();
};

class Diaporama
{
private:
    string m_titre;
    unsigned int m_vitesseDefilement;
    vector<ImageDansDiaporama*> m_localisationImages;

public:
    // Getters
    string getTitre() const;

    unsigned int getVitesse() const;

    unsigned int getNbImages() const;

    vector<ImageDansDiaporama*> getLocalisationImages() const;

    // Setters
    void setTitre(string titre);

    void setVitesse(unsigned int vitesse);

    void setNbImages(unsigned int nbImages);

    void setLocalisationImages(vector<ImageDansDiaporama*> localImages);

    // Constructeur par défaut
    Diaporama();

    // Constructeur de copie
    Diaporama(const Diaporama&);

    // Constructeur avec attributs
    Diaporama(string titre, unsigned int vitesseDefilement, vector<ImageDansDiaporama*> localImage);

    // Destructeur
    ~Diaporama();
};

typedef vector<Image*> Images;
typedef vector<Diaporama*> Diaporamas;

#endif // TYPEDIAPORAMA_H
