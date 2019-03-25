#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct edge {
    int v, block, c;

    edge() {}
    edge(int _v, int _block, int _c) {
        v = _v;
        block = _block;
        c = _c;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<vector<edge> > > v(40, vector<vector<edge> >(40));
    vector<int> mm;
    mm.push_back(1);
    for (int i = 1; i <= n; i++){
        int m;
        cin >> m;
        mm.push_back(m);
        int h;
        for (int j = 0; j < m; j++){
            while (cin >> h){
                if (h == 0)
                    break;
                h--;
                int c;
                cin >> c;
                v[i - 1][h].push_back(edge(j, i, c));
            }
        }
        string to_bin;
        if (i != n)
            cin >> to_bin;
    }
    vector<vector<int> > dist(n + 1);
    for (int i = 0; i <= n; i++){
        dist[i].resize(mm[i], 1e9 + 7);
    }
    dist[0][0] = 0;
    for (int l = 0; l < 1000; l++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < mm[i]; j++){
                for (int k = 0; k < v[i][j].size(); k++){
                    int vertex = v[i][j][k].v;
                    dist[i + 1][vertex] = min(dist[i + 1][vertex], dist[i][j] + v[i][j][k].c);
                }
            }
        }
    }
    int answ = 1e9 + 7;
    for (int i = 0; i < mm[n]; ++i){
        answ = min(answ, dist[n][i]);
    }
    cout << answ;
    return 0;
}
