//file.c
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
using namespace std;

void storeData(string game, vector<string> nickname, string *ptr)
{
	string const nomFichier("files/scores.txt");
	
	ofstream monFlux(nomFichier.c_str(), ios::app);
	
	if(monFlux)  //On teste si tout est OK
	{
	    monFlux << " ** " << game << " **"<< endl;
	    monFlux << "The Players :" <<  endl;

	    for( int i(0); i < nickname.size(); i++)
	    {
	    	monFlux << nickname[i] << ", ";
	    	
	    }
	    monFlux << endl;

	    monFlux << "The winner is : " << *ptr << endl;  

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}

void displayData()
{

	ifstream monFlux("files/scores.txt");  //Ouverture d'un fichier en lecture

	if(monFlux)
	{

	    string ligne;

		while(getline(monFlux, ligne))
		{
			cout << ligne << endl;
		} 

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}


void cleanFile()
{
	remove( "files/scores.txt" );
}




