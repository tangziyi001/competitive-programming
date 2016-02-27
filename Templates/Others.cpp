/*
 *	Other Template
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

// LIS Greedy + Divide and Conquer
int LIS(vector<int>& s)
{
    if (s.size() == 0) return 0;
    vector<int> v;
    v.push_back(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        int n = s[i];
        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }
    return v.size();
}

// Next lexicographical permutation
void myswap(int* a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void nextPermutation(vector<int> nums) {
    int sz = nums.size();
    int i = sz-1;
    while(i > 0 && nums[i] <= nums[i-1])
        i--;
    if(i <= 0) sort(nums.begin(),nums.end());
    else{
        int j = sz-1;
        while(nums[j] <= nums[i-1])
            j--;
        myswap(&nums[i-1],&nums[j]);
        j = sz-1;
        while(j > i){
            myswap(&nums[i],&nums[j]);
            i++;
            j--;
        }
    }
}