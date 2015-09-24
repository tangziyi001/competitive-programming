//UVA 10684
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int num;
	while (cin >> num && num != 0){
		int streak = 0;
		int gain = 0;

		for (int i = 0; i < num; ++i){
			int a;
			cin >> a;
			if (streak + a > 0){
				streak = streak + a;
				if (streak > gain){
					gain = streak;
				}	
			}
			else{
				streak = 0;
				continue;
			}			
		}
		if (gain > 0){
			cout << "The maximum winning streak is " << gain << "." << endl;
		}
		else{
			cout << "Losing streak." << endl;
		}
		
	}
	

	return 0;
}