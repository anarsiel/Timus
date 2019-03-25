#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    n = 12 - n;
    if (1.0 * 45 * n / 60 > 4)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
