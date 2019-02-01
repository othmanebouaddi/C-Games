//Lotorie

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
using namespace std;


int randNumber(vector<int> number)
{
	int nombre_aleatoire(0);
	srand(time(NULL));
	int loop(0);	

	do
	{
		loop = 0 ;
		nombre_aleatoire = rand();
		nombre_aleatoire = (nombre_aleatoire % (50-1)) + 1;

		for(int i(0); i < number.size(); i++)
		{
			if(nombre_aleatoire == number[i]) loop = 1;
		}

	}while(loop);


	return nombre_aleatoire;

}



void lotteryGame(vector <string> nickname)
{	
	// number to go to the right habit
	int *score = new int [nickname.size()];
	vector<int> number;
	int **numberChoisie = new int*[nickname.size()];
	cout << "Hi every body to the Lottery Game!" << endl;

	for(int i(0); i < 6; i++)
	{
		int newNumber = randNumber(number);
		number.push_back(newNumber);
	}

	// clean the console line.
	cin.ignore();


	//Start asking the player about their six lottery numbers 
	for(int joueur(0); joueur < nickname.size(); joueur++)
	{
		//Create the arry for each player.
		numberChoisie[joueur] = new int[6];

		for(int i(0); i < 6; i++)
		{
			cout << "Hi " << nickname[joueur] << " choose you number " << i+1 << " : " << endl;
			//getline(cin, numberChoisie[joueur][i]);
			cin >> numberChoisie[joueur][i];
		}

	}

	//Initialize the array.
	for(int i(0); i < nickname.size(); i++)
	{
		score[i] = 0;
	}

	// checking who won and who lost
	for(int joueur(0); joueur < nickname.size(); joueur++)
	{
		
		for(int j(0); j < 6; j++)
		{
			for(int i(0); i < 6; i++)
			{
				if(numberChoisie[joueur][i] == number[j])
					score[joueur] += 1;
			}
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
	cout << "The numbers were : ";
	for(int i(0); i < 6; i++)
	{
		cout << number[i] << ", ";
	}
	cout << endl;
	//Declare the winner
	cout << "The winner is : " << winner << endl;


	//Store data in the file
	storeData("Lottery Game", nickname, ptr);


	//Free the dynamic memory.
	delete[] score;
	for (int i = 0; i < nickname.size(); ++i)
    	delete[] numberChoisie[i];
    delete[] numberChoisie;

}












