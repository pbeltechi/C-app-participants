#pragma once
#include "repolist.h"
#include "service.h"
#include "Domain.h"
#include <stdio.h>
#include <string.h>
void printstring(char* string);
void printlist(darray* alist);
void ui_addparticipant(repo* repos);
void ui_updateparticipant(repo* repos);
void ui_deleteparticipant(repo* repos);
void ui_filter(repo* repos);
void ui_sort(repo* repos);
void ui_printmenu();
void ui_start(repo* repos);
