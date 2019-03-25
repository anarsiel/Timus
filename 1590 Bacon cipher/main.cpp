#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_func(string s){
	int n = s.size();
	vector<int> answ(n + 1);
	answ[0] = 0;

	for (int i = 1; i < n; i++){
		int ind = answ[i - 1];
	 	while (ind > 0 && s[ind] != s[i]){
	 		 ind = answ[ind - 1];
	 	}
	 	answ[i] = ind + (s[ind] == s[i]);
	}
	return answ;
}

int main(){
	#ifdef LocalHost
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.size();
	string cur = "";
	long long answ = 0;
	for (int i = 0; i < n; i++){
	 	cur = cur + s[i];
	 	
	 	reverse(cur.begin(), cur.end());
	 	vector<int> v = prefix_func(cur);
	 	reverse(cur.begin(), cur.end());

	 	int m = -1e9;
	 	for (int j = 0; j < i + 1; ++j){
	 	 	m = max(m, v[j]);
	 	}	
	 	answ += i + 1 - m;
	}
	cout << answ;
 	return 0;
}
