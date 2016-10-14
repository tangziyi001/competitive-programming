/*
 *  Dinic's Algorithm
 *  Created by Ziyi Tang
 *  O(V^2 E)
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

#define N 100040  
#define M 205000  
struct Edge{  
    ll from, to, cap, nex;  
}edge[M*2]; // Must be big enough
  
ll head[N], edgenum;  
void add(ll u, ll v, ll cap, ll rw = 0){ // Directed Edge: add(u,v,cap);
                                         // Undirected Edge：add(u,v,cap,cap);
    Edge E = { u, v, cap, head[u]};  
    edge[ edgenum ] = E;  
    head[u] = edgenum ++;  
  
    Edge E2= { v, u, rw,  head[v]};  
    edge[ edgenum ] = E2;  
    head[v] = edgenum ++;  
}  
ll sign[N];  
bool BFS(ll from, ll to){  
    memset(sign, -1, sizeof(sign));  
    sign[from] = 0;  
  
    queue<ll>q;  
    q.push(from);  
    while( !q.empty() ){  
        ll u = q.front(); q.pop();  
        for(ll i = head[u]; i!=-1; i = edge[i].nex)  
        {  
            ll v = edge[i].to;  
            if(sign[v]==-1 && edge[i].cap)  
            {  
                sign[v] = sign[u] + 1, q.push(v);  
                if(sign[to] != -1)return true;  
            }  
        }  
    }  
    return false;  
}  
ll Stack[N], top, cur[N];  
ll Dinic(ll from, ll to){  
    ll ans = 0;  
    while( BFS(from, to) )  
    {  
        memcpy(cur, head, sizeof(head));  
        ll u = from;      top = 0;  
        while(1)  
        {  
            if(u == to)  
            {  
                ll flow = INF, loc;//loc 表示 Stack 中 cap 最小的边  
                for(ll i = 0; i < top; i++)  
                    if(flow > edge[ Stack[i] ].cap)  
                    {  
                        flow = edge[Stack[i]].cap;  
                        loc = i;  
                    }  
  
                    for(ll i = 0; i < top; i++)  
                    {  
                        edge[ Stack[i] ].cap -= flow;  
                        edge[Stack[i]^1].cap += flow;  
                    }  
                    ans += flow;  
                    top = loc;  
                    u = edge[Stack[top]].from;  
            }  
            for(ll i = cur[u]; i!=-1; cur[u] = i = edge[i].nex) 
                if(edge[i].cap && (sign[u] + 1 == sign[ edge[i].to ]))break;  
            if(cur[u] != -1)  
            {  
                Stack[top++] = cur[u];  
                u = edge[ cur[u] ].to;  
            }  
            else  
            {  
                if( top == 0 )break;  
                sign[u] = -1;  
                u = edge[ Stack[--top] ].from;  
            }  
        }  
    }  
    return ans;  
}  
void init(){memset(head,-1,sizeof head);edgenum = 0;}

int main(){
    scanf("%d", &test);
    while(test--){
        int n,m;
        scanf("%d %d", &n, &m);
        init();
        REP(i,0,n){
            ll tmp;
            scanf("%lld", &tmp);
            add(n,i,tmp);
        }
        REP(i,0,m){
            ll a,b,c;
            scanf("%lld %lld %lld", &a,&b,&c);
            add(a-1,b-1,c,c); // Undirected
        }
        ll mf = Dinic(n,n+1);
        printf("%lld\n", mf);
    }
    return 0;
}