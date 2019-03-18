#include "validator.h"
/*returns 0 if the string does not contain only letters and 1 otherwise
string = char pointer*/
int validname(char * string) {
	if ((string[0] >= 'A' && string[0] <= 'Z') || (string[0] >= 'a' && string[0] <= 'z')) {
		for (unsigned int i = 1; i < strlen(string); i++) {
			if (string[i]<'a' || string[i]>'z') {
				return 0;
			}
		}
		return 1;
	}
	return 0;
	
}
/*validates if the score >0 and <=100
score = ElementType*/
int validscore(ElementType score) {
	if (score > 0 && score <=100)
		return 1;
	return 0;
}

/*validates a participant
newp = pointer to participant
returns 0 if the participant is not valid, 1 otherwise*/
int validatep(participant * newp) {
	if (!validname(getfname(newp)))
		return 0;
	if (!validname(getlname(newp)))
		return 0;
	if (!validscore(getscore(newp)))
		return 0;
	return 1;
}
