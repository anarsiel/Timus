#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i){
	 	int a, b;
	 	cin >> a >> b;
	 	v.push_back(make_pair(b, a));
	}
   	vector<int> dp(n + 1);

   	sort(v.begin(), v.end());

	dp[0] = 1;

	for (int i = 1; i < n; i++){
		int j = upper_bound(v.begin(), v.end(), make_pair(v[i].second - 1, int(1e9))) - v.begin();
		if (j == 0){
		 	dp[i] = dp[i - 1];
		}else
			dp[i] = max(dp[i - 1], dp[j - 1] + 1);
	}
	cout << dp[n - 1];
 	return 0;
}        