#include "image.h"

/*
 * Classe Image
 */

void Image::afficher() const
{
    cout << "Titre : " << (*this).m_intitule << endl;
    cout << "Categorie : " << (*this).m_categorie << endl;
    cout << "Chemin : " << (*this).m_chemin << endl;
}

// Getters

string Image::getIntitule() const
{
    return (*this).m_intitule;
}

string Image::getCategorie() const
{
    return (*this).m_categorie;
}

string Image::getChemin() const
{
    return (*this).m_chemin;
}

// Setters

void Image::setIntitule(string intitule)
{
    (*this).m_intitule = intitule;
}

void Image::setCategorie(string categorie)
{
    (*this).m_categorie = categorie;
}

void Image::setChemin(string chemin)
{
    (*this).m_chemin = chemin;
}

// Constructeurs

Image::Image() :
    m_intitule(),
    m_categorie(),
    m_chemin()
{ }

Image::Image(const Image& original) :
    m_intitule(original.m_intitule),
    m_categorie(original.m_categorie),
    m_chemin(original.m_chemin)
{ }

Image::Image(string categorie, string intitule, string chemin) :
    m_intitule(intitule),
    m_categorie(categorie),
    m_chemin(chemin)
{ }

// Destructeur

Image::~Image()
{ }
