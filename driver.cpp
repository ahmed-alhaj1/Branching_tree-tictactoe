//#include"Board.h"
#include"Node.h"

/*
void make_safe_move( Board &b1 , int risk, Node *root){
	switch(risk){
	case 1:
		//if(b1.is_empty(0,0) != b1.is_empty() && board[0][1])
	case 2:
	case 3:
	case 4:


	}

}
*/
int simulate(Board &b1){
	
	
	State state(b1);
	Node * root = new Node(state);
	root->initialize_branches();
	vector<Move> average_move;
	list<Node*>::iterator it ;
	cout <<"####### things are alright ###### " << endl;
	int i =0;
	for(it = root->m_branches->begin(); it != root->m_branches->end(); it++){
		if( (*it)->get_move().get_risk() == 8){
		 	cout <<"@@@@ I am going to resign fuck this game @@@@" << endl;
			return 0;
		}
		Move mv = (*it)->get_move();
		if( mv.get_risk() == 12 /*mv.get_risk() == 0 || mv.get_risk() == 1 || mv.get_risk() == 2 || mv.get_risk() ==3 */){
			b1.fill_p2(mv.get_position().x, mv.get_position().y);
			return 1;
		}else{
		average_move.push_back(mv);
		}
			//if( mv.get_risk() == 0 mv.get_position() == Point(1,1) || mv.get_position == Point(2,0)){
			//b1.fill_p2(pt.x, pt.y);
			//return 1;
	
			//}else{
			//	average_move.push_back(pt);
			//}
		//}else{
		///	return 0;	
			
		//}
		//i++;

	}
	cout <<"things still alright 2 " << endl;
	cout << average_move.size()  << endl;
	vector<Move>::iterator itx ;
	
	for(itx = average_move.begin() ; itx != average_move.end() ; itx++){
		Move mv = (*itx);
		Point pt = mv.get_position();
		if(pt.x< 2 && pt.y < 2 ){
			if(b1.board[pt.x+1][pt.y] =='X' && b1.is_empty(pt.x, pt.y)){
				b1.fill_p2(pt.x, pt.y);
				return 1;
			}else if(b1.board[pt.x][pt.y+1]== 'X' && b1.is_empty(pt.x,pt.y)){
				b1.fill_p2(pt.x,pt.y);	
				return 1;
			}
		}else if(pt.x == 0 && pt.y == 0 ){
			if(b1.board[pt.x+1][pt.y+1] =='X' && b1.is_empty(pt.x, pt.y)){
				b1.fill_p2(pt.x,pt.y);
				return 1;
			}else if(b1.board[pt.x+1][pt.y] =='X' && b1.is_empty(pt.x,pt.y)){
				b1.fill_p2(pt.x,pt.y);
				return 1;
			}
		}else{
			if(b1.board[pt.x-1][pt.y] == 'X' && b1.is_empty(pt.x,pt.y)){
				b1.fill_p2(pt.x, pt.y);
				return 1;
			}else if(b1.board[pt.x][pt.y+1] =='X' && b1.is_empty(pt.x,pt.y)){
				b1.fill_p2(pt.x,pt.y);
				return 1;
			}
		}
	}
	cout <<"############## Something wrong happened ################" << endl;
	return 0;
}

void run_game(Board board){
        bool sentinal = true;
        int counter = 0, res;
        printf("##### Weclome to the TicToeTac world #####\n");
	board.dump();
        while(!!sentinal){
                //board.dump();
                if(counter % 2 == 0 ){
                        board.p1_move();
                        board.m_empty_pos--;
                        if(board.m_empty_pos < 3) {
                                if(!!board.check_draw()) {
                                        board.print_full();
                                        break;
                                }
                        }
                        board.dump();
                        res  = board.check_win();
                        printf("res = %d \n", res);
                        if(res > 0) {
                                board.print_win_msg(res);
                                break;
                        }

                        if(!!board.check_full()){
                                sentinal = false;
                                board.print_full();
                                break;
                        }
                        counter++;
                }
                if(counter % 2 != 0){
                        //if(board.warn_p2_win() != 0){
                        //        board.indicator(board.warn_p2_win());
                        //}
                        //board.p2_move();
			cout <<"I am about to simulate" << endl;
			int x = simulate(board);
			if(x == 0) break;
                        board.m_empty_pos--;
			board.dump();//
                        if(board.m_empty_pos < 3){
                                if(!! board.check_draw()){
                                        board.print_full();
                                        break;
             }
                        }

                        //board.dump();
                        res = board.check_win();
                        printf("res = %d \n",res );
                        if(res > 0 ){
                                printf("res = %d \n",res );
                                board.print_win_msg(res);
                                break;
                        }
                        if(!!board.check_full()){
                                sentinal = false;
                                board.print_full();
                                break;
                        }
                        counter++;
                }


        }

}


int main(){
	printf("you have made it congrat \n");
	Board B1;
	//B1.run_game();
	State state(B1);
	Node *root = new Node(state);
	run_game(B1);
	Board B2;
	B2 = B1;	
	B2.dump();
	
	


}
