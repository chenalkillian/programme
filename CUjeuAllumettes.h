#ifndef CUJEUALLUMETTES_H
#define CUJEUALLUMETTES_H
#include <QMainWindow>
#include <iostream>
#include "ihmjoueur.h"
using namespace std;


//ici on crée la classe CUjeuAllumettes avec le tableau de nom, et les autres paramètres.

class CUjeuAllumettes{
private:
    QString nom[2];
    int nbreAllumettes;
    int joueurEnCours;
    IHMjoueur ihm;
    int tirageAleatoire(int mini,int maxi);

public:
    //les métodes
    CUjeuAllumettes();
    void setnbreAllumettes(int);
    int getnbreAllumettes();
    int getjoueurEnCours();
    void ChangerJoueur();
    void commencerunepartie();
};

#endif // CUJEUALLUMETTES_H
