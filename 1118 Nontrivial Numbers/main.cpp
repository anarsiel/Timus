#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	long long f, s;
	cin >> f >> s;

	vector<long long> arr(s + 2);
	
	for (long long i = 2; i <= s; ++i){
	    for (long long j = 2 * i; j <= s; j += i){
	    	arr[j] += i;
	   	} 
	}
	long double m = 1e18;
	long long answ = 0;
	for (long long i = f; i <= s; i++){
	 	if (m > (0.0 + arr[i] + (i > 1)) / i){
	 	 	m = 1.0 * (arr[i] + (i > 1)) / i;
	 	 	answ = i;
	 	}
	}
	cout << answ;
 	return 0;
}
