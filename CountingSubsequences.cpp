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
		map<long , int> seq;
		vector<int> tmp;
		long n;
		long a[1000001];
		scanf("%ld",&n);
		long sum = 0;
		seq[0]=1;

		for (int i = 0; i < n; i++){
			int num;
			scanf("%d",&num);
			sum += num;
			a[i] = sum;
		}
		int count = 0;
		for (int i = 0; i < n; i++){
			seq[a[i]] += 1;
			count += seq[a[i]-47];
			
		}
		printf("%d\n", count);
	}
	return 0;
}