#include"Board.h"


Board::Board(int rsize){
	m_size =  rsize;
	m_empty_pos = 9;
	//pr1 = 1;
	//pr2 = 2;
	//printf("initial the board rsize = %d  \n", m_size);
	board = new char *[m_size];
	for(int i = 0 ; i < m_size; i++){
		board[i] = new char[m_size];
		//board[i] = NULL;

	}
	
	for(int i= 0 ; i < rsize; i++){
		for(int j = 0 ; j < rsize; j++ ){
				board[i][j] = empty;
				//printf("| %c", board[i][j]);
			}
		//printf("| \n");
		
	}
	
}


Board::Board(Board &other){
	m_empty_pos = other.m_empty_pos;
        turn = other.turn;
        m_size = other.m_size;
        setpair(new_move);
        board = new char*[m_size];
        for(int i = 0; i < m_size; i ++){
                board[i] = new char[m_size];
        }
        for(int i = 0; i < m_size; i++ ){
                for(int j = 0; j < m_size; j++){
                        board[i][j] = other.board[i][j];
                }

        }

}
const Board& Board::operator=(Board & rhs){
	clear();
	m_empty_pos = rhs.m_empty_pos;
	turn = rhs.turn;
	m_size = rhs.m_size;
	setpair(new_move);
	board = new char*[m_size];
	for(int i = 0; i < m_size; i ++){
		board[i] = new char[m_size];
	}
	for(int i = 0; i < m_size; i++ ){
		for(int j = 0; j  < m_size; j++){
			board[i][j] = rhs.board[i][j];
		}

	}

}	


void Board::setpair(pair<int ,int> position){
	new_move.first = position.first;
	new_move.second= position.second;

}
Board::~Board(){
	clear();

}
void Board::clear(){
	for(int i = 0 ; i < m_size; i++){
		delete board[i];
	}
	delete board;
	

};
bool Board::is_empty(int i, int j ){
		return (board[i][j] == empty) ? true :false;

	}	
void Board::dump(){
	//printf("I am at dump m_size = %d \n", m_size);
	printf("-------------\n");
	for(int i = 0 ; i  < m_size; i++ ){
		for(int j = 0 ; j < m_size ; j++ ){
			printf("| %c " , board[i][j] );
		}
		printf("| \n");
	}
	printf("-------------\n");

}

	

bool Board::check_full(){
	for(int i=0; i < m_size; i ++){
		for(int j  =0;j< m_size; j++){
			if(board[i][j] == empty) return false;
		}
	}
	return true;
}


int Board::num_of_possible_moves(){
	return m_empty_pos;
}
pair<int ,int> Board::dissolve_pos(int slot){
	//pair<int, int> pos;
	pair<int , int > pos;
	switch(slot){
		case 1: 
			pos.first = 0;
			pos.second = 0;
			return pos;
		case 2: 
			pos.first = 0;
			pos.second = 1;
			return pos;
		case 3:
			pos.first = 0;
			pos.second= 2;
			return pos;
		case 4:
			pos.first =1 ;
			pos.second  = 0;
			return pos;
	
		case 5: 
			pos.first =1;
			pos.second = 1;
			return pos;
		case 6:
			pos.first =1;
			pos.second =2;
			return pos;
		case 7:
			pos.first =2;
			pos.second = 0;
			return pos;
		case 8: 
			pos.first = 2;
			pos.second = 1;
			return pos;
		case 9 :
			pos.first =2;	
			pos.second =2;
			return pos;


	}


}
int Board::combine_pos(pair<int,int> pos){

	if((pos.first = 0) && (pos.second == 0 )) return 1;
	if((pos.first = 0) && (pos.second == 1 )) return 2;
	if((pos.first = 0) && (pos.second == 2 )) return 3;
	if((pos.first = 1) && (pos.second == 0 )) return 4;
	if((pos.first = 1) && (pos.second == 1 )) return 5;
	if((pos.first = 1) && (pos.second == 2 )) return 6;
	if((pos.first = 2) && (pos.second == 0 )) return 7;
	if((pos.first = 2) && (pos.second == 1 )) return 8;
	if((pos.first = 2) && (pos.second == 2 )) return 9;


}

char** Board::getBoard(){
	return board;

}
int Board::getNewPos(){


}

int Board::warn_p2_win(){
	int risk[4] = { check_horiz(), check_vertical(), check_left_diagnal() ,check_right_diagnal()};
	int risk_degree = 0 ;
	//resign action;
	int loc= 12;
	for(int i = 0 ; i < 4 ; i++){
		if(risk[i] > 0 ){
			loc = i;
			risk_degree++;
		}
	}
	// resign is best action 
	if(risk_degree > 1) return 8;
			
	return loc; 	
}
int Board::check_horiz(){
	int hpr1 = 0, hemp=0;
	for(int i = 0; i < m_size ; i ++){
		for(int j = 0; j < m_size ; j++){
			if(board[i][j] == p1) hpr1++;
			if(board[i][j] == empty) hemp++;  
			if(hpr1 == 2 && hemp ==1 ) return 1; 		
		}
		hpr1 = 0;
		hemp = 0;
	}
	return 0;
}
	//check vertically
int Board::check_vertical(){
	int vpr1 =0, vemp=0;
	for(int i = 0 ;i < m_size; i++){
		for(int j = 0 ; j < m_size; j++){
			if(board[j][i] ==  p1)++vpr1;
			if(board[j][i] == empty) ++vemp;
			if(vpr1 ==2 && vemp == 1) return 2;
	
		}
		vpr1 = 0;
		vemp =0;
	}
	return 0;
}
	// check left diagonal 
int Board::check_left_diagnal(){
	int ldpr1 = 0, ldemp = 0; 
	for(int i = 0, j = 0 ; i < m_size ; i++, j++){
		if(board[i][j] == p1) ldpr1++;
		if(board[i][j] == empty) ldemp++;
		if(ldpr1 == 2 && ldemp == 1) return 3;
	}
	return 0;
	}
	
	// check right diagnoal
int Board::check_right_diagnal(){
	int rdpr1 = 0, rdemp = 0; 
	for(int i = 0, j =2; i < m_size ; i++, j--){
		if(board[i][j] == p1)rdpr1++;
		if(board[i][j] == empty )rdemp++;
		if(rdpr1 == 2 && rdemp == 1 ) return 4;
	}
	// no threat
	return 0;

}


int Board::check_draw(){
	//check horizonatally
	int hpr1 = 0, hpr2=0;
	bool horiz_draw =0;
	for(int i = 0; i < m_size ; i ++){
		if(board[i][0] == p1 || board[i][1] || p1 || board[i][2] == p1)
			hpr1++;
		if(board[i][0] == p2 || board[i][1] || p2 || board[i][2] == p2)
			hpr2++;  		

	}
	if(hpr1 == 3 && hpr2 ==3 ) horiz_draw= 1; 
	//check vertically

	int vpr1 =0, vpr2=0;
	bool ver_draw =0;
	for(int i = 0 ;i < m_size; i++){
		if(board[0][i] == p1 || board[1][i] == p1 || board[2][i] == p1)
			vpr1++;
		if(board[0][i] == p2 || board[1][i] == p2 || board[2][i] == p2)
			 vpr2++;
			
		}
	if(vpr1 ==3 && vpr2 == 3) ver_draw = 1;


	// check left diagonal 
	int ldpr1 = 0, ldpr2 = 0; 
	bool ld_draw = 0;
	if(board[0][0] == p1 || board[1][1] == p1 || board[2][2] == p1)
			ldpr1++;
	if(board[0][0] == p2 || board[1][1] == p2 || board[2][2] == p2)
			ldpr2++;
	if(ldpr1 == 1 && ldpr2 == 1) ld_draw = 1;
	// check right diagnoal
	int rdpr1 = 0, rdpr2 = 0; 
	bool rd_draw = 0;
	if(board[0][2] == p1 || board[1][1] == p1 || board[2][0] == p1)
			rdpr1++;
	if(board[0][2] == p2 || board[1][1] == p2 || board[2][0] == p2)
			 rdpr2++;
	if(rdpr1 == 1 && rdpr2 == 1 ) rd_draw = 1;
	// draw check
	return (horiz_draw == 1 && ver_draw == 1 && ld_draw ==1 && rd_draw ==1 )? 1: 0;
	
}
void Board::p1_move(){
	int pos =0;
	bool empty_flag;
	bool range_flag;
	pair<int, int> bpos;
	do {
	 	printf("player 1 please enter the postion to place into \n");
		cin>> pos;
		range_flag = (pos > 0 && pos < 10 ) ? true : false;
		if(!!range_flag) bpos = dissolve_pos(pos);
		empty_flag = (board[bpos.first][bpos.second] == empty)? true : false;
	}while( range_flag == false || empty_flag == false);

	board[bpos.first][bpos.second] =  p1;
		

	}

