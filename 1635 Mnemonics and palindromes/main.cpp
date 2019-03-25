#include <bits/stdc++.h>

using namespace std;

vector<long long> l_hash, powers, r_hash;

long long left_hash(long long l, long long r){
	l++, r++;
	return l_hash[r] - l_hash[l - 1] * powers[r - l + 1];
}

long long right_hash(long long l , long long r){
 	//l++, r++;
 	return r_hash[l] - r_hash[r + 1] * powers[r - l + 1];
}

bool palindrome(long long l, long long r){
 	return left_hash(l, r) == right_hash(l, r);
}

int main(){
	#ifdef LocalHost
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

    string s;
    cin >> s;
    long long n = s.size();
    vector<long long> d(n + 1, 1e18);
   	vector<int> pred(n + 1, -1);

    powers.push_back(1);
    for (long long i = 1; i < n + 1; ++i){
    	powers.push_back(powers[i - 1] * 239);
    }

	l_hash.push_back(0);
	for (long long i = 1; i < n + 1; i++){
	 	l_hash.push_back(l_hash[i - 1] * 239 + s[i - 1]);
	}

	r_hash.resize(n + 1);
	r_hash[n] = 0;
	for (long long i = n - 1; i > -1; i--){
	 	r_hash[i] = r_hash[i + 1] * 239 + s[i];
	}

	for (long long i = 0; i < n; i++){
     	for (long long j = 0; j <= i; j++){
     		if (!palindrome(j, i))
     			continue;
     		//cout << i << ' ' << j << endl;
     		long long a = ((j == 0) ? 1 : d[j - 1] + 1);
    		if (a < d[i]){
    			d[i] = a;
    			pred[i] = j - 1;
    	    }
     	}
    }            
    cout << d[n - 1] << endl;
   	int i = n - 1;
   	vector<string> answ;
   	while (i != -1){
   	 	answ.push_back(s.substr(pred[i] + 1, i - pred[i]));
   	 	i = pred[i];
   	}
   	for (int i = answ.size() - 1; i > -1; i--)
   		cout << answ[i] << ' ';
   	return 0;
}