//http://acm.timus.ru/problem.aspx?space=1&num=1126

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<int> v;
    int h;
    while(cin >> h){
        if (h == -1)
            break;
        v.push_back(h);
    }
    set<int> current;
    vector<int> cnt(100001, 0);
    for (int i = 0; i < m; i++){
        cnt[v[i]]++;
        current.insert(v[i]);
    }
    set<int>::iterator it = current.end();
    it--;
    cout << *it << endl;
    for (int i = m; i < v.size(); i++){
        cnt[v[i - m]]--;
        if (cnt[v[i - m]] == 0)
            current.erase(v[i - m]);

        cnt[v[i]]++;
        current.insert(v[i]);
        set<int>::iterator it = current.end();
        it--;
        cout << *it << endl;
    }
    return 0;
}
