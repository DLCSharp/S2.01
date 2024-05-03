#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include "lecteur.h"
#include "typeDiaporama.h"

void triCroissantRang (Diaporama* pDiaporama);

void saisieVerifChoixActionSurImageCourante(char& pChoixAction);

unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas);

void declencherAction(char pChoixAction, Lecteur* lecteur);

void chargerImagesFactices(Lecteur* lecteur);

void chargerDiaporamasFactices(Lecteur* lecteur);

void afficherImageCouranteDansDiaporamaCourant (const Diaporama& pDiaporama, unsigned int pImageCourante, const Image& pImage);

void triCroissantRang (Diaporama* pDiaporama);

#endif // SOUSPROGRAMMES_H
