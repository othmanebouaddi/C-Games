//menu.c
#include <iostream>

using namespace std;

int menu()
{
	int choice(0);

	cout << "**************************" << endl;
	cout << "1 : Authentification" << endl;
	cout << "2 : Jeux de carte(pas Implementer)" << endl;
	cout << "3 : Course de chevaux"<< endl;
	cout << "4 : Jeux de dé" << endl;
	cout << "5 : Jeux de mystère"<< endl;
	cout << "6 : Jeux de caillou, ciseaux, papier" << endl;
	cout << "7 : Jeux de trésor(pas Implementer)" << endl;
	cout << "8 : Jeux de mine(pas Implementer)" << endl;
	cout << "9 : Jeux de lotorie" << endl;*
	cout << "10 : Course d'escargot(pas Implementer)" << endl;
	cout << "11 : Jeux stratégique(pas Implementer)" << endl;
	cout << "12 : Date with a girl" << endl;
	cout << "13 : Fight club(pas Implementer)" << endl;
	cout << "14 : Store Data" << endl;
	cout << "15 : Display Data" << endl;
	cout << "16 : Exit" << endl;
	cout << "Your choice is : ";
	cin >> choice ;
	cout << "**************************" << endl;

	return choice;

}