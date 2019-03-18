#pragma once
#include "repolist.h"
#include <stdlib.h>
#include <string.h>
typedef int ElementType;
typedef struct {
	char* fname;
	char* lname;
	ElementType score;
}participant;

/*creates dynamically a participant
char *fname = pointer to a string
char *lname = pointer to a string
elementtype score = elementtype
returns a pointer to the new participant
*/
participant* createparticipant(char* fname,char* lname,ElementType score);

/*frees the memory allocated to a participant
participant *p = pointer to a participant
returns 1
*/
int deleteparticipant(participant* p);

/*returns a pointer to a participant's first name
participant *p = pointer to a participant*/
char* getfname(participant* p);

/*returns a pointer to a participant's last name
participant *p = pointer to a participant*/
char* getlname(participant* p);

/*returns an elementType var to a participant's score
participant *p = pointer to a participant*/
ElementType getscore(participant* p);