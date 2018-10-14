#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);

//IsWin
//'X'����Ӯ
//'0'���Ӯ
//'Q'ƽ�� 
//''����
char IsFull(char board[ROW][COL], int row, int col);



#endif //GAME_H__