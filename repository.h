#pragma once
#include "Domain.h"
#include "repolist.h"
typedef struct {
	darray* list;
}repo;

/*creates the repository and returns a pointer*/
repo* createrepo();

/*deletes the space allocated for repository*/
void deleterepo(repo* repository);

/*adds an elem to repository*/
void addtorepo(repo* repository, Element* p);

/*returns how much elems are in repo*/
int get_lenrepo(repo* repository);

/*interchanges the element from index1 with the el of index2
index1,index2 = int*/
void interchangerepo(repo* repository, int index1, int index2);

/*returns the participant at index in the repo or Null if index is nonvalid
index = int*/
Element getparticipantrepo(repo* repository, int index);

/*Searches for a participant in repo
returns the pointer to participant or NULL if it doesnt exist*/
Element searchrepo(repo* repository, Element elem);

/*Returns the index of elem in repo or -1 if it does not exists
findp = Element*/
int repoindex(repo* repository, Element elem);

/*deletes the participant at index in repo
index = int*/
void deleteparticipantrepo(repo* repos, int index);