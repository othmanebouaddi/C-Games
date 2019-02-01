//jeuxDe.cpp
// #include "jeuxDe.h"
#include <iostream>
#include <string>
#include <vector>
#include "file.cpp"

using namespace std;



int diceFace()
{
 	int i(0);
	int nombre_aleatoire(0);
	srand(time(NULL));	

	nombre_aleatoire = rand();
	nombre_aleatoire = (nombre_aleatoire % (7-1)) + 1;
	return nombre_aleatoire;

}


void jeuxDe( vector<string> nickname)
{
	int count(0);
	int numberSecret(diceFace());
	int choice(0);
	string *ptr;

	cout << "You have to find the face of the dice! " << endl;

	//If the player doen't enter any name;
	if( nickname.size() == 0)
	{
		nickname.push_back("Guest");
	}

	//the number of player
	int playernumber(0);
	do
	{

		cout << nickname[playernumber] << " Choose a number between 1 and 6!" << endl;
		cin >> choice ; 
		ptr = &nickname[playernumber];

		count++;
		if(nickname.size() > playernumber+1){
			playernumber++;
		}else
		{
			playernumber = 0;
		}
	
	}while( choice < 1 || choice > 6 || choice != numberSecret);

	//We do that to preserve the last played if he won.
	//if(playernumber == 0 ) playernumber = nickname.size();
	
	cout << "Alright " << *ptr << " your right after " << count << " times" << endl;

	storeData("JeuxDe", nickname, ptr);
}