void Board::p2_move(){
	int pos =0;
	bool empty_flag;
	bool range_flag;
	
	pair<int, int> bpos;
	do {
	 	printf("player 2 please enter the postion to place into \n");
		cin>> pos;
		range_flag = (pos > 0 && pos < 10 ) ? true : false;
		if(!!range_flag) bpos = dissolve_pos(pos);
		empty_flag = (board[bpos.first][bpos.second] == empty)? true : false;
		
	}while( range_flag == false || empty_flag == false);

	board[bpos.first][bpos.second]= p2;

	}


int Board::check_win(){
	//check horizonatally
	for(int i = 0; i < m_size ; i ++){
		if(board[i][0] == p1 && board[i][1] == p1 && board[i][2] == p1)
			return pr1;
		if(board[i][0] == p2 && board[i][1] == p2 && board[i][2] == p2)
			return pr2;  		

	}
	//check vertically
	for(int i = 0 ;i < m_size; i++){
		if(board[0][i] == p1 && board[1][i] == p1 && board[2][i] == p1)
			return pr1;
		if(board[0][i] == p2 && board[1][i] == p2 && board[2][i] == p2)
			return pr2;
			
		}
	// check right diaganally
	int prev1 =0, prev2=0;
		
	for(int i =0, j = 0; i< m_size; i++, j++){
		prev1= (board[i][j] ==p1) ? ++prev1 : prev1 ;
		if(prev1 == 3) return pr1;
		
		prev2 = (board[i][j]== p2)? ++prev2 : prev2;
		if(prev2 == 3 )return pr2;
		}
	//check left diagonally
	int pv1 = 0, pv2 =0;
	for(int i = 0,j =2; i < 3; i++, j-- ){
		pv1= (board[i][j] ==p1) ? ++pv1 : pv1 ;
			if(pv1 == 3) return pr1;
		
		pv2 = (board[i][j]== p2)? ++pv2 : pv2;
			if(pv2 == 3 )return pr2;
		}
	//no winner yet 
		return 0;

		
	}


void Board::fill_p2(int i,int j){
	board[i][j] = p2;

}
void Board::fill_p1(int i,int j){
	board[i][j] = p1;
}
void Board::print_win_msg(int pr){
		printf("pr = %d ");
		if(pr == pr1){
			printf("congratulation player 1 u made it \n");
		}else{
			printf("congratulation player 2 u made it \n");
		}
		
	}

void Board::print_full(){
			printf("resul is a draw. there is no winner both u all sucks \n");
	}


void Board::indicator(int x){
	if(x==1) printf("pay attention to horizonal slot\n");
	if(x==2) printf("pay attention to vertical slot\n");
	if(x==3) printf("pay attention to right diagonal\n");
	if(x==4) printf("pay attention to left diagonal\n");

}

void Board::run_game(){
	bool sentinal = true;
	int counter = 0, res;
	printf("##### Weclome to the TicToeTac world #####\n");
	
	while(!!sentinal){
		dump();
		if(counter % 2 == 0 ){
			p1_move();
			m_empty_pos--;
			if(m_empty_pos < 3) {
				if(!!check_draw()) {
					print_full();
					break;	
				}
			}
			dump();
			res  = check_win();
			printf("res = %d \n", res);
			if(res > 0) {
				print_win_msg(res);
				break;
			}
		
			if(!!check_full()){
				sentinal = false;
				print_full();
				break;
			}	
			counter++;
		}
		if(counter % 2 != 0){
			if(warn_p2_win() != 0){
				indicator(warn_p2_win());
			}
			p2_move();
			m_empty_pos--;
			if(m_empty_pos < 3){
				if(!! check_draw()){
					print_full();
					break;
				}
			}

			dump();
			res = check_win();
			printf("res = %d \n",res );
			if(res > 0 ){
				printf("res = %d \n",res );
				print_win_msg(res);
				break;
			}
			if(!!check_full()){
				sentinal = false;
				print_full();
				break;
			}
			counter++;
		}


	}

}


