#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    vector<vector<int> > v(902);
    for (int i = 0; i < 902; i++)
        v[i].resize(8102, 1e9);
    v[0][0] = 0;
    for (int i = 1; i < 902; i++){
        for (int j = 1; j < 8102; j++){
            int m = 1e9;
            for (int h = 1; h <= 9 && h <= i && h * h <= j; h++){
                m = min(m, v[i - h][j - h * h] + 1);
            }
            v[i][j] = m;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if (a > 900 || b > 8100){
            cout << "No solution\n";
            continue;
        }
        int len = v[a][b];
        if (len > 100){
            cout << "No solution\n";
            continue;
        }

        string s;
        for (int j = 0; j < len; j++){
            for (int h = 1; h < 10; h++){
                if (v[a][b] == v[a - h][b - h * h] + 1){
                    s += char('0' + h);
                    a -= h;
                    b -= h * h;
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
