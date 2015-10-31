/*
 *	Aizu 0023
 *	Created by Ziyi Tang
 *	Basic Geometry (Circle)
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
#define INF (int)1E9
#define INFL (long)1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


int main(){
	int test;
	cin >> test;
	while(test--){
		double x1,y1,r1,x2,y2,r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double up1 = y1+r1;
		double down1 = y1-r1;
		double left1 = x1-r1;
		double right1 = x1+r1;

		double up2 = y2+r2;
		double down2 = y2-r2;
		double left2 = x2-r2;
		double right2 = x2+r2;
		int flag = -10;

		if ((left1 > left2 && right1 < right2 && up1 < up2 && down1 > down2) ||
			(left1 > left2 && right1 < right2 && up1 < up2 && down1 > down2) ||
			(left1 > left2 && right1 < right2 && up1 < up2 && down1 > down2) ||
			(left1 > left2 && right1 < right2 && up1 < up2 && down1  > down2)){
				flag = -2;
		}
		if ((left1 < left2 && right1 > right2 && up1 > up2 && down1 < down2) ||
			 (left1 < left2 && right1 > right2 && up1 > up2 && down1 < down2) ||
			 (left1 < left2 && right1 > right2 && up1 > up2 && down1 < down2) ||
			 (left1 < left2 && right1 > right2 && up1 > up2 && down1  < down2)){
				flag = 2;
		}
		if (flag == -10){
			double dis = -1 ;
			dis = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
			if (dis > r1+r2){
				flag = 0;
			}
			else{
				flag = 1;
			}
		}
		
		cout << flag << endl;
	}





	return 0;
}
