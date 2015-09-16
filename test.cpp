#include <iostream>
#include <string>
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

int main(){
	Node a(1);
	a.set(4);
	a.print();
}