#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long mod(long long x){
 	return (x % MOD >= 0 ? x % MOD : x % MOD + MOD);
}

vector<long long> h, pp;

long long get_hash(int l, int r){
	return mod(h[r + 1] - h[l] * pp[r - l + 1]);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	s = s + s;

	h.resize(2 * n + 1);
	pp.resize(2 * n + 1);
	pp[0] = 1;
	for (int i = 1; i < 2 * n + 1; i++){
		h[i] = mod(h[i - 1] * 239 + s[i - 1]);
		pp[i] = mod(pp[i - 1] * 239);
	}

	long long _h = 0;

	for (int i = 1; i < n + 1; i++){
	 	_h *= 239;
		_h += t[i - 1];
		_h = mod(_h);
	}

	for (int i = 1; i <= n; i++){
	 	if (get_hash(i, i + n - 1) == _h){
	 	 	cout << n - i;
	 	 	return 0;
	 	}
	}
	cout << -1;
 	return 0;
}
