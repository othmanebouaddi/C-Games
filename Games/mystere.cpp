//mystere.cpp


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string melangerLettres(string mot)
{
   string melange;
   int position(0);

   //Tant qu'on n'a pas extrait toutes les lettres du mot
   while (mot.size() != 0)
   {
      //On choisit un numéro de lettre au hasard dans le mot
      position = rand() % mot.size();
      //On ajoute la lettre dans le mot mélangé
      melange += mot[position];
      //On retire cette lettre du mot mystère
      //Pour ne pas la prendre une deuxième fois
        mot.erase(position, 1);
    }

   //On renvoie le mot mélangé
   return melange;
}

void mystere(vector<string> nickname)
{
   string motMystere, motMelange, motUtilisateur, joueur1;
   string *ptr;
   int playernumber(0), count(0);

   //Initialisation des nombres aléatoires
   srand(time(0));

	cout << "Who's going to start?" << endl;
	cin.ignore();
	getline(cin, joueur1);
   //1 : On demande de saisir un mot
   cout << joueur1 << " Saisissez un mot" << endl;
   cin >> motMystere;

   //2 : On récupère le mot avec les lettres mélangées dans motMelange
   motMelange = melangerLettres(motMystere);

   //3 : On demande à l'utilisateur quel est le mot mystère
   do
   {
   		// the payer who choose the mystere doesn't have the right to play.
   		if( nickname[playernumber] != joueur1 ) 
   		{
			cout << endl << nickname[playernumber] << " Quel est ce mot ? " << motMelange << endl;
			cin >> motUtilisateur;
			ptr = &nickname[playernumber];

			if (motUtilisateur == motMystere)
			{
			 cout << "Bravo ! " <<  nickname[playernumber] << endl;
			}
			else
			{
			 cout << "Ce n'est pas le mot !" << endl;
			}
			count++;
		}
		// Change the next player.
		if(nickname.size() > playernumber+1){
			playernumber++;
		}else
		{
			playernumber = 0;
		}
   }while (motUtilisateur != motMystere);
   //On recommence tant qu'il n'a pas trouvé


	cout << "Alright " << *ptr << " your right, after " << count << " times" << endl;

	storeData("Jeux Mystere", nickname, ptr);

}