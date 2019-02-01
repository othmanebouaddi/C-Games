//Girl

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
using namespace std;


string *habit;



int girlHabit(int first, int end)
{
 	int i(0);
	int nombre_aleatoire(0);
	srand(time(NULL));	

	nombre_aleatoire = rand();
	nombre_aleatoire = (nombre_aleatoire % (end-first)) + first;

	return nombre_aleatoire;

}


void uploadDataGril()
{

	ifstream monFlux("files/girl.txt");  //Ouverture d'un fichier en lecture

	if(monFlux)
	{
		habit = new string [18];
	    string ligne;
	    int i(0);
		while(getline(monFlux, ligne))
		{
			habit[i] = ligne;
			i++;
		} 

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}


void dateGirl(vector <string> nickname)
{	
	// number to go to the right habit
	int first(-3), end(-1);
	int *score = new int [nickname.size()];
	string *habitChoisie = new string [nickname.size()];
	string habitQuestion[6]= {"What is her best drink? ", "Where does she like go?", "What is her best color?", "What is her best season?", "What does she practice?", "Who's her best actor?"};
	cout << "Lawrence want to go out with one of you, but you have to have the same habit as her" << endl;
	cout << "The one who has more correct answer will go out on date with her!" << endl;

	uploadDataGril();

	// clean the console line.
	cin.ignore();

	for(int i(0); i < nickname.size(); i++)
	{
		score[i] = 0;
	}


	// start asking the players and taking their answers
	for(int nbHabit(0); nbHabit < 6; nbHabit++)
	{
		first += 3;
		end += 3;
		cout << habitQuestion[nbHabit] << endl;

		//Display the choices
		for(int i(first); i < end+1; i++)
		{
			cout << habit[i] << endl;

		}
		// the choice of the players
		for(int joueur(0); joueur < nickname.size(); joueur++)
		{
			cout << "What is your answer " << nickname[joueur] << " : " << endl;
			getline(cin, habitChoisie[joueur]);
		}

		//Choose randomly the girl answer by calling a randome function
		string grilHabitChoosen = habit[girlHabit(first, end)];

		cout << "The girl like : " << grilHabitChoosen << endl;
		
		// checking who won and who lost
		for(int joueur(0); joueur < nickname.size(); joueur++)
		{
			if(habitChoisie[joueur] == grilHabitChoosen)
				score[joueur] += 1;
		}

	}

	// find out the best score.
	int max(0);
	string winner("");
	string* ptr;
	for(int joueur(0); joueur < nickname.size(); joueur++)
	{
		if(score[joueur] > max)
		{
			max = score[joueur];
			winner = nickname[joueur];
			ptr = &nickname[joueur];

		}
	}
	//Declare the winner
	cout << "The winner is : " << winner << endl;


	//Store data in the file
	storeData("Date Girl", nickname, ptr);


	//Free the dynamic memory.
	delete[] habit;
	delete[] habitChoisie;
	delete[] score;

}












