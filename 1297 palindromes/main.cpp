#include <bits/stdc++.h>

using namespace std;

vector<long long> powers;
vector<long long> HAAAAASH, rHAAAAASH;

const int M = 1e9 + 7;

long long mmod(long long x) {
	return (x % M + M) % M;
}

long long _HAAAAASH(long long l, long long r){
 	long long a = HAAAAASH[r + 1];
 	long long b = HAAAAASH[l];
 	return mmod(a - b * powers[r - l + 1]);
}

long long _rHAAAAASH(long long l, long long r){
 	long long a = rHAAAAASH[l];
 	long long b = rHAAAAASH[r + 1];
 	return mmod(a - b * powers[r - l + 1]);
}

int main(){
	string s;
	cin >> s;
	long long n = s.size();

	HAAAAASH.resize(n + 1);
	rHAAAAASH.resize(n + 1);
	powers.resize(n + 1);

	powers[0] = 1;
	
	for (long long i = 1; i <= n; i++)
		powers[i] = mmod(powers[i - 1] * 239);
	
	for (long long i = 0; i < n; i++){
	    HAAAAASH[i + 1] = mmod(HAAAAASH[i] * 239 + s[i]);
	    rHAAAAASH[n - i - 1] = mmod(rHAAAAASH[n - i] * 239 + s[n - i - 1]);
	}

	long long answ = -1e9, a_l, a_r;

	for (long long l = 0; l < n; l++){
	 	for (long long r = l; r < n; r++){
	 	 	 if (_HAAAAASH(l, r) == _rHAAAAASH(l, r)){
	 	 	  	if (answ < r - l + 1){
	 	 	  	 	answ = r - l + 1;
	 	 	  	 	a_l = l;
	 	 	  	 	a_r = r;
	 	 	  	}
	 	 	 }
	 	}
	}         
	cout << s.substr(a_l, a_r - a_l + 1);
 	return 0;
}