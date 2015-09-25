// SPOJ SUBSEQ
//Handling searching of consecutive elements by cumulation.
#include <iostream>
#include <vector>
#include <set>
#include <vector>

using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		set<int> seq;
		vector<int> tmp;
		int n;
		int a[1000001];
		cin >> n;
		int sum = 0;
		seq.insert(sum);

		for (int i = 0; i < n; i++){
			int num;
			cin >> num;
			sum += num;
			a[i] = sum;
			seq.insert(sum);
		}
		int count = 0;
		for (int i = 0; i < n; i++){
			while (seq.find(a[i]-47) != seq.end()){
				auto it = seq.find(a[i] - 47);
				count += 1;
				tmp.push_back(*it);
				seq.erase(it);
			}
			if (!tmp.empty()){
				for (auto it = tmp.begin(); it != tmp.end(); it++){
					seq.insert(*it);
				}
				tmp.clear();
			}

		}
		cout << count << endl;
	}
	return 0;
}