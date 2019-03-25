//http://acm.timus.ru/problem.aspx?space=1&num=1100

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct triple{
    int f, s, t;

    triple(){}

    triple(int x, int y, int z){
        f = x;
        s = y;
        t = z;
    }
};

bool comp(triple a, triple b){
    if (a.s != b.s)
        return a.s > b.s;
    return a.t < b.t;
}

int main()
{
    int n;
    cin >> n;
    vector<triple> v;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(triple(a, b, i));
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++)
        cout << v[i].f << ' ' << v[i].s << endl;
    return 0;
}
