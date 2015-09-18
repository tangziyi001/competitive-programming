// UVA 12356
// Gist: Using two arrays to maintain the left and the right survivor respectively for each buddy.
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int main(){
	int num, loss;
	while (cin >> num >> loss && num != 0){
		int l[100001];
		int r[100001];
		l[0] = -1;
		r[0] = -1;
		for (int i = 1; i <= num; ++i){
			l[i] = i - 1;
			r[i] = i + 1;
		}
		for (int i = 0; i < loss; ++i){
			int left, right;
			cin >> left >> right;
			int left_sur = l[left];
			int right_sur = r[right];
			l[right_sur] = left_sur;
			r[left_sur] = right_sur;
			if (left_sur <= 0){
				cout << "* ";
			}
			else{
				cout << left_sur << " ";
				
			}
			if (right_sur >= num + 1){
				cout << "*" << endl;
				
			}
			else{
				cout << right_sur << endl;
			}
		}
		cout << "-" << endl;
	}



}
// Time Limit Exceeded
// int main(){
// 	int num, loss;
// 	while(cin >> num >> loss && num != 0){
// 		vector<char*> interval;
// 		vector<char*> :: iterator it;
// 		for (int i = 0; i < loss; ++i){
// 			int left, right;
// 			cin >> left >> right;
// 			int combine = 0;
// 				for (it = interval.begin(); it != interval.end(); ++it){
// 					if (right == (*it)[0] - 1){
// 						(*it)[0] = left;
// 						right = (*it)[1];
// 						combine = 1;
// 					}
// 					else if (left == (*it)[1]+ 1){
// 						(*it)[1] = right;
// 						left = (*it)[0];
// 						combine = 1;
// 					}
// 				}
// 				if (combine == 0){
// 					char dead[] = {left,right};
// 					interval.push_back(dead);
// 				}
// 				if (left == 1 && right == num){
// 					cout << "* *" << endl;
// 				}
// 				else if(left == 1){
// 					cout << "* " << right + 1 << endl;
// 				}
// 				else if(right == num){
// 					cout << left - 1 << " *" << endl;
// 				}
// 				else{
// 					cout << left - 1 << " " << right + 1 << endl;
// 				}				
// 		}
// 		cout << "-" << endl;
// 	}
// 	return 0;
// }

// Time Limit Exceeded
// int main(){
// 	int num, loss;
// 	while (cin >> num >> loss && num != 0){
// 		int line[num];
// 		for (int i = 0; i < num; ++i){
// 			line[i] = 1;
// 		}

// 		for (int i = 0; i < loss; ++i){
// 			int left;
// 			int right;
// 			cin >> left >> right;
// 			for (int j = left - 1; j <= right - 1; ++j){
// 				line[j] = 0;
// 			}
// 			int left_sur = -1;
// 			int right_sur = -1;
// 			for (int k = left - 2; k >= 0 ; --k){
// 				if (line[k] == 1){
// 					left_sur = k + 1;
// 					break;
// 				}
// 			}
// 			for (int t = right - 1 + 1; t <= num - 1; ++t){
// 				if (line[t] == 1){
// 					right_sur = t + 1;
// 					break;
// 				}
// 			}
// 			if (left_sur == -1){
// 				cout << "* "; 
// 			}
// 			else{
// 				cout << left_sur << " ";
// 			}
// 			if (right_sur == -1){
// 				cout << "*" << endl;
// 			}
// 			else{
// 				cout << right_sur << endl;
// 			}

// 		}
// 		cout << "-" << endl;
// 	}




// 	return 0;
// }

