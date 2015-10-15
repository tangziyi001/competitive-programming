/*
 *	UVA 11790
 *	Created by Ziyi Tang
 *	Weighted LIS and LDS
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
#include <bitset>
using namespace std;
#define INF 1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++){
		int num;
		vi allheight;
		vi allwidth;
		vi lis;
		vi lds;
		int maxlis = 0;
		int maxlds = 0;
		cin >> num;
		for (int j = 0; j < num; j++){
			int tmp;
			cin >> tmp;
			allheight.push_back(tmp);
		}
		for (int j = 0; j < num; j++){
			int tmp;
			cin >> tmp;
			allwidth.push_back(tmp);
		}
		for (int j = 0; j < num; j++){
			if (j == 0){
				lis.push_back(allwidth[j]);
				lds.push_back(allwidth[j]);
				maxlis = max(maxlis, lis[0]);
				maxlds = max(maxlds, lds[0]);
			}
			else{
				int idx = j-1;
				int lenlis = allwidth[j];
				int lenlds = allwidth[j];
				while (idx >= 0){
					if (allheight[j] > allheight[idx]){
						lenlis = max(lenlis, lis[idx]+allwidth[j]);
					}
					if (allheight[j] < allheight[idx]){
						lenlds = max(lenlds, lds[idx]+allwidth[j]);
					}
					idx--;
				}
				maxlis = max(maxlis, lenlis);
				maxlds = max(maxlds, lenlds);
				lis.push_back(lenlis);
				lds.push_back(lenlds);
			}
		}
		if (maxlis >= maxlds){
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",i, maxlis, maxlds);
		}
		else{
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",i, maxlds, maxlis);
		}
	}




	return 0;
}
