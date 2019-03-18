#pragma once
#include "Domain.h"
typedef void* Element;
typedef struct {
	int capacity;
	int n;
	Element* participantlist;
}darray;

/*returns the elems from the alist
alist = pointer to a darray*/
int getlen(darray* alist);
/*creates a dynamic list for participants
returns pointer to list*/
darray* createlist();
/*appends a participant to participantlist
! copies the fname,lname and score, frees the newp pointer to participant
alist = pointer to darray
newp = pointer to a new participant
*/
void append(darray* alist,Element newp);
/*deletes all the participants from the list and the list itself
alist = pointer to a darray*/
void deletelist(darray* alist);

/*interchanges the element from index1 with the el of index2
alist = pointer to a darray
index1,index2 = int*/
void interchange(darray* alist, int index1,int index2);
/*returns the participant at index in the darray or Null if index is nonvalid
alist = pointer to a darray
index = int*/
Element getparticipant(darray* alist, int index);
/*deletes the participant at index
alist = pointer to a darray
index = int*/
void deleteparticipantlist(darray* alist, int index);
/*Searches for a participant in the dynamic list
alist = pointer to darray
returns the pointer to participant or NULL if it doesnt exist*/
Element searchparticipant(darray* alist,Element tosearch);
/*Returns the index of a participant in the list or -1 if it does not exists
alist = pointer to darray
findp = Element*/
int participantindex(darray *alist, Element findp);