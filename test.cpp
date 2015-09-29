#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
int re = check(1,10);
cout << re << endl;
}