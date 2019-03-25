#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	ios_base::sync_with_stdio(false);
	map<int, int> cnt;

	for (int i = 0; i < n; i++){
	 	int h;
	 	cin >> h;
	 	cnt[h]++;
	}

	int answ = 0;
	int m = -1e9;

	for (auto current : cnt){
		if (m < current.second){
		 	m = current.second;
		 	answ = current.first;
		}                       
	}
	cout << answ;
 	return 0;
}