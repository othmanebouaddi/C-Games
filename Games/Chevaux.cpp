//Chevaux;
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
using namespace std;


string *chevaux;



int chevalGagnan()
{
 	int i(0);
	int nombre_aleatoire(0);
	srand(time(NULL));	

	nombre_aleatoire = rand();
	nombre_aleatoire = (nombre_aleatoire % (15-0)) + 1;

	return nombre_aleatoire;

}


void uploadData()
{

	ifstream monFlux("files/chevaux.txt");  //Ouverture d'un fichier en lecture

	if(monFlux)
	{
		chevaux = new string [15];
	    string ligne;
	    int i(0);
		while(getline(monFlux, ligne))
		{
			cout << ligne << endl;
			chevaux[i] = ligne;
			i++;
		} 

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}


void jeuxChevaux(vector <string> nickname)
{
	string *chevauxChoisie = new string [nickname.size()];

	cout << "Les noms des chevaux de la course d'aujourd'hui!" << endl;

	uploadData();

	cin.ignore();
	for(int joueur(0); joueur < nickname.size(); joueur++)
	{
		
		cout << nickname[joueur] << " choisie ton cheval :" << endl;
		getline(cin, chevauxChoisie[joueur]);

	}

	//Choose randomly a winner horse by calling a randome function

	string nomChevalGagnan = chevaux[chevalGagnan()];

	cout << "the horse winner is : " << nomChevalGagnan << endl;
	// checking who won and who lost
	for(int joueur(0); joueur < nickname.size(); joueur++)
	{
		if(nickname[joueur] == nomChevalGagnan)
			cout << nickname[joueur] << " you won" << endl;
		else
			cout << nickname[joueur] << " you lost" << endl;
	}

	//Free the dynamic memory.

	// for( int nbChevaux(0); nbChevaux < 15; nbChevaux++)
	// {
	// 	delete chevaux[nbChevaux];
	// }

	delete[] chevaux;

	// for( int nbJoueur(0); nbJoueur < nickname.size(); nbJoueur++)
	// {
	// 	delete chevauxChoisie[nbJoueur];
	// }
	
	delete[] chevauxChoisie;

}












