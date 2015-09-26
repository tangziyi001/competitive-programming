//SPOJ SUBSEQ
// Handling searching of consecutive elements by cumulation.
// Use map to record how many times a certain sum shows up.
#include <iostream>
#include <vector>
#include <set>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		map<long long, int> seq;
		vector<int> tmp;
		int n;
		int a[1000001];
		scanf("%d",&n);
		int sum = 0;
		seq[0]=1;

		for (int i = 0; i < n; i++){
			int num;
			cin >> num;
			sum += num;
			a[i] = sum;
		}
		int count = 0;
		for (int i = 0; i < n; i++){
			seq[a[i]] += 1;
			if (seq.find(a[i]-47) != seq.end() ){
				count += seq[a[i]-47];
			}
		}
		printf("%d\n", count);
	}
	return 0;
}