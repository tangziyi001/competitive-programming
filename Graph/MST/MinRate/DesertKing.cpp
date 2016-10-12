/*
 *	POJ 2728	
 *	Created by Ziyi Tang
 *	MST with min rate - Fractional Programming
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1005
#define MOD 1000000007
#define EPS 1e-5
struct Point {
	double x_;
	double y_;
	double h_;
	double dista(Point& tmp) const {
		return hypot(x_-tmp.x_, y_-tmp.y_);
	}
	Point() : x_(0), y_(0), h_(0){}
	Point(double x, double y, double h) : x_(x), y_(y), h_(h) {}
} all[MAXN];
double bs[MAXN][MAXN];
double cs[MAXN][MAXN];
double graph[MAXN][MAXN];
int mark[MAXN];
int dis[MAXN];

// Min Spanning Tree
double prim(const int& n)  
{  
    double dis[MAXN];  
    int vis[MAXN];  
    double sum = 0;  
    memset(vis,0,sizeof(vis));  
    for(int i = 0; i < n; i++)  
        dis[i] = graph[0][i];
    vis[0] = 1;  
    for(int i = 0; i < n-1; i++)  
    {  
        double Min = INF;  
        int pos = -1;  
        for(int j = 0; j < n; j++)  
        {  
            if(!vis[j] && dis[j] < Min)  
            {  
                Min = dis[j];  
                pos = j;  
            }  
        }  
        if(pos == -1)  
            break;  
        sum += Min;  
        vis[pos] = 1;  
  
        double tmp;  
        for(int j = 0; j < n; j++)  
        {  
            tmp = graph[pos][j];
            if(!vis[j] && dis[j] > tmp)  
                dis[j] = tmp;  
        }  
    }  
    return sum;  
}  
void build(const int& n, const double& mid){
	REP(i,0,n-1) REP(j,i+1,n) {
		graph[i][j] = graph[j][i] = cs[i][j] - mid*bs[i][j];
	}
}
int main(){
	int n;
	while(scanf("%d", &n) && n != 0){
		double x,y,h;
		FILL(bs,-1);
		FILL(cs,-1);
		FILL(graph,-1);
		REP(i,0,n){
			scanf("%lf %lf %lf", &x, &y, &h);
			all[i] = Point(x,y,h);
		}
		REP(i,0,n-1) REP(j,i+1,n) {
			bs[i][j] = bs[j][i] = all[i].dista(all[j]);
			cs[i][j] = cs[j][i] = fabs(all[i].h_-all[j].h_);
		}
		double l = 0.0, r = 50.0;
		while(fabs(r-l) > EPS){
			double mid = (l+r)/2;
			build(n, mid);
			if(prim(n) >= 0.0)
				l = mid;
			else
				r = mid;
			// printf("mid %.3f\n", mid);
		}
		printf("%.3f\n", r);
	}
	return 0;
}
