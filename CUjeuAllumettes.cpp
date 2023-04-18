#include <iostream>
#include "CUjeuAllumettes.h"
using namespace std;
#include <QMessageBox>

CUjeuAllumettes::CUjeuAllumettes(){
    ihm.RecupAddJeu(this);
    ihm.show();
    ihm.initIHM();
}

int CUjeuAllumettes::tirageAleatoire(int mini, int maxi){
    srand(time(NULL));
    nbreAllumettes = rand()%(maxi-mini)+mini;
    return nbreAllumettes;
}

void CUjeuAllumettes::setnbreAllumettes(int NBreAllumettes){
    nbreAllumettes = NBreAllumettes;
}

int CUjeuAllumettes::getnbreAllumettes(){
    return nbreAllumettes;
}

int CUjeuAllumettes::getjoueurEnCours(){
    return joueurEnCours;
}

void CUjeuAllumettes::ChangerJoueur(){
    if(joueurEnCours==0){
           joueurEnCours++;
       }else if(joueurEnCours==1){
           joueurEnCours--;
       }
}

void CUjeuAllumettes::commencerunepartie(){
int z=0;
nom[0]=ihm.saisirNom(0);
nom[1]=ihm.saisirNom(1);
if(nom[0]=="" || nom[1]=="")
{
    QMessageBox msgBox; QString x;
    msgBox.setIcon(QMessageBox::Information);
                x="le nom des joueurs est mal rentrée !";
    msgBox.setText(x);
 msgBox.exec();
}
else {
ihm.boutonJOUERonOff(0);
ihm.nomsOnOff(0);
ihm.boutonOKonOff(1);
nbreAllumettes=tirageAleatoire(5,20);
setnbreAllumettes(nbreAllumettes);
joueurEnCours=1;
ihm.afficherJeuAllumettes(nbreAllumettes);
ihm.afficherMessage(nom[z++]);
ihm.NbAEnleverOnOff(1);
}
}
