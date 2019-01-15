#ifndef _Board_H
#define _Board_H


#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;
class Board{

	public:
	int m_empty_pos;
	char **board;
	const char p1  =  'X';
	const char p2  =  'O';
	char empty = ' ';
	const int pr1 =1;
	const int pr2 =2;
	int turn;
	int m_size; 
	pair<int, int >new_move;
	
	//public:
	void indicator(int x);
	void fill_p2(int j , int i);
	void fill_p1(int j ,  int i);
	int num_of_possible_moves();
	
	void setpair(pair<int,int> position);
	void clear();
	int check_draw();
	int warn_p2_win();
	Board(int rsize =3);
	Board (Board &other);
	~Board();
	int getNewPos();
	char** getBoard();
	pair<int,int> dissolve_pos(int slot);
	const Board& operator=(Board &rhs) ;
	int combine_pos(pair<int ,int>pos);
	void print_win_msg(int pr);
	void print_full();
	void dump();
	void p1_move();
	void p2_move();
	bool check_full();
	int check_horiz();
	int check_vertical();
	int check_left_diagnal();
	int check_right_diagnal();
	bool is_empty(int i, int j);
	int  check_win();
	void run_game();
	

};
#endif
