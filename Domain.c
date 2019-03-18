#include "Domain.h"
/*returns a pointer to a participant's first name
participant *p = pointer to a participant*/
char * getfname(participant* p)
{
	return p->fname;
}
/*returns a pointer to a participant's last name
participant *p = pointer to a participant*/
char * getlname(participant* p)
{
	return p->lname;
}
/*returns an elementType var to a participant's score
participant *p = pointer to a participant*/
ElementType getscore(participant* p)
{
	return p->score;
}
/*creates dynamically a participant
char *fname = pointer to a string
char *lname = pointer to a string
elementtype score = elementtype
returns a pointer to the new participant
*/
participant* createparticipant(char * fname, char * lname, ElementType score)
{
	participant* newp = (participant*)malloc(sizeof(participant));
	newp->fname = (char*)malloc(strlen(fname)*sizeof(char)+1);
	strcpy(newp->fname,fname);
	newp->lname = (char*)malloc(strlen(lname) * sizeof(char) + 1);
	strcpy(newp->lname, lname);
	newp->score = score;
	
	return newp;
}
/*frees the fname, lname dynamic memory
participant *p = pointer to a participant
returns 1
*/
int deleteparticipant(participant * p)
{
	free(p->fname);
	free(p->lname);
	return 1;
}