#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int> > v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        v.push_back(make_pair(h, i));
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    string answ = "";
    /*for (int i = 0; i < n; i++){
        cout << " (" << v[i].first << " " << v[i].second << ") ";
    }
    cout << endl;*/
    for(int i = 0; i < m; i++){
        int l, r, number;
        cin >> l >> r >> number;
        l--, r--;
        int index = lower_bound(v.begin(), v.end(), make_pair(number, l)) - v.begin();
        if (index == v.size() || v[index].first != number){
            answ += "0";
            continue;
        }
        // int index = it -> second;
        if (v[index].second <= r)
            answ += "1";
        else
            answ += "0";
    }
    cout << answ;
    return 0;
}
