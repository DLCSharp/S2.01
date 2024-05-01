#include "typediaporama.h"

// Classe ImageDansDiaporama

unsigned int ImageDansDiaporama::getPos() const
{
    return (*this).m_pos;
}

unsigned int ImageDansDiaporama::getRang() const
{
    return (*this).m_rang;
}

void ImageDansDiaporama::setPos(unsigned int pos)
{
    (*this).m_pos = pos;
}

void ImageDansDiaporama::setRang(unsigned int rang)
{
    (*this).m_rang = rang;
}

ImageDansDiaporama::ImageDansDiaporama() :
    m_pos(),
    m_rang()
{ }

ImageDansDiaporama::ImageDansDiaporama(const ImageDansDiaporama& original) :
    m_pos(original.m_pos),
    m_rang(original.m_rang)
{ }

ImageDansDiaporama::ImageDansDiaporama(unsigned int pos, unsigned int rang) :
    m_pos(pos),
    m_rang(rang)
{ }

ImageDansDiaporama::~ImageDansDiaporama()
{ }

// Classe Diaporama

string Diaporama::getTitre() const
{
    return (*this).m_titre;
}

unsigned int Diaporama::getVitesse() const
{
    return (*this).m_vitesseDefilement;
}

vector<ImageDansDiaporama*> Diaporama::getLocalisationImages() const
{
    return (*this).m_localisationImages;
}

void Diaporama::setLocalisationImages(vector<ImageDansDiaporama*> localImages)
{

    for (int i=0; i<localImages.size(); i++)
    {
        (*this).m_localisationImages[i] = localImages[i];
    }
}

void Diaporama::setTitre(string titre)
{
    (*this).m_titre = titre;
}

void Diaporama::setVitesse(unsigned int vitesse)
{
    (*this).m_vitesseDefilement = vitesse;
}

Diaporama::Diaporama() :
    m_titre(),
    m_vitesseDefilement(1),
    m_localisationImages()
{ }

Diaporama::Diaporama(const Diaporama& original) :
    m_titre(original.m_titre),
    m_vitesseDefilement(original.m_vitesseDefilement),
    m_localisationImages()
{ }

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement, vector<ImageDansDiaporama*> localImage) :
    m_titre(titre),
    m_vitesseDefilement(vitesseDefilement),
    m_localisationImages(localImage)
{ }

Diaporama::~Diaporama()
{
    m_localisationImages.clear();
}
