//UVA 10977
// BFS for Path. Avoid repeatably search.
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> PP;


int dp[205][205];

void check(int gr, int gc){
    queue<PP> que;
    PP fir(1,1);
    que.push(fir);
    while (!que.empty()){
        PP tmp = que.front();que.pop();
        int f = tmp.first;
        int s = tmp.second;
        if(f==gr&&s==gc)break;
        if (f+1 <= gr && dp[f+1][s] == -1){
            // Mark as explored, push to the queue
            dp[f+1][s] = dp[f][s]+1;
            que.push(make_pair(f+1,s));
        }
        if (f-1 >= 1 && dp[f-1][s] == -1){
            dp[f-1][s] = dp[f][s]+1;
            que.push(make_pair(f-1,s));
        }
        if (s+1 <= gc && dp[f][s+1] == -1){
            dp[f][s+1] = dp[f][s]+1;
            que.push(make_pair(f,s+1));
        }
        if (s-1 >= 1 && dp[f][s-1] == -1){
            dp[f][s-1] = dp[f][s]+1;
            que.push(make_pair(f,s-1));
        }
    }
    
}

int main(){
    int r, c;
    while (cin >> r >> c && (r != 0 || c != 0)){
        for(int i=0;i<=r;i++)
            for(int j=0;j<=c;j++)
                dp[i][j]=-1;
        dp[1][1] = 0;
        int bn;
        cin >> bn;
        
        while (bn--){
            int br, bc;
            cin >> br >> bc;
            dp[br][bc] = -2;
        }
        int sound;
        cin >> sound;
        
        while(sound--){
            int sr, sc, radius;
            cin >> sr >> sc >> radius;
            
            for (int i =1 ; i <= r; i++){
                for (int j = 1; j <=c; j++){
                    if (((i-sr)*(i-sr) + (j-sc)*(j-sc) <= (radius)*(radius) )){
                        dp[i][j] = -2;
                    }
                }
            }
            
        }
        if(dp[1][1] == -2 || dp[r][c] == -2){
            cout << "Impossible." << endl;
            continue;
        }
        int gr = r;
        int gc = c;
        check(gr,gc);
        int re = dp[r][c];
        if (re <0){
            cout << "Impossible." << endl;
        }
        else{
            cout << re << endl;
        }
        
    }
    
    
    
    
    return 0;
}