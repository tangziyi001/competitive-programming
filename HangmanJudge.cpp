//UVA 489
// Make sure that each charactor will not be processed by mutiple times
#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;
int main(){
	int round;
	while (cin >> round && round != -1){
		cout << "Round " << round << endl;
		
			char c[100000];
			char g[100000];
			int correct = 0;
			int wrong = 0;
			int solve = 0;
			int end = 0;
			cin >> c >> g;
			int gl = strlen(g);
			int cl = strlen(c);
			set<char> exi;
			for (int j = 0; j < gl; j++){
				if (exi.find(g[j]) != exi.end()){
					continue;
				}
				else{
					exi.insert(g[j]);
				}
				int get = 0;
				for (int k = 0; k < cl; k++){
					if (g[j] == c[k]){
						solve += 1;
						get = 1;
					}

				}
				
				if (get != 1){
					wrong += 1;
				}
				if (solve == cl){
					cout << "You win." << endl;
					end = 1;
					break;
				}
				if (wrong >= 7){
					cout << "You lose." << endl;
					end = 1;
					break;
				}

			}
			if (end == 1){
				continue;
			}
			else {
				cout << "You chickened out." << endl;
			}	
	}
	return 0;
}