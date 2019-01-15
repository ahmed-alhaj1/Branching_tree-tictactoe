//#include<iostream>
//#include<vector>
#include"exper.h"
using namespace std;


vector<Point>* get_points(){
	vector<Point>* m_points = new vector<Point>();
	int x = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0 ; j < 3; j ++){
			Point pt(i,j);
			m_points->push_back( pt);
			x++;
			
			
		}
	}
	return m_points;

}


int main(){
	Point pt(3,2);
	cout <<pt.x <<" " << pt.y << endl;
	
	vector<Point> *m_points = new vector<Point>();
	m_points = get_points();
	vector<Point>::iterator it;
	for(it = m_points->begin(); it !=  m_points->end() ; it++){
			Point pt = *it;
			cout <<pt.x << pt.y<< endl;
		}

	return 0;
}
