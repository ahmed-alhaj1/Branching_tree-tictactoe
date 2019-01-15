#ifndef _EXPER_H
#define _EXPER_H

#include<iostream>
#include"Board.h"
#include<list>
#include<vector>
using namespace std;


class Point{
	public:
	int x;
	int y;
	Point();
	Point(int x, int y);
	Point operator=(Point & rhs);
	friend std::ostream & operator<< (std::ostream & sout, const Point &pt);
	bool operator==(const Point &pt );
	

};

class Move{
	private:
	Point m_pos;
	int m_risk;
	public:
	Move();
	Move operator=(Move &mv);
	int get_risk();
	Point get_position();
	void set_position(Point pt);
	void set_risk(int risk);
	
};

class State{
	public:
	State();
	State(Board board);
	vector<Point>* available_moves();
	const State& operator=(State& rhs);
	int get_best_move();
	int num_of_moves();
	void dump();
	void fill_p1(int i,int j);
	void fill_p2(int i,int j);

	//member vars
	Board m_board;
	int best_move;
	int possible_moves;

	//vector<Point> m_pss_moves;

};


class Node{
	public:
	State m_state;
	Node();
	Node(State curr_state);
	Move get_move();
 	void print_Node();
	void initialize_branches();
	//friend void simulate(Board b1);

	//private: 
	list<Node*> *m_branches;
	int  m_data;
	Move m_move;
	//Node *parent;
		
};


#endif
