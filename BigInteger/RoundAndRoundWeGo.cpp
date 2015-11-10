
/*
 *	POJ 1047
 *	Created by Ziyi Tang
 *	Use string to represent big integer addition
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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

bool check(string ori, string aa){
	return ori == aa;
}
string add(string num, string num2){
	int sz = num.size();
	int carry = 0;
	string tmp;
	for (int i = sz-1; i >= 0; i--){
		int tt = 0;
		if (carry == 1){
			tt++;
			carry = 0;
		}
		//cout << num.substr(i,1);
		stringstream s1(num.substr(i,1));
		stringstream s2(num2.substr(i,1));
		int ele1, ele2;
		s1 >> ele1; s2>>ele2;
		int ele = ele1+ele2;
		tt += ele;
		if (tt >= 10)
			carry = 1;
		tt %= 10;
		stringstream nn;
		nn << tt;
		tmp = nn.str() + tmp;

	}
	return tmp;

}

int main(){
	string num;
	while(cin >> num){
		int sz = num.size();
		string aa = num;
		int flag = 1;
		int flag2 = 0;
		REP(i, 0, sz-1){
			aa = add(aa, num);
			string aaa = aa;
			REP(j,0,sz-1){
				if (check(num,aaa)){
					flag2 = 1; 
					break;
				}
				rotate(aaa.begin(),aaa.begin()+1,aaa.end());
			}
			if (flag2 == 1)
				continue;	
			else
				flag = 0; break;
		}
		if (flag == 0){
			REP(i,0,sz){
				cout << num[i];
			}
			printf(" is not cyclic\n");
		}
		else{
			REP(i,0,sz){
				cout << num[i];
			}
			printf(" is cyclic\n");
		}

	}





	return 0;
}
