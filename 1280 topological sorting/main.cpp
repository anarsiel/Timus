#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[b].push_back(a);
    }

    vector<bool> used(n, false);

    for (int i = 0; i < n; i++){
        int current;
        cin >> current;
        current--;
        used[current] = true;
        for (int j = 0; j < v[current].size(); j++){
            if (!used[v[current][j]]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
