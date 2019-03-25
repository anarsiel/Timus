#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        v.push_back(h);
    }
    int answ = 0;
    int sum = 0, min_sum = 0;
    for (int i = 0; i < n; i++){
        sum += v[i];
        answ = max(answ, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    cout << answ;
    return 0;
}
