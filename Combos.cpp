//NYUCOMBO
// Binary Value Expectation

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

int score[1100000];
double pro[1100000];
using namespace std;
int pos = 0;
int gn;
double gp;
double cal(int n, double p, int sum, int con){
	if (n == 0){
		return sum * p;
	}
	else{
		return cal(n-1,gp * p, sum + con + 1, con + 1) + cal(n-1,p * (1-gp), sum + 0, 0);
	}
	
}
int main(){
	int test;
	cin >> test;
	while (test--){
		memset(score,0,sizeof(score));
		memset(pro,0,sizeof(pro));
		gn = 0;
		gp = 0;
		pos = 0;
		cin >> gn >> gp;
		double sum = cal(gn,1,0,0);
		printf("%6f\n", sum);
	}

	return 0;
}