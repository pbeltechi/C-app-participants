#pragma once
#include "repolist.h"
#include "repository.h"
#include "Domain.h"
#include "service.h"
#include <assert.h>
#include <string.h>
/*tests the creating and deleting a participant
also getfname,lname and score */
void testparticipant();
/*tests the append and deleting the dynamic list*/
void testlist();
/*tests the addparticipant and deleteparticipant functionalities*/
void testparticipanti();
/*tests the update participant functionality*/
void testupdate();
/*tests the filter functionality*/
void testfilter();
/*tests the sort functionality*/
void testsort();
/*runs all the tests from tests.h*/
void runtests();
