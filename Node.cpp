#include<iostream>
#include"Node.h"

#define poss_branches(x) ((x)-(1))

const int len =3;
Point::Point(){
	this->x = -1;
	this->y = -1;
}
Point::Point(int x, int y){

	this->x = x;
	this->y = y;
}


Point Point::operator=(Point &pt){
	x= pt.x;
	y= pt.y;
	return *this; 
}


std::ostream& operator<<(std::ostream &sout, const Point &pt){

	sout<< "(" << pt.x << ", " << pt.y << ")";

}

bool Point::operator==(const Point &pt){
		return ((x == pt.x) && (x == pt.y));
	} 
//###################################################################
//###################################################################

Move::Move(){
	m_pos ;
	m_risk = 0;
}
Move Move::operator=(Move &mv){
	m_pos = mv.m_pos;
	m_risk = mv.m_risk;
}
int Move::get_risk(){
	return m_risk;
}

Point Move::get_position(){
	return m_pos;
}
void Move::set_position(Point pt){
	m_pos = pt;

}
void Move::set_risk(int risk){
	m_risk = risk;
}
//##################################################################
//##################################################################
State::State(){
	m_board;
	possible_moves;
	best_move = 0;

}

//State::board_state(){
	
//}

State::State(Board board){
	m_board = board;
	possible_moves = m_board.num_of_possible_moves();
	best_move = 0;
}
const State& State::operator=(State& rhs){
	m_board = rhs.m_board;
	//printf("board is fine \n");
	possible_moves = rhs.possible_moves;
	
	best_move = rhs.best_move;
	printf("board is fine \n");
	//eturn *this;
	
}
int State::num_of_moves(){
	return possible_moves;

}
vector<Point>* State::available_moves(){
	cout <<"I am at available moves " <<endl;
	vector<Point> *m_pss_moves = new vector<Point>();
	for(int i = 0 ; i < len;i++){
		for(int j = 0; j < len ;j++){
			if(m_board.is_empty(i,j)){
				Point slot(i,j);
				m_pss_moves->push_back(slot);
				
			}
		}
	}
	return m_pss_moves;
}

int State::get_best_move(){
	return m_board.warn_p2_win();
	
}
void State::dump(){
	m_board.dump();
	}

void State::fill_p2(int i, int j){
	m_board.fill_p2( i , j);
}
void State::fill_p1(int i, int j){
	m_board.fill_p1( i, j);
}
//##############################################
//#############################################



Node::Node(){
	m_branches = new list<Node*>();
	m_state;
	m_move;
	m_move.set_risk(0);
	

}
Node::Node(State curr_state){
		printf("I am at initialze the state\n");
		m_state = curr_state;
		m_move ;
		//parent = NULL;
		m_branches = new list<Node*>();

		cout <<m_move.get_position().x <<" " << m_move.get_position().y << endl;
		
	}


Move Node::get_move(){
		return m_move;

	}
void Node::initialize_branches(){
		cout <<"_____I am initilaize m_branches ____" << endl;
		vector<Point> *pss_moves = new vector<Point>();
		 pss_moves = m_state.available_moves();

		vector<Point>::iterator it;
		for(it = pss_moves->begin() ;it != pss_moves->end(); it++){
			
			Point pt = *it;
			State new_state(m_state.m_board);
			new_state.fill_p2(pt.x, pt.y);
			Node* curr = new Node(new_state);
			//Move new_move; 
			//parent  = *this;
			curr->m_move.set_position(pt);
			curr->m_move.set_risk(curr->m_state.m_board.warn_p2_win());
			//curr->m_move = pt;
			curr->m_state.dump();
			m_branches->push_back(curr);
		}
}

//int Node::find_best_move(){
//	list<Node*>::iterator it;
//	for(it = m_branches.begin() ; it != m_bracnhes.end(); it++ ){
//		}
//}


