/*
 *	UVA 00183
 *	Created by Ziyi Tang
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

int sum[205][205];
int all[205][205];
int x,y;
int idx;
string re;
bool check1(int xs, int xe, int ys, int ye){
	int dim = (xe-xs+1)*(ye-ys+1);
	int dim_sum = sum[xe+1][ye+1]-sum[xe+1][ys]-sum[xs][ye+1]+sum[xs][ys];
	return dim == dim_sum;
}
bool check0(int xs, int xe, int ys, int ye){
	int dim_sum = sum[xe+1][ye+1]-sum[xe+1][ys]-sum[xs][ye+1]+sum[xs][ys];
	return dim_sum == 0;
}
void div(int xs, int xe, int ys, int ye){
	if(check1(xs,xe,ys,ye)){
		re += "1";
		return ;
	}
	if(check0(xs,xe,ys,ye)){
		re += "0";
		return ;
	}
	re += "D";
	if(xe-xs == 0){
		int mid = (ye+ys)/2;
		div(xs,xe,ys,mid);
		div(xs,xe,mid+1,ye);
	}
	else if(ye-ys == 0){
		int mid = (xe+xs)/2;
		div(xs,mid,ys,ye);
		div(mid+1,xe,ys,ye);
	}
	else{
		int midx = (xs+xe)/2;
		int midy = (ys+ye)/2;
		div(xs,midx,ys,midy);
		div(xs,midx,midy+1,ye);
		div(midx+1,xe,ys,midy);
		div(midx+1,xe,midy+1,ye);
	}
}
void btod(string line){
	int idx = 0;
	REP(i,0,x) REP(j,0,y)
		all[i][j] = line[idx++]-'0';
	REP(i,1,x+1) REP(j,1,y+1)
		sum[i][j] = all[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	div(0,x-1,0,y-1);
}

void fill(int xs, int xe, int ys, int ye, string line){
	if(line[idx] == 'D'){
		idx++;
		if(xe-xs == 0){
			fill(xs,xe,ys,(ys+ye)/2,line);
			fill(xs,xe,(ys+ye)/2+1,ye,line);
		}
		else if(ye-ys == 0){
			fill(xs,(xs+xe)/2,ys,ye,line);
			fill((xs+xe)/2+1,xe,ys,ye,line);
		}
		else{
			fill(xs,(xs+xe)/2,ys,(ys+ye)/2,line);
			fill(xs,(xs+xe)/2,(ys+ye)/2+1,ye,line);
			fill((xs+xe)/2+1,xe,ys,(ys+ye)/2,line);
			fill((xs+xe)/2+1,xe,(ys+ye)/2+1,ye,line);
		}
	}
	else{
		REP(i,xs,xe+1) REP(j,ys,ye+1)
			all[i][j] = line[idx]-'0';
		idx++;
	}
}
void dtob(string line){
	fill(0,x-1,0,y-1,line);
	REP(i,0,x) REP(j,0,y)
		re+= '0' + all[i][j];
}
int main(){
	string cas;
	getline(cin, cas);
	while(1){
		if(cas == "#") break;
		FILL(all,0);
		FILL(sum,0);
		re = "";
		idx = 0;
		stringstream ss(cas);
		char sig;
		ss >> sig >> x >> y;
		string line;
		while(getline(cin,cas)){
			int sz = cas.size();
			int flag = 0;
			REP(i,0,sz) if(cas[i] == ' ' || cas[i] == '#') flag = 1;
			if(flag) break;
			else line+=cas;
		}
		//cout << line << endl;
		if(sig == 'B'){
			printf("D%4d%4d\n",x,y);
			if(x == 0 || y == 0){
				cout << endl; continue;
			}
			btod(line);
			int sz = re.size();
			REP(i,0,sz){
				if(i%50 == 0 && i != 0) cout << endl;
				cout << re[i];
			}
			cout << endl;
		}else{
			printf("B%4d%4d\n",x,y);
			if(x == 0 || y == 0){
				cout << endl; continue;
			}
			dtob(line);
			int sz = re.size();
			REP(i,0,sz){
				if(i%50 == 0 && i != 0) cout << endl;
				cout << re[i];
			}
			cout << endl;
		}
	}
		
	return 0;
}

