#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Point {
	public:
	int x;
	int y;
	Point(int x , int y){
		this->x = x;
		this->y = y;	
		};
	Point operator=(Point &pt){
		x = pt.x;
		y = pt.y;
	};


};

vector<pair<int,int> > make_pairs();

vector< pair<int,int> > make_pairs(){
	vector< pair<int,int> > m_elems;
	
	for(int i =0;i < 3;i++){
		for(int j = 0;j < 3; i++){
			pair<int,int> slot;
			slot.first = i; slot.second = j;	
			m_elems.push_back(slot);
		}
	}

}


int main(){
	Point pt = Point(5,7);
	Point pt1 = pt;
	cout <<"welcome to testing " << pt1.x << pt1.y << endl;
	vector< pair<int,int> > elems;
	elems = make_pairs();
	cout << "elements size = "<< elems.size() << endl;
	for(int i = 0 ; i < elems.size() ; i++){
		cout<< elems[i].first << elems[i].second  << "\n";
	}

return 0;
}
