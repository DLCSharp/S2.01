#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

using namespace std;

class Image
{
private:
    string m_intitule;  // intitulé de l'image
    string m_categorie; // catégorie de l'image (personne, animal, objet)
    string m_chemin;

public:
    // Méthode pour afficher tous les champs de l'image
    void afficher() const;

    // Getters
    string getIntitule() const;

    string getCategorie() const;

    string getChemin() const;

    // Setters
    void setIntitule(string intitule);

    void setCategorie(string categorie);

    void setChemin(string chemin);

    // Constructeur par défaut
    Image();

    // Constructeur de copie
    Image(const Image&);

    // Constructeur avec attributs
    Image(string categorie, string intitule, string chemin);

    // Destructeur
    ~Image();
};

#endif // IMAGE_H
