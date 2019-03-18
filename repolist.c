#include "repolist.h"

/*returns the elems from the alist
alist = pointer to a darray*/
int getlen(darray* alist) {
	return alist->n;
}

/*creates a dynamic list for participants
returns pointer to list*/
darray* createlist() {
	darray* newlist = (darray*)malloc(sizeof(darray));
	newlist->n = 0;
	newlist->participantlist = (Element*)malloc(2 * sizeof(Element));
	newlist->capacity = 2;
	return newlist;
}
/*deletes all the participants from the list and the list itself
alist = pointer to a darray*/
void deletelist(darray* alist) {
	for (int i = 0; i < getlen(alist); i++) {
		deleteparticipant(alist->participantlist[i]);
		free(alist->participantlist[i]);
	}
	free(alist->participantlist);
	free(alist);
}

/*appends a participant to participantlist
! copies the fname,lname and score, frees the newp pointer to participant
alist = pointer to darray
newp = pointer to a new participant
*/
void append(darray* alist, Element newp) {
	if (alist->n == alist->capacity) {
		alist->capacity *= 2;
		alist->participantlist = realloc(alist->participantlist, alist->capacity * sizeof(Element));
	}
	alist->participantlist[alist->n++] = newp;
	//free(newp); // frees the first pointer before copying the fname lname and score
}
/*interchanges the element from index1 with the el of index2
alist = pointer to a darray
index1,index2 = int*/
void interchange(darray* alist, int index1, int index2) {
	Element aux = alist->participantlist[index1];
	alist->participantlist[index1] = alist->participantlist[index2];
	alist->participantlist[index2] = aux;
}
/*returns the participant at index in the darray or Null if index is nonvalid
alist = pointer to a darray
index = int*/
Element getparticipant(darray* alist,int index) {
	if (index < 0 || index >= getlen(alist))
		return NULL;
	return alist->participantlist[index];

}
/*deletes the participant at index
alist = pointer to a darray
index = int*/
void deleteparticipantlist(darray * alist, int index) {
	deleteparticipant(alist->participantlist[index]);
	free(alist->participantlist[index]);
	alist->n--;
}
/*Searches for a participant in the dynamic list
alist = pointer to darray
returns the pointer to participant or NULL if it doesnt exist*/
Element searchparticipant(darray* alist, Element tosearch) {
	for (int i = 0; i < getlen(alist); i++) {
		Element actual = getparticipant(alist, i);
		if (_strcmpi(getfname(actual), getfname(tosearch)) == 0 && _strcmpi(getlname(actual), getlname(tosearch))==0)
			return actual;
	}
	return NULL;
}
/*Returns the index of a participant in the list or -1 if it does not exists
alist = pointer to darray
findp = Element*/
int participantindex(darray *alist, Element findp) {
	for (int i = 0; i < getlen(alist); i++) {
		Element actual = getparticipant(alist, i);
		if (_strcmpi(getfname(actual), getfname(findp)) == 0 && _strcmpi(getlname(actual), getlname(findp)) == 0) {
			return i;
		}
	}
	return -1;
}
