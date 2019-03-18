#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "UI.h"
#include "repolist.h"
#include "repository.h"
#include "validator.h"
#include "tests.h"
int main(){
	runtests();

	repo* repos = createrepo();
	ui_start(repos);
	deleterepo(repos);
	_CrtDumpMemoryLeaks();
	return 0;
}
