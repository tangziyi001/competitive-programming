#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
typedef int D;
set<D> a;
class Node{
	int label;
	public:
		Node(int a){label = a;}
		void print() {cout << label <<endl;}

		void set(int);
};
void Node::set(int num){
	label = num;
}

int check(int a, int b){
	if (a == b){
		return 1;
	}
	else{
		return 1 + check(a+1,b);
	}	


}
int main(){
	map<int,int> t;
	t[1] = 10;
	t[2]= 6;
	t[3] = 4;
	priority_queue<pair<int,string>, set<pair<int,string> >, greater<pair<int,string> > > a;
	
	a.push(make_pair(4,"ahu"));
	a.push(make_pair(6,"hadh"));
	a.push(make_pair(8,"auid"));
	cout << a.top().second << endl;
}