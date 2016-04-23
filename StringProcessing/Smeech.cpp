/*
 *	UVA 11291
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	
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
#define MOD 1000000007

string now;
double eval(int sta, int ter){
		//cout << now.substr(sta, ter-sta+1) << endl;;
		if(now[sta] != '('){
			string num = now.substr(sta, ter-sta+1);
			double tmp = stod(num);
			//cout << tmp << endl;
			return tmp;
		}else{
			int idx = sta;
			while(now[idx] != ' ')
				idx++;
			string first = now.substr(sta+1,idx-sta-1);
			// cout << idx << endl;
			// cout << first << endl;
			double ff = stod(first);
			//cout << ff << endl;
			idx++;
			int idxtmp = idx;
			double a,b;
			if(now[idxtmp] == '('){
				int cont = 1;
				idx++; 
				while(cont != 0){
					if(now[idx] == '(') cont++;
					if(now[idx] == ')') cont--;
					idx++;
				}
				a = eval(idxtmp, idx-1);
			}
			else{
				while(now[idx] != ' ')
					idx++;
				a = eval(idxtmp, idx-1);
			}

			idx++;
			idxtmp = idx;
			if(now[idxtmp] == '('){
				int cont = 1;
				idx++;
				while(cont != 0){
					if(now[idx] == '(') cont++;
					if(now[idx] == ')') cont--;
					idx++;
				}
				b = eval(idxtmp, idx-1);
			}
			else{
				while(now[idx] != ')')
					idx++;
				b = eval(idxtmp, idx-1);
			}
			return (double)ff*(a+b) + (1-ff)*(a-b);
		}
}
int main(){	
	while(getline(cin,now)){
		if(now == "()")
			break;
		int sz = now.size();
		double re = eval(0,sz-1);
		printf("%.2lf\n", re);
	}
	return 0;
}