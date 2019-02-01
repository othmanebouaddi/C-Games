#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
#include <vector>
#include "menu.cpp"
#include "jeuxDe.cpp"
#include "mystere.cpp"
#include "Ccp.cpp"
#include "Chevaux.cpp"
#include "Girl.cpp"
#include "Lotorie.cpp"
//#include "Personnage.h"


using namespace std;


// void figtClub(vector<string> nickname)
// {

//     // vector<Personnage> arr(nickname.size()-1);

//     // for(int fighter(0); fighter < nickname.size(); fighter++)
//     // {
        
//     //     arr[fighter].afficherEtat();
//     // }
//     Personnage goli;
//     //goli.afficherEtat();

// }





int main()
{
	vector <string> nickname(0);
	int exit(1);
    int number(0);


	do{
        switch (menu())
        {
        	case 1 :
                cin.ignore();
        		do
                {
                    nickname.push_back("");
                    number++;
                    cout << "The nickname of player n" << number << " : ";
            		getline(cin, nickname[number-1]);
                    cout << endl;
                }while(nickname[number-1] != "");
                nickname.pop_back();
                for(int i(0); i < nickname.size(); i++)
                {
        		  cout << "HI " << nickname[i] << "!" << endl;
        		} 
                break;
            case 3 : 
                jeuxChevaux(nickname);
                break;
        	case 4 : 
                if(nickname.size())
        		jeuxDe(nickname);
        		break;
            case 5 :
                mystere(nickname);
                break;
            case 6 :
                ccp(nickname);
                break;
            case 9 :
                lotteryGame(nickname);
                break;
            case 12 :
                dateGirl(nickname);
                break;
            case 15 :
                displayData();
                break;
        	case 16 :
                cleanFile();
        		exit = 0;
        		break;
        	default :
        		cout << "Le jeux n'est pas Implementer! veux tu l'ajouter?" << endl; 
        		break;

        }
    }while(exit);

	return 0;

}
