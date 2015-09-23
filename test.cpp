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

int main(){
	double a =  1.5555555555;
	printf("%.5f\n", a);
}