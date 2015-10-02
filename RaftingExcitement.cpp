//NYURAFT
// Set
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

char map[15][15];
typedef pair<int,int> PP;
set<PP> exi;
set<PP> spot;
int spotnum = 0;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool bound(int r, int c, int gr, int gc){
	if (r < 1 || r > gr || c > gc || c < 1){
		return false;
	}
	else{
		return true;
	}
}

bool progress(int sr, int sc, int r, int c, int gr, int gc){
	if (bound(r,c,gr,gc) == false){
		return false;
	}
	if (r == sr && c == sc && exi.find(make_pair(r,c)) != exi.end()){
		if (spot.size() == spotnum){
			return true;
		}
		else{
			return false;
		}
	}
	else if(exi.find(make_pair(r,c)) != exi.end()){
		return false;
	}


	int nextdir = 0;
	if (map[r][c] == '>'){
		nextdir = 2;
	}
	else if (map[r][c] == '<'){
		nextdir = 3;
	}
	else if (map[r][c] == '^'){
		nextdir = 1;
	}
	else if (map[r][c] == 'v'){
		nextdir = 0;
	}
	else{
		return false;
	}
	exi.insert(make_pair(r,c));
	for (int i = 0; i < 4; i++){
		int dr = r + dir[i][0];
		int dc = c + dir[i][1];
		if (map[dr][dc] == 'S'){
			if(spot.find(make_pair(dr,dc)) != spot.end()){
				return false;
			}
			else{
				spot.insert(make_pair(dr,dc));
			}
		}
	}
	int tdr = r + dir[nextdir][0];
	int tdc = c + dir[nextdir][1];
	return progress(sr,sc,tdr,tdc,gr,gc);
}

int main(){
	int test;
	cin >> test;
	while (test--){
		exi.clear();
		spot.clear();
		memset(map,'0',sizeof(map));
		spotnum = 0;

		int r, c;
		int sr, sc;
		cin >> r >> c >> sr >> sc;
		for (int i = 1; i <= r; i++){
			cin >> &(map[i][1]);
			for (int j = 1; j <= c; j++){
				if (map[i][j] == 'S'){
					spotnum += 1;
				}
			}
		}
		if (spotnum == 0){
			cout << "not exciting" << endl;
		}
		else{
			bool exc = progress(sr,sc,sr,sc,r,c);
			if (exc){
				cout << "exciting" << endl;
			}
			else{
				cout << "not exciting" << endl;
			}
		}
		
		
		

	}


	return 0;
}