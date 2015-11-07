/*
 *	UVA 11242
 *	Created by Ziyi Tang
 *	
 */

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

vector<double> ra;
vector<double> re;
vi rear;
vi front;
int main(){
	int f,r;
	while (cin >> f && f != 0){
		ra.clear();
		re.clear();
		rear.clear();
		front.clear();
		cin >> r;
		REP(i,0,f){
			int tmp;
			cin >> tmp;
			front.push_back(tmp);
		}
		REP(i,0,r){
			int tmp;
			cin >> tmp;
			rear.push_back(tmp);
		}
		REP(i,0,f){
			REP(j,0,r){
				double tmp;
				tmp = (double)rear[j]/(double)front[i];
				ra.push_back(tmp);
			}
		}
		sort(ra.begin(),ra.end());
		
		int sz = ra.size();
		REP(i,0,sz-1){
				re.push_back((double)ra[i+1]/ra[i]);
		}
		// REP(i,0,re.size()){
		// 	cout << re[i] << endl;
		// }
		double res = *max_element(re.begin(),re.end());
		printf("%.2lf\n",res);

	}





	return 0;
}
