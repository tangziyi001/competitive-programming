// UVA 11727
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	int n;
	cin >> n;
	int i = 1;
	int a, b, c;
	while (cin >> a >> b >> c){
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		int max = *max_element(v.begin(), v.end());
		int min = *min_element(v.begin(), v.end());
		remove(v.begin(), v.end(), max);
		remove(v.begin(), v.end(), min);
		int med = *v.begin();
		cout << "Case " << i << ": " << med << endl;
		i += 1;
	}
	return 0;
}