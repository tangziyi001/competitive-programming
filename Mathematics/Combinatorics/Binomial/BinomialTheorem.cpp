/*
 *	UVA 11955
 *	Created by Ziyi Tang
 *	Create a Pascal Triangle
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

ll all[55][55];
int main(){
	all[0][0] = 1;
	all[1][0] = 1;
	all[1][1] = 1;
	REP(i,2,55){
		all[i][0] = 1;
		all[i][i] = 1;
		REP(j,1,i){
			all[i][j] = all[i-1][j-1]+all[i-1][j];
		}
	}
	
	int test;
	cin >> test;
	getchar();
	string line;
	REP(t,1,test+1){
		getline(cin,line);
		int sz = line.size();
		int idx_plus = 0;
		int idx_power = 0;
		REP(j,0,sz){
			if(line[j] == '+')
				idx_plus = j;
			if(line[j] == '^'){
				idx_power = j; break;
			}
		}
		string a = line.substr(1,idx_plus-1);
		string b = line.substr(idx_plus+1,idx_power-idx_plus-2);
		int power = stoi(line.substr(idx_power+1,sz-idx_power-1));
		if(power == 0)
			printf("Case %d: 1\n",t);
		else if(power == 1)
			printf("Case %d: %s+%s\n", t, a.c_str(), b.c_str());
		else if(power == 2)
			printf("Case %d: %s^2+2*%s*%s+%s^2\n", t, a.c_str(), a.c_str(),b.c_str(),b.c_str());
		else{
			printf("Case %d: ",t);
			REP(i,0,power+1){
				if(i == 0)
					cout << a << "^" << power;
				else if(i == power)
					cout << "+" << b << "^" << power << endl;
				else if(i == 1){
					cout << "+" << all[power][i] << "*" << a << "^" << power-i << "*" << b;
				}
				else if(i == power - 1){
					cout << "+" << all[power][i] << "*" << a << "*" << b << "^" << i;
				}
				else{
					cout << "+" << all[power][i] << "*" << a << "^" << power-i << "*" << b << "^" << i;
				}
			}
		}


	}

	return 0;
}
