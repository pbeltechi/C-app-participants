#pragma once
#include <string.h>
#include "repository.h"
#include "validator.h"
/*searches a participant in the dynamic list
alist = pointer to dynamic list
fname,lname = char pointer
score = elementtype
returns 1 if the participant was found and 0 otherwise*/
int addparticipant(repo* repos, char* fname, char*lname, ElementType score);
/*deletes a participant from the darray
alist = pointer to dynamic list
fname,lname = char pointer
returns 1 if the participant was deleted and 0 otherwise*/
int deleteparticipantservice(repo* repos, char* fname, char*lname);
/*updates a participant in the dynamic list
alist = pointer to dynamic list
fname,lname = char pointer
score = elementtype
returns 1 if the participant was uodated and 0 otherwise*/
int updateparticipant(repo* repos, char* fname, char*lname, char* newfname, char*newlname, ElementType newscore);
/*appends the elems which are filtered by score
alist = pointer to darray
score = ElementType
newlist = pointer to darray*/
void filterscore(repo* repos,darray* newlist, ElementType score);
/*returns the sorted list in tosort
alist = pointer to darray
tosort = pointer to new darray
key,cmp = pointer to function
reverse = bool*/
void mysort(repo* repos, darray* tosort, int(*cmp)(Element, Element),int reverse);
/*generic sort for sorting the list alist by a key
alist = pointer to darray
key,cmp = pointer to function*/
void sort(darray* alist, int(*cmp)(Element, Element));
/*returns if Element type a is greater thant ElementType b*/
int greaterthan(Element a, Element b);
/*returns if name of element a is greater than name of el b*/
int cmpname(Element a, Element b);