 #include "ihmjoueur.h"
#include "ui_ihmjoueur.h"
#include "CUjeuAllumettes.h"
#include <iostream>
#include <QMessageBox>
using namespace std;
IHMjoueur::IHMjoueur(QWidget *parent): QMainWindow(parent), ui(new Ui::IHMjoueur)
{
ui->setupUi(this);
}

IHMjoueur::~IHMjoueur()
{
delete ui;
}

void IHMjoueur::initIHM()
{
ui->Joueur1Nom->setText("");
ui->Joueur2Nom->setText("");
ui->OK->setEnabled(false);
ui->NbAEnlever->setText("");
ui->NbAEnlever->setEnabled(false);
ui->zoneMessage->clear();
ui->Jouer->setEnabled(true);
ui->Joueur1Nom->setEnabled(true);
ui->Joueur2Nom->setEnabled(true);
ui->Allumettes->setText("");

}

QString IHMjoueur::saisirNom(int numerojoueur){
QString nom,x;QMessageBox msgBox;
if(numerojoueur==0){
nom=ui->Joueur1Nom->text();
}else if(numerojoueur==1) {
nom=ui->Joueur2Nom->text();
}
return nom;
}

void IHMjoueur::RecupAddJeu(class CUjeuAllumettes* jeu){
addJeuAllumettes = jeu;
}

void IHMjoueur::afficherJeuAllumettes(int NbreAllumettes){
QString ALLumettess;
for(int i=0;i<NbreAllumettes;i++){
ALLumettess = ALLumettess + "| ";
ui->Allumettes->setText(ALLumettess);
}
}

void IHMjoueur::afficherMessage(QString Message){
ui->zoneMessage->setText(Message);
}

void IHMjoueur::boutonOKonOff(bool okonoff){
if(okonoff==0){
ui->OK->setEnabled(false);
}else if(okonoff==1){
ui->OK->setEnabled(true);
}
}

void IHMjoueur::boutonJOUERonOff(bool joueronoff){
if(joueronoff==0){
ui->Jouer->setEnabled(false);
}else if(joueronoff==1){
ui->Jouer->setEnabled(true);
}
}

void IHMjoueur::nomsOnOff(bool nomsonoff){
if(nomsonoff == 0 ){
ui->Joueur1Nom->setEnabled(false);
ui->Joueur2Nom->setEnabled(false);
}else if(nomsonoff == 1){
ui->Joueur1Nom->setEnabled(true);
ui->Joueur2Nom->setEnabled(true);
}
}

void IHMjoueur::NbAEnleverOnOff(bool nbaenleveronOff){
if (nbaenleveronOff==0){
ui->NbAEnlever->setEnabled(false);
}else if(nbaenleveronOff==1){
ui->NbAEnlever->setEnabled(true);
}
}

void IHMjoueur::on_Jouer_clicked()
{addJeuAllumettes->commencerunepartie();}

void IHMjoueur::on_OK_clicked()
{
QMessageBox msgBox; QString x;

QString nom[2];
nom[0]=ui->Joueur1Nom->text();
nom[1]=ui->Joueur2Nom->text();
int nbrsupprimes,nbrtotal,nbrallumettes,joueurencours;

nbrallumettes=addJeuAllumettes->getnbreAllumettes();
joueurencours=addJeuAllumettes->getjoueurEnCours();
nbrsupprimes=ui->NbAEnlever->text().toInt();
nbrtotal = nbrallumettes-nbrsupprimes;

int flag = 0 ;
if (flag==0) {
    try
      {


       if(nbrsupprimes<1 || nbrsupprimes>3) throw 1;

       if(nbrsupprimes>nbrallumettes  ) throw 2 ;
       if (nbrtotal==0 &&  joueurencours==1) throw 3;
       if (nbrtotal==0 && joueurencours==0) throw 4;
       flag =1;
       addJeuAllumettes->setnbreAllumettes(nbrtotal);

       afficherJeuAllumettes(nbrtotal);


       addJeuAllumettes->ChangerJoueur();

       afficherMessage(nom[joueurencours]);
      }
      catch (int i)
    {
        switch (i) {
            case 1:

            x="le chiffre doit être compris entre 1 et 3 !";


            break;

            case 2:

            x="le chiffre dépasse le nombre d'allumettes, impossible";


            break;
        case 3:

            x="le vainqueur est " +nom[1];
            initIHM();
            break;

        case 4:

             x="le vainqueur est "+ nom[0];
             initIHM();

            break;
        }
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setText(x);
         msgBox.exec();
        flag=0;
    }

}


}




