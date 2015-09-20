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
	vector<int> a;
	cout << a[10] << endl;
}