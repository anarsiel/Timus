#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(20);

    vector<double> v;

    long long h;

    while (cin >> h) {
        v.push_back(sqrt(h));    
    } 

    for (int i = v.size() - 1; i > -1; i--)
        cout << v[i] << endl;
    return 0;
}
