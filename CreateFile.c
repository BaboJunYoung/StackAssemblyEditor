#include <stdio.h>
#include <windows.h>
#include "Screen.h"
#include "CreateFile.h"


void createfile_setup(struct File files[])
{
	system("cls");

	char* txt = "Input the name of file you create";

	struct Screen screen = get_screen();
	set_console_position(screen.columns / 2 - (strlen(txt)) / 2, screen.rows / 2 - 2);

	printf("%s", txt);
}
