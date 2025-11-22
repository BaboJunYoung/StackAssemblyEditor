#pragma once
#define MAX 50

struct Stack {
	int value[MAX];
	int top;
};

void init_stack(struct Stack* s);

int is_empty(struct Stack* s);

int is_full(struct Stack* s);

int push(struct Stack* s, int value);

int pop(struct Stack* s, int* value);

