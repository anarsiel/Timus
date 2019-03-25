#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	if (n == 1 && m == 1){
	 	cout << "It is a lie";
	 	return 0;
	}

	for (int i = 0; i < n; ++i){
	 	cout << 100 * (i + 1) << ' ';
	}
	cout << endl;
	for (int i = 0; i < m; i++)
		cout << 1000000000 - i - 1 << ' ';
 	return 0;
}