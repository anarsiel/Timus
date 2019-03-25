#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> b >> a;
    if (a % 2 == 1 || b % 2 == 0)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
