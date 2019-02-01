//jeuxDe.h

#if !defined(_JEUXDE_H_)
#define _JEUXDE_H_

#include <string>
#include <vector>


/*
 * Function which display the game of dice. 
 * take  parameter : the nickname of the player.
 * return nothing.
*/
void jeuxDe(vector<string> nickname);

/*
 * Function which count the random number. 
 * no parameters.
 * return a int the random number.
*/
int diceFace();

#endif 