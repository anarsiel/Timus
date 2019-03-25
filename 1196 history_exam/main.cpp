//http://acm.timus.ru/problem.aspx?space=1&num=1196

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    set<int> real;
    cin >> n;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        real.insert(h);
    }
    int m;
    cin >> m;
    int answ = 0;
    for (int i = 0; i < m; i++){
        int h;
        cin >> h;
        answ += real.count(h);
    }
    cout << answ;
    return 0;
}
