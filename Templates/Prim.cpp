/*
 *  Prim's Algorithm
 *  Created by Ziyi Tang
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

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

int main(){
    
    return 0;
}