#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> azaz(3);
bool used[256 * 3];
bool arr[256][256][256]; 

void func(vector<int> &v) {
	used[v[0] + v[1] + v[2]] = true;
	used[v[0] + v[1]] = true;
	used[v[0] + v[2]] = true;
	used[v[1] + v[2]] = true;
	used[v[0]] = true;
	used[v[1]] = true;
	used[v[2]] = true;

	arr[v[0]][v[1]][v[2]] = true;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;

			int x = min(v[i], azaz[j] - v[j]);
			v[i] -= x;
			v[j] += x;

			if (!arr[v[0]][v[1]][v[2]])
				func(v);

			v[i] += x;
			v[j] -= x;
		}
	}

	for (int i = 0; i < 3; i++) {
		int mem = v[i];
		v[i] = azaz[i];
		if (!arr[v[0]][v[1]][v[2]])
			func(v);
		v[i] = mem;
	}
}

int main() {
	//freopen("second.in", "r", stdin);
	//freopen("second.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	
	cin >> azaz[0] >> azaz[1] >> azaz[2];
	vector<int> v = {0, 0, 0};
	func(v);
	int cnt = 0;
	for (int i = 1; i < 256 * 3; i++) {
		cnt += used[i];
	}
	cout << cnt << endl;
	return 0;
}