#include <iostream>

using namespace std;

int main() {
	int l, t1, t2, v1, v2;
	cin >> l >> t1 >> v1 >> v2;
	t2 = t1;

	int n;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int type;
		cin >> type;
		int timer;
		cin >> timer >> timer;
		if (type - 1) {
			t2 -= timer;
		} else {
			t1 -= timer;
		}
	}

	cout << (v1 * t1 + v2 * t2) / l;
	return 0;
}