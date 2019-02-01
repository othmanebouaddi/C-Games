//Ccp.cpp

#include <iostream>
#include <string>
#include <vector>
// #include "Ccp.h"

using namespace std;




int ccpRand()
{
	int nombre_aleatoire(0);
	srand(time(NULL));	

	nombre_aleatoire = rand();
	nombre_aleatoire = (nombre_aleatoire % (2-0)) + 1;
	return nombre_aleatoire;

}

int whoWin(string choice , int numberSecret)
{
	int win(0);
	if(choice == "caillo")
	{
		switch(numberSecret)
		{
			case 0 :
				win = 0;
				break;
			case 1 :
				win = 1;
				break;
			case 2 :
				win = 0;
				break;
		}
	}
	else if( choice == "ciseaux")
	{
		switch(numberSecret)
		{
			case 0 :
				win = 0;
				break;
			case 1 :
				win = 0;
				break;
			case 2 :
				win = 1;
				break;
		}
	}
	else if(choice == "papier")
	{
		switch(numberSecret)
		{
			case 0 :
				win = 1;
				break;
			case 1 :
				win = 0;
				break;
			case 2 :
				win = 0;
				break;
		}
	}
	else {
		win = 0;
	}
	return win;

}







void ccp( vector<string> nickname)
{
	int win(0);
	string choice;
	string *ptr;
	string value[3] = {"caillou", "cisaux", "papier"};

	cout << "You have to fchoose between pebble, scissors and paper and challenge the computer" << endl;

	//If the player doen't enter any name;
	if( nickname.size() == 0)
	{
		nickname.push_back("Guest");
	}

	//the number of player
	int numberSecret(0);
	for(int playernumber(0); playernumber < nickname.size(); playernumber++)
	{

		cout << nickname[playernumber] << " Choose a pebble or scissors or paper !" << endl;
		cin >> choice ; 
		ptr = &nickname[playernumber];
		numberSecret = ccpRand();
		win = whoWin(choice , numberSecret);

		cout << endl;
		cout << "the computer choice is  : " << value[numberSecret] << endl;
		
		if(win)
		{
			cout << "Alright " << *ptr << " your win " << endl;
			win = 0;
		}
		else
		{
			cout << "I am sorry " << *ptr << " your lost " << endl;
		}
	}


	//storeData("CailloCiseauPapier", nickname, ptr);
}




