#include <bits/stdc++.h>

using namespace std;

long long p(long long number, long long power){
    if (power == 0)
    	return 1;
   	if (power == 1)
   		return number;
   	long long a = p(number, power / 2);
   	if (power % 2 == 0){
   	 	return a * a;
   	}
   	return a * a * number;
}	

int main(){
    ios_base::sync_with_stdio(false);
	
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++){
	 	long long m, k;
	 	cin >> m >> k;
	 	long long h = -1e9;
	 	for (long long j = 1; j <= k; j++){
	 	    long long one = m / j;
	 	    long long two = m % j;
	 	    h = max(h, p(one, j) * max(two, 1LL));
	 	}	
	 	cout << h << endl;
	}
 	return 0;
}