#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int strtoint(string str);

int randomness(int range);

void effect(void);

void show_start(void);

void show_next(void);

void show_round(int round);

void show_kill(int row, int col, string soldiers1_name, string soldiers2_name);

void show_kill(int row, int col, string soldiers1_name, char army_name, int weapon);

bool isGameover(int alive_A, int alive_B, int alive_C, int alive_D);

void printLine(int mapSize, int game_mode);


#endif
