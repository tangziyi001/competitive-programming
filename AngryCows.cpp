/*
 *	USACO 2016 January Contest, Bronze 2
 *	Created by Ziyi Tang
 *	Implementation
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> all;
int n;
int countLeft(int now, int rad){
	int left = all[now]-rad;
	//cout << "left is " << right << endl;
	int cont = 1;
	for(int i = 0; i < now; i++){
		if(all[i] >= left){
			cont += (now-i-1+countLeft(i, rad+1));
			break;
		}
	}
	return cont;
}
int countRight(int now, int rad){
	int right = all[now]+rad;
	int cont = 1;
	for(int i = n-1; i > now; i--){
		if(all[i] <= right){
			// cout << "pos " << i << " " << all[i] << endl;
			cont += (i-now-1+countRight(i, rad+1));
			break;
		}
	}
	return cont;
}
int main(){
	ifstream ifile("angry.in");
	ifile >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		ifile >> tmp;
		all.push_back(tmp);
	}
	ifile.close();
	sort(all.begin(),all.end());
	int maxp = 0;
	for(int i = 0; i < n; i++){
		int l = countLeft(i,1);
		int r = countRight(i,1);
		//cout << l << " " << r << endl;
		maxp = max(maxp, l+r-1);
	}
	ofstream ofile("angry.out");
	ofile << maxp << endl;
	//cout << maxp << endl;
	ofile.close();
	return 0;
}