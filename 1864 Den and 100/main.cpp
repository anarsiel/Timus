#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v;
	long long sum = 0;
	for (int i = 0; i < n; i++){
		int h;
		cin >> h;
		sum += h;
		v.push_back(h);
	}
	long double drink = 1.0 * sum / (n + 1);
	long double s = 0;
	vector<long double> more;

	for (int i = 0; i < n; i++){          
		if (v[i] - drink > 0 - 1e-9){
			more.push_back(v[i] - drink);
			s += more[i];
		}else
			more.push_back(0);
	}        
	for (int i = 0; i < n; i++){
		cout << int(more[i] * 100 / s) << ' ';	
	}	
 	return 0;
}