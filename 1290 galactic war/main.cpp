#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        return 0;

    vector<int> v, _v;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());
    int current = 0, index = 0;
    n = v.size();
    while (true){
        if (current < v[index]){
            _v.push_back(n - index);
            current++;
        }else{
            index++;
            if (index == n)
                break;
        }
    }

    /*for (int i = 0; i < _v.size(); i++){
        cout << _v[i] << ' ';
    }
    cout << '\n';*/
    sort(_v.begin(), _v.end());
    current = 0, index = 0;
    n = _v.size();
    while (true){
        if (current < _v[index]){
            cout << n - index << '\n';
            current++;
        }else{
            index++;
            if (index == n)
                break;
        }
    }
    return 0;
}
