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
	string a;
	while (getline (cin, a)){
	if (a == ""){
		cout << "blank" << endl;
	}else{
		cout << "not" << endl;
		int idx = a.find(' ');
		string one;
		string two;
		one = a.substr(0, idx + 1);
		two = a.substr(idx + 1, a.size() - idx);
		cout << idx << endl;
		cout << one << endl;
		cout << two << endl;
		cout << endl;

	}
}
}