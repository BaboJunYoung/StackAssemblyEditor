#include <stdio.h>
#include <windows.h>
#include "Screen.h"
#include "Menu.h"

#define YELLOW (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define CYAN (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY)


void createfile_setup(struct File files[])
{
	system("cls");

	char* txt = "Input the name of file you create";

	struct Screen screen = get_screen();

	set_console_position(screen.columns / 2 - (strlen(txt)) / 2, screen.rows / 2 - 2);
	printf("%s", txt);

	set_console_position(screen.columns / 2 - 10, screen.rows / 2 + 2);
	printf("----------------------");

	set_console_position(screen.columns / 2 - 10, screen.rows / 2 + 1);

	int empty_index = 0;
	for (int i = 0; i < 10; i++) {
		if (strstr(files[i].name, "undefined") != NULL) {
			empty_index = i; 
			break;
		}
	}

	scanf_s("%s", files[empty_index].name, 10);
}


void deletefile_setup(struct File files[]) {
	system("cls");
	struct Screen screen = get_screen();

	char* txt = "Select the file you want to delete";

	set_console_position(screen.columns / 2 - (strlen(txt) / 2), screen.rows / 2 - 2);
	printf("%s", txt);
}


void selectfile_setup(struct File files[]) {
	system("cls");

	char* txt = "List of file";

	struct Screen screen = get_screen();

	set_console_position(screen.columns / 2 - (strlen(txt) / 2), screen.rows / 2 - 2);
	set_text_color(CYAN);
	printf("%s", txt);

	int selected = 0;

	while (1) {
		int max_size = 10;

		for (int i = 0; i < 10; i++) {
			if (strstr(files[i].name, "undefined") != NULL) { 
				max_size = i;
				break;
			} // undefined가 포함되면 반복 중지

			set_console_position(screen.columns / 2 - (strlen(txt) / 2), screen.rows / 2 + (i));
			if (selected == i) set_text_color(YELLOW);

			printf("%d. %s.asm", i + 1, files[i].name);

			set_text_color(WHITE);
		}

		int ch = _getch();

		if (ch == 224) { // 특수키 (방향키 등)
			ch = _getch();

			if (ch == 'H' && selected > 0) selected--; // UP

			else if (ch == 'P' && selected < max_size - 1) selected++; // DOWN
		}
		else if (ch == 13) { // Enter
			break;
		}
		else if (ch == 27) { // ESC
			break;
		}
	}
}