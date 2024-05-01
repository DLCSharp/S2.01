#include "lecteur.h"

void Lecteur::chargerImages(vector<Image*> imagesACharger)
{
    int tailleImages = imagesACharger.size();

    for (int i=0; i<tailleImages; i++)
    {
        (*this).m_tabImages.push_back(imagesACharger[i]);
    }
}

void Lecteur::chargerDiaporamas(vector<Diaporama*> DiaporamasACharger)
{
    int tailleDiaporams = DiaporamasACharger.size();

    for (int i=0; i<tailleDiaporams; i++)
    {
        (*this).m_tabDiaporamas.push_back(DiaporamasACharger[i]);
    }
}

void Lecteur::avancer()
{
    Diaporama* _diaporamaCourant = (*this).m_tabDiaporamas[(*this).m_diaporamaCourant];
    vector<ImageDansDiaporama*> _localisationImages = _diaporamaCourant->getLocalisationImages();

    if ((*this).m_imageCourante == _localisationImages.size() - 1)
    {
        (*this).m_imageCourante = 0;
    }
    else {
        (*this).m_imageCourante += 1;
    }
}

void Lecteur::reculer()
{
    Diaporama* _diaporamaCourant = (*this).m_tabDiaporamas[(*this).m_diaporamaCourant];
    vector<ImageDansDiaporama*> _localisationImages = _diaporamaCourant->getLocalisationImages();

    if ((*this).m_imageCourante == 0)
    {
        (*this).m_imageCourante = _localisationImages.size() - 1;
    }
    else {
        (*this).m_imageCourante -= 1;
    }
}

void Lecteur::afficherImageCouranteDansDiaporamaCourant ()
{
    Image* _imageCourante = (*this).m_tabImages[(*this).m_imageCourante];
    Diaporama* _diaporamaCourant = (*this).m_tabDiaporamas[(*this).m_diaporamaCourant];
    vector<ImageDansDiaporama*> _localisationImages = _diaporamaCourant->getLocalisationImages();

    cout << endl << endl;
    cout << "DIAPORAMA : " << _diaporamaCourant->getTitre() << endl << endl;
    cout << _localisationImages[(*this).m_imageCourante]->getRang() << " sur " << _localisationImages.size() << " / ";
    _imageCourante->afficher();
}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    (*this).m_diaporamaCourant = pNumDiaporama;
    (*this).m_imageCourante = 0;
}

unsigned int Lecteur::getImageCourante() const
{
    return (*this).m_imageCourante;
}

unsigned int Lecteur::getDiapoCourant() const
{
    return (*this).m_diaporamaCourant;
}

vector<Diaporama*> Lecteur::getTabDiaporamas() const
{
    return (*this).m_tabDiaporamas;
}

modesLecteur Lecteur::getMode() const
{
    return (*this).m_mode;
}

void Lecteur::changerImage(unsigned int pNumImage)
{
    (*this).m_imageCourante = pNumImage;
}

void Lecteur::definirMode(modesLecteur mode)
{
    (*this).m_mode = mode;
}

Lecteur::Lecteur() :
    m_mode(MANUEL),
    m_imageCourante(0),
    m_diaporamaCourant(0),
    m_tabDiaporamas(),
    m_tabImages()
{ }

Lecteur::Lecteur(const Lecteur& original) :
    m_mode(original.m_mode),
    m_imageCourante(original.m_imageCourante),
    m_diaporamaCourant(original.m_diaporamaCourant),
    m_tabDiaporamas(original.m_tabDiaporamas),
    m_tabImages(original.m_tabImages)
{ }

Lecteur::~Lecteur()
{
    (*this).m_tabDiaporamas.clear();
    (*this).m_tabImages.clear();
}
