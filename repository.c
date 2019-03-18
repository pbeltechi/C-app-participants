#include "repository.h"
/*creates the repository and returns a pointer*/
repo* createrepo() {
	repo* repos = (repo*)malloc(sizeof(repo));
	repos->list = createlist();
	return repos;
}
/*deletes the space allocated for repository*/
void deleterepo(repo* repository) {
	deletelist(repository->list);
	free(repository);
}
/*adds an elem to repository*/
void addtorepo(repo* repository, Element* p) {
	append(repository->list,p);
}
/*returns how much elems are in repo*/
int get_lenrepo(repo* repository) {
	return getlen(repository->list);
}
/*interchanges the element from index1 with the el of index2
index1,index2 = int*/
void interchangerepo(repo* repository,int index1,int index2) {
	interchange(repository->list,index1,index2);
}
/*returns the participant at index in the repo or Null if index is nonvalid
index = int*/
Element getparticipantrepo(repo* repository, int index) {
	return getparticipant(repository->list,index);
}
/*Searches for a participant in repo
returns the pointer to participant or NULL if it doesnt exist*/
Element searchrepo(repo* repository, Element elem) {
	return searchparticipant(repository->list, elem);
}
/*Returns the index of elem in repo or -1 if it does not exists
findp = Element*/
int repoindex(repo* repository, Element elem) {
	return participantindex(repository->list,elem);
}
/*deletes the participant at index in repo
index = int*/
void deleteparticipantrepo(repo* repos, int index) {
	deleteparticipantlist(repos->list,index);
}