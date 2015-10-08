//UVA 10194
// Multifield-sort, to lower case.
// Trap: Lexicographic order should change all words to lower case first.
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<pair<string,vector<int> > > vp;

bool com(pair<string, vector<int> > a, pair<string, vector<int> > b){
	if ((a.second)[0] != (b.second)[0]){
		return (a.second)[0] > (b.second)[0];
	}
	else if ((a.second)[1] != (b.second)[1]){
		return (a.second)[1] > (b.second)[1];
	}
	else if ((a.second)[2] - (a.second)[3] != (b.second)[2] - (b.second)[3]){
		return (a.second)[2] - (a.second)[3] > (b.second)[2] - (b.second)[3];
	}
	else if ((a.second)[2] != (b.second)[2]){
		return (a.second)[2] > (b.second)[2];
	}
	else if ((a.second)[4] != (b.second)[4]){
		return (a.second)[4] < (b.second)[4];
	}
	else{
		string one = a.first;
		string two = b.first;
		int sz1 = one.size();
		int sz2 = two.size();
		for (int i = 0; i < sz1; i++){
			if (one[i] <= 'Z' && one[i] >= 'A'){
				one[i] = one[i] - ('Z' - 'z');
			}
		}
		for (int i = 0; i < sz2; i++){
			if (two[i] <= 'Z' && two[i] >= 'A'){
				two[i] = two[i] - ('Z' - 'z');
			}
		}
		return one < two;
	}
}
using namespace std;
int main(){
	int test;
	string tmp;
	getline(cin,tmp);
	test = stoi(tmp);
	while (test--){
		map<string, vector<int> > all;
		string des;
		getline(cin,des);
		int t;
		getline(cin, tmp);
		t = stoi(tmp);
		while (t--){
			string name;
			getline(cin,name);
			vector<int> nt(6,0);
			// 0: points
			// 1: wins
			// 2: goalsco
			// 3: goalagi
			// 4: gameplay
			// 5: ties
			all[name] = nt;
		}
		
		int g;
		getline(cin,tmp);
		g = stoi(tmp);
		while (g--){
			string line;
			getline(cin,line);
			int sz = line.size();
			int pre = 0;
			string team1 = "#";
			string team2 = "#";
			int score1 = -1;
			int score2 = -1;
			for (int i = 0; i <= sz; i++){
				if (line[i] == '#'){
					if (team1 == "#"){
						team1 = line.substr(pre, i);
						pre = i + 1;
					}else{
						score2 = stoi(line.substr(pre,i));
						pre = i + 1;
					}
					
				}
				else if (line[i] == '@'){
					if (score1 == -1){
						score1 = stoi(line.substr(pre,i));
						pre = i+1;
					} 
				}
				if (i == sz){
					team2 = line.substr(pre,i);
					break;
				} 
			}
			all[team1][2] += score1;
			all[team1][3] += score2;
			all[team2][2] += score2;
			all[team2][3] += score1;
			all[team1][4] += 1;
			all[team2][4] += 1;
			if (score1 > score2){
				all[team1][0] += 3;
				all[team1][1] += 1;
			}else if (score1 < score2){
				all[team2][0] += 3;
				all[team2][1] += 1;
			}else{
				all[team1][0] += 1;
				all[team2][0] += 1;
				all[team1][5] += 1;
				all[team2][5] += 1;
			}


		}
		vp s;
		for (auto it = all.begin(); it != all.end(); it++){
			s.push_back(*it);
		}
		sort(s.begin(),s.end(),com);
		cout << des << endl;
		int num = 1;
		for (auto it = s.begin(); it != s.end(); it++){
			cout << num << ") " << (*it).first << " ";
			printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",((*it).second)[0], 
			((*it).second)[4], ((*it).second)[1], ((*it).second)[5],((*it).second)[4]-((*it).second)[5]-((*it).second)[1], 
			((*it).second)[2] - ((*it).second)[3], ((*it).second)[2], ((*it).second)[3]);
			num++;
		}
		if (test != 0){
			cout << endl;
		}
	}



	return 0;
}