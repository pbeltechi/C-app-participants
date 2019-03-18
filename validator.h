#pragma once
#include "Domain.h"
#include <string.h>
/*returns 0 if the string does not contain only letters and 1 otherwise
string = char pointer*/
int validname(char* string);
/*validates if the score >0 and <=100
score = ElementType*/
int validscore(ElementType score);
/*validates a participant
newp = pointer to participant
returns 0 if the participant is not valid, 1 otherwise*/
int validatep(participant* newp);