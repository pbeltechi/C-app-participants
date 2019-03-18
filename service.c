#include "service.h"
/*adds a participant to the dynamic list
alist = pointer to dynamic list
fname,lname = char pointer
score = elementtype
returns 1 if the participant was succesfully added and 0 otherwise*/
int addparticipant(repo* repos, char* fname, char*lname, ElementType score) {
	Element newp = createparticipant(fname, lname, score);
	if (!validatep(newp)) {
		deleteparticipant(newp);
		free(newp);
		return 0;
	}
	Element found = searchrepo(repos,newp);
	if (found != NULL) {
		deleteparticipant(newp);
		free(newp);
		return 0;
	}
	addtorepo(repos, newp);
	return 1;
}
/*deletes a participant from the darray
alist = pointer to dynamic list
fname,lname = char pointer
returns 1 if the participant was deleted and 0 otherwise*/
int deleteparticipantservice(repo* repos, char* fname, char*lname) {
	Element findp = createparticipant(fname, lname, 1);
	if (!validatep(findp)) {
		deleteparticipant(findp);
		free(findp);
		return 0;
	}	
	int index = repoindex(repos, findp);
	if (index == -1) {
		deleteparticipant(findp);
		free(findp);
		return 0;
	}
	interchangerepo(repos, index, get_lenrepo(repos) - 1);
	deleteparticipantrepo(repos, get_lenrepo(repos) - 1);
	deleteparticipant(findp);
	free(findp);
	return 1;
}
/*updates a participant in the dynamic list
alist = pointer to dynamic list
fname,lname = char pointer
score = elementtype
returns 1 if the participant was uodated and 0 otherwise*/
int updateparticipant(repo* repos, char* fname, char*lname, char* newfname, char*newlname, ElementType newscore) {
	if (!deleteparticipantservice(repos, fname, lname))
		return 0;
	if (!addparticipant(repos, newfname, newlname, newscore))
		return 0;
	return 1;
}
/*appends the elems which are filtered by score
alist = pointer to darray
score = ElementType
newlist = pointer to darray*/
void filterscore(repo* repos, darray* newlist, ElementType score) {
	for (int i = 0; i < get_lenrepo(repos); i++) {
		Element actual = getparticipantrepo(repos,i);
		if (getscore(actual) >= score) {
			Element newel = createparticipant(getfname(actual),getlname(actual),getscore(actual));
			append(newlist, newel);
		}
	}
}
/*returns the sorted list in tosort
alist = pointer to darray
tosort = pointer to new darray
key,cmp = pointer to function
reverse = bool*/
void mysort(repo* repos, darray* tosort, int (*cmp)(Element,Element), int reverse) {
	filterscore(repos, tosort, 0); // copy the repo elems in tosort list
	sort(tosort,(*cmp));
	if (reverse) {
		int n = getlen(tosort);
		for (int i = 0; i < n / 2; i++) {
			interchange(tosort, i, n - i - 1);
		}
	}
}

/*generic sort for sorting the list alist by a key
alist = pointer to darray
key,cmp = pointer to function*/
void sort(darray* alist, int(*cmp)(Element,Element)) {
	//insertion sort
	for(int i=0;i<getlen(alist)-1;i++){
		for (int j = i+1; j < getlen(alist); j++) {
			if (cmp(getparticipant(alist,i),getparticipant(alist, j)) > 0) {
				interchange(alist, i, j);
			}
		}
	}
}
/*returns if Element type a is greater thant ElementType b*/
int greaterthan(Element a, Element b) {
	return getscore(a) > getscore(b);
}
int cmpname(Element a, Element b) {
	return strcmp(getfname(a),getfname(b));
}