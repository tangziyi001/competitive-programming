/*
 *	UVA 00793
 *	Created by Ziyi Tang
 *	Trivial Union Find
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
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
#define MAXN 100000
#define FILL(x,v) memset(x,v,sizeof(x));
#define REP(i,s,t) for(int i = s; i < t; i++)

int all[MAXN];
int n;
int p[MAXN];
int rk[MAXN];
int findRep(int i){
	if (p[i] == i){
		return i;
	}
	return p[i] = findRep(p[i]); // Update parent to the root;
}
bool isSameSet(int i, int j){
	return findRep(i) == findRep(j);
}
void unionSet(int i, int j){
	if (!isSameSet(i,j)){
		int p1 = findRep(i);
		int p2 = findRep(j);
		if (rk[p1] > rk[p2]){
			p[p2] = p1;
		}
		else if(rk[p1] < rk[p2]){
			p[p1] = p2;
		}
		else{
			p[p1] = p2;
			rk[p2]++;
		}
	}
}
int main(){
	int test;
	cin >> test;
	getchar();getchar();
	REP(t,0,test){
		if(t)
			cout << endl;
		// Input n elements
		cin >> n;
		getchar();
		// Clear
		FILL(all,0);
		FILL(rk,0);
		for(int i = 0; i < n; i++){
			all[i] = i;
			p[i] = i;
		}
		string line;
		int suc,fai;
		suc = 0; fai = 0;
		while(getline(cin,line) && line != ""){
			stringstream ss(line);
			string letter;
			ss >> letter;
			if(letter == "c"){
				int a,b;
				ss >> a >> b;
				unionSet(a-1,b-1);

			}else{
				int a,b;
				ss >> a >> b;
				if(isSameSet(a-1,b-1))
					suc++;
				else
					fai++;
			}
		}
		cout << suc << "," << fai << endl;

	}
	



	return 0;
}

