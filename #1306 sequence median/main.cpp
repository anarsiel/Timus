//http://acm.timus.ru/problem.aspx?space=1&num=1306

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    unsigned int n;
    cin >> n;
    vector<unsigned int> v;

    for (unsigned int i = 0; i < n; i++){
        unsigned int h;
        cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());
    unsigned int len = v.size();

    /*for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;*/

    if ((len % 2) == 1)
        printf("%d", v[len / 2]);
    else
        printf("%.1f" ,(v[len / 2 - 1] + v[len / 2] + 0.0) / 2);
    //cout << ' ' << v[len / 2] << " " << v[len / 2 - 1];
    return 0;
}
