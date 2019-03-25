//http://acm.timus.ru/problem.aspx?space=1&num=1026

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> base;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        base.push_back(h);
    }
    string some_trash;
    cin >> some_trash;

    sort(base.begin(), base.end());

    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int index;
        cin >> index;
        index--;
        cout << base[index] << endl;
    }
    return 0;
}
