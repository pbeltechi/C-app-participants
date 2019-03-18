#include "UI.h"

void printstring(char* string) {
	for (unsigned int i = 0; i < strlen(string); i++) {
		printf("%c", string[i]);
	}
}
void printlist(darray* alist) {
	for (int i = 0; i < getlen(alist); i++) {
		printf("Participantul %d: ", i + 1);
		Element p = getparticipant(alist, i);
		printstring(getfname(p));
		printf(" ");
		printstring(getlname(p));
		printf(" ");
		printf("%d\n", getscore(p));
	}
}


void ui_addparticipant(repo* repos) {
	char fname[30],lname[30];
	ElementType score;
	printf("Dati prenumele: ");
	scanf_s("%s",fname, 29);
	printf("Dati numele: ");
	scanf_s("%s",lname, 29);
	printf("Dati scorul: ");
	scanf("%d",&score);
	int succeded = addparticipant(repos, fname, lname, score);
	if (succeded)
		printf("Participantul a fost adaugat cu succes!\n");
	else
		printf("Acest participant exista deja!\n");
}
void ui_updateparticipant(repo* repos) {
	char fname[30], lname[30];
	printf("Dati prenumele: ");
	scanf_s("%s", fname, 29);
	printf("Dati numele: ");
	scanf_s("%s", lname, 29);
	char newfname[30], newlname[30];
	ElementType newscore;
	printf("Dati prenumele nou: ");
	scanf_s("%s", newfname, 29);
	printf("Dati numele nou: ");
	scanf_s("%s", newlname, 29);
	printf("Dati scorul nou: ");
	scanf("%d", &newscore);
	int succeded = updateparticipant(repos, fname, lname, newfname,newlname,newscore);
	if (succeded)
		printf("Participantul a fost actualizat cu succes!\n");
	else
		printf("Acest participant nu exista!\n");
		
}
void ui_deleteparticipant(repo* repos) {
	char fname[30], lname[30];
	printf("Dati prenumele: ");
	scanf_s("%s", fname, 29);
	printf("Dati numele: ");
	scanf_s("%s", lname, 29);
	int succeded = deleteparticipantservice(repos, fname, lname);
	if (succeded)
		printf("Participantul a fost sters cu succes!\n");
	else
		printf("Acest participant nu exista!\n");
}

void ui_filter(repo* repos) {
	ElementType score;
	printf("Dati scorul: ");
	scanf("%d", &score);
	darray* filteredarray = createlist();
	filterscore(repos, filteredarray,score);
	printf("Lista participantilor filtrati dupa scorul %d:\n", score);
	printlist(filteredarray);
	printf("\n");
	deletelist(filteredarray);
}
void ui_sort(repo* repos) {
	int cmd = 0,reverse = 0;
	printf(">> 1.Sorteaza dupa scor\n>> 2.Sorteaza dupa nume\n");
	scanf("%d", &cmd);
	darray* sorted = createlist();
	if (cmd == 1) {
		printf(">>0.Crescator\n>>1.Descrescator\n");
		scanf("%d", &reverse);
		mysort(repos,sorted,greaterthan,reverse);
		printf("Lista participantilor sortati dupa scor:\n");
		printlist(sorted);
		printf("\n");
	}
	else if (cmd == 2) {
		printf(">>0.Crescator\n>>1.Descrescator\n");
		scanf("%d", &reverse);
		mysort(repos, sorted,cmpname, reverse);
		printf("Lista participantilor sortati dupa nume:\n");
		printlist(sorted);
		printf("\n");
	}
	else{
		printf("Comanda invalida!\n");
	}
	deletelist(sorted);
}

void ui_start(repo* repos)
{
	int cmd=0;
	while (1) {
		ui_printmenu();
		scanf("%d",&cmd);
		if (cmd == 0) break;
		if (cmd == 1) ui_addparticipant(repos);
		else if (cmd == 2) ui_updateparticipant(repos);
		else if (cmd == 3) ui_deleteparticipant(repos);
		else if (cmd == 4) ui_filter(repos);
		else if (cmd == 5) ui_sort(repos);
		else printf("Comanda invalida!\n");
		//printlist(plist);
	}
}
void ui_printmenu() 
{
	printf("\n1. Adauga participanti\n2. Actualizare participant existent\n3. Sterge participanti\n");
	printf("4. Permite afisearea participantilor filtrat dupa o proprietate(cei care au un scor mai mic decat o valoare data, cei cu nume incepand cu o litera data, etc)\n");
	printf("5. Permite sortarea participantilor dupa: nume sau dupa scor (crescator / descrescator)\n");
	printf("0. Exit \n\n");
}