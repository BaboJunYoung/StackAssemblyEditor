#pragma once
#include <stdio.h>
#include <windows.h>
#include "Screen.h"

struct File {
    char name[20];
    char code[100][1000];
};


void createfile_setup(struct File files[]);

void deletefile_setup(struct File files[]);

void selectfile_setup(struct File files[]);
