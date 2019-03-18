#include "tests.h"

/*tests the creating and deleting a participant (Domain.h)
also getfname,lname and score */
void testparticipant() {
	char fname[5] = "paul";
	char lname[5] = "belt";
	ElementType score = 50;
	participant* newp = createparticipant(fname,lname,score);
	assert(strcmp(getfname(newp), fname) == 0);
	assert(strcmp(getlname(newp), lname) == 0);
	assert(getscore(newp)==score);
	deleteparticipant(newp);
	free(newp);
}
/*tests the append and deleting the dynamic list (repo.h)*/
void testlist() {
	darray* alist = createlist();
	assert(alist->n==0);
	assert(alist->capacity == 2);
	char fname[5] = "paul";
	char lname[5] = "belt";
	ElementType score = 60;
	participant* newp = createparticipant(fname, lname, score);
	append(alist, newp);
	assert(alist->n == 1);
	assert(alist->capacity == 2);
	participant* lpart = getparticipant(alist, alist->n - 1);
	assert(strcmp(getfname(lpart), fname) == 0);
	assert(strcmp(getlname(lpart), lname) == 0);
	assert(getscore(lpart) == score);
	assert(getparticipant(alist, alist->n) == NULL);
	assert(searchparticipant(alist, newp) != NULL);
	deletelist(alist);
}
/*tets the addparticipant functionality (service.h)*/
void testparticipanti() {
	repo* alist = createrepo();
	assert(addparticipant(alist, "paul", "belt", 70) == 1);
	assert(addparticipant(alist, "paul", "belt", 30) == 0);
	assert(addparticipant(alist, "asd", "bggg", 5) == 1);
	assert(addparticipant(alist, "1asd", "bel", 3) == 0);
	assert(addparticipant(alist, "Paul", "b123", 5) == 0);
	assert(addparticipant(alist, "scor", "scor", -1) == 0);
	assert(addparticipant(alist, "PPal", "bel", 5) == 0);
	assert(get_lenrepo(alist) == 2);
	assert(addparticipant(alist, "bun", "bun", 100) == 1);
	assert(get_lenrepo(alist) == 3);
	assert(deleteparticipantservice(alist, "bun", "bun") == 1);
	assert(deleteparticipantservice(alist, "NUE", "BUN") == 0);
	assert(get_lenrepo(alist) == 2);
	assert(deleteparticipantservice(alist, "bun", "bun") == 0);
	deleterepo(alist);
}
/*tests the update participant functionality*/
void testupdate() {
	repo* alist = createrepo();
	char fname[5] = "paul";
	char lname[5] = "belt";
	ElementType score = 70;
	assert(addparticipant(alist, fname, lname, score) == 1);
	char nfname[5] = "andr";
	char nlname[5] = "pele";
	ElementType nscore = 100;
	assert(updateparticipant(alist, fname, lname, nfname, nlname, nscore) == 1);
	assert(updateparticipant(alist, fname, lname, nfname, nlname, nscore) == 0);
	assert(updateparticipant(alist, nfname, nlname, "NUE", "BUN", 45) == 0);
	deleterepo(alist);
}
/*tests the filter functionality*/
void testfilter() {
	repo* alist = createrepo();

	assert(addparticipant(alist, "paul", "belt", 92) == 1);
	assert(addparticipant(alist, "razvan", "b", 91) == 1);
	assert(addparticipant(alist, "silviu", "a", 70) == 1);
	assert(addparticipant(alist, "bogdan", "a", 60) == 1);
	darray* tosort = createlist();
	filterscore(alist, tosort,71);
	assert(tosort->n == 2);
	assert(getscore(getparticipant(tosort, 0)) == 92);
	assert(getscore(getparticipant(tosort, 1)) == 91);
	deletelist(tosort);

	deleterepo(alist);
}

/*tests the sort functionality*/
void testsort() {
	repo* alist = createrepo();

	assert(addparticipant(alist, "paul", "belt", 92) == 1);
	assert(addparticipant(alist, "razvan", "b", 91) == 1);
	assert(addparticipant(alist, "silviu", "a", 70) == 1);
	assert(addparticipant(alist, "bogdan", "a", 60) == 1);
	darray* tosort = createlist();
	mysort(alist, tosort, greaterthan, 0);
	assert(getscore(getparticipant(tosort, 0)) == 60);
	assert(getscore(getparticipant(tosort, 1)) == 70);
	assert(getscore(getparticipant(tosort, 2)) == 91);
	assert(getscore(getparticipant(tosort, 3)) == 92);
	deletelist(tosort);
	darray* tosort2 = createlist();
	mysort(alist, tosort2, cmpname, 0);
	assert(strcmp(getfname(getparticipant(tosort2, 0)), "bogdan") == 0);
	assert(strcmp(getfname(getparticipant(tosort2, 1)), "paul") == 0);
	assert(strcmp(getfname(getparticipant(tosort2, 2)), "razvan") == 0);
	assert(strcmp(getfname(getparticipant(tosort2, 3)), "silviu") == 0);
	deletelist(tosort2);
	darray* tosort3 = createlist();
	mysort(alist, tosort3, cmpname, 1);
	assert(strcmp(getfname(getparticipant(tosort3, 0)), "silviu") == 0);
	assert(strcmp(getfname(getparticipant(tosort3, 1)), "razvan") == 0);
	assert(strcmp(getfname(getparticipant(tosort3, 2)), "paul") == 0);
	assert(strcmp(getfname(getparticipant(tosort3, 3)), "bogdan") == 0);
	deletelist(tosort3);

	deleterepo(alist);
}
/*runs all the tests from tests.h*/
void runtests() {
	testparticipant();
	testlist();
	testparticipanti();
	testupdate();
	testfilter();
	testsort();
}
