#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_func(string s){
	int n = s.size();
 	vector<int> answ(n);
 	answ[0] = 0;
 	int ind;
 	for (int i = 1; i < n; i++){
 		ind = answ[i - 1];
 		while (ind > 0 && s[ind] != s[i]){
 		 	ind = answ[ind - 1];
 		}
 		if (s[ind] == s[i]){
 		 	answ[i] = ind + 1;
 		}
   	}
   	return answ;
}

int main(){
	#ifdef LocalHost
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	string g, t;
	cin >> g >> t;

	string s = g + "#" + t;
	vector<int> v = prefix_func(s);
	for (int i = g.size() + 1; i < v.size(); i++){
	 	if (!v[i]){
	 	 	cout << "Yes";
	 	 	return 0;
	 	}
	}

	vector<pair<int, int> > to_print;
	for (int i = (int)s.size() - 1; i > (int)g.size(); i -= v[i]){
	 	to_print.push_back({i - v[i] + 1, v[i]});
	}
	cout << "No\n";
	for (int i = (int)to_print.size() - 1; i >= 0; i--){
	 	cout << s.substr(to_print[i].first, to_print[i].second) << ' ';
	}
 	return 0;
}