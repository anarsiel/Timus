#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> pref;
    int sum = 0;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        sum += h;
        pref.push_back(sum);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a == 0)
            cout << pref[b] << endl;
        else
            cout << pref[b] - pref[a - 1] << endl;
    }
    return 0;
}
