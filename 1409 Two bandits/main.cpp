#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    a--, b--;
    int s = a + b;
    cout << s - a << ' ' << s - b;
    return 0;
}
