//UVA 12504
//Map Processing
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//Put all pairs into a map
map<string, string> fill_map(char* buf){
	string key = "";
	string value = "";
		int process_key = 1;
		map<string, string> mymap;
		for (int i = 1; i < strlen(buf); ++i){
			if (process_key == 1){
				if (buf[i] == ':'){
					process_key = 0;
				}
				else{
					key = key + buf[i];
				}			
			}
			else {
				if (buf[i] == ','){
					mymap[key] = value;
					process_key = 1;
					key = "";
					value = "";
					
				}
				else{
					value = value + buf[i];
				}
			}		
		}
		return mymap;
}


int main(){
	int count;
	cin >> count;
	char first[100];
	char second[100];
	map<string,string> mymap1;
	map<string,string> mymap2;
	while(cin >> first >> second){
		first[strlen(first) - 1] = ',';
		second[strlen(second) - 1] = ',';
		mymap1 = fill_map (first);
		mymap2 = fill_map (second);
		vector<string> add;
		vector<string> del;
		vector<string> mod;
		map<string,string>::iterator ia, ib;
		for (ib = mymap2.begin(); ib != mymap2.end(); ib++){
			if (mymap1.find(ib->first) == mymap1.end()){
				add.push_back(ib->first);
			}
			else{
				ia = mymap1.find(ib->first);
				if(mymap1[ia->first] != ib->second){
					mod.push_back(ia->first);
				}
			}

		}
		for (ia = mymap1.begin(); ia != mymap1.end(); ++ia){
			if (mymap2.find(ia->first) == mymap2.end()){
				del.push_back(ia->first);
			}
		}

		if (add.empty() && mod.empty() && del.empty()){
			cout << "No changes" << endl;
			cout << endl;
			continue;
		}
		if (!add.empty()){
			vector<string>:: iterator it;
			sort(add.begin(), add.end());
			cout << "+";
			cout << *add.begin();
			for (it = add.begin() + 1; it != add.end(); ++it){
				cout << "," << *it;
			}
			cout << endl;
		}
		if (!del.empty()){
			vector<string>:: iterator it;
			sort(del.begin(), del.end());
			cout << "-";
			cout << *del.begin();
			for (it = del.begin() + 1; it != del.end(); ++it){
				cout << "," << *it;
			}
			cout << endl;
		}
		if (!mod.empty()){
			vector<string>:: iterator it;
			sort(mod.begin(), mod.end());
			cout << "*";
			cout << *mod.begin();
			for (it = mod.begin() + 1; it != mod.end(); ++it){
				cout << "," << *it;
			}
			cout << endl;
		}
		cout << endl;

	}

	


	return 0;
}