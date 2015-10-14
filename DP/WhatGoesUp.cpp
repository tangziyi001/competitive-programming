/*
 *	UVA 481
 *	Created by Ziyi Tang
 *	Longest Increasing Subsequence (Non-consecutive), D&C algorithm, Track LIS
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
#define INF 1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	vpi all; // Value; Index in a
	vpi a;   // Value; Prior
	int count = 0;
	int length = 0;
	string line;
	int tmp;
	while (getline(cin,line) && line != ""){
		tmp = stoi(line);
		if (count == 0){
			a.push_back(make_pair(tmp,-1));
			length = 1;
			all.push_back(make_pair(tmp, length-1));
			count += 1;
		}
		else if(tmp <= all[count-1].first){
			int ttmp = count-1;
			while (tmp <= all[ttmp].first){
				if (ttmp < 0){
					break;
				}
				ttmp--;
			}
			//cout << "rep" << endl;
			if (ttmp < 0){
				a.push_back(make_pair(tmp,-1));
				
			}
			else{
				a.push_back(make_pair(tmp,all[ttmp].second));
			}
			length++;
			all[ttmp+1] = make_pair(tmp,length-1);
			//cout << "tt" << ttmp << endl;
		}
		else{
			a.push_back(make_pair(tmp,all[count-1].second));
			length++;
			all.push_back(make_pair(tmp,length-1));
			count += 1;
			//cout << "append" << endl;
		}
	}
	cout << count << endl;
	cout << "-" << endl;
	if (count != 0){
		vi re;
		int t = all[count-1].second;
		re.push_back(a[t].first);
		while (a[t].second != -1){
			t = a[t].second;
			re.push_back(a[t].first);
		}
		for (auto it = re.end()-1; it != re.begin()-1; it--){
			cout << *it << endl;
		}
	}
	





	return 0;
}
