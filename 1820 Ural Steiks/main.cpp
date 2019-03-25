#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int z = a;

    int answ = 0;

    while (a > 0) {
        answ += 1;
        a -= b;
    }
    a += z;

    while (a > 0) {
        answ += 1;
        a -= b;
    }

    cout << answ;
    return 0;
}
