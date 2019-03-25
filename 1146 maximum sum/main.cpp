#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int h;
            cin >> h;
            v[i].push_back(h);
        }
    }
    vector<vector<int> > pref1(n), pref2(n);

    for (int i = 0; i < n ; i++){
        pref1[i].resize(n);
        pref2[i].resize(n);
    }

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == 0 && j == 0){
                pref1[i][j] = v[i][j];
            }else{
                if (i == 0){
                    pref1[i][j] = pref1[i][j] + pref1[i][j - 1] + v[i][j];
                    continue;
                }

                if (j == 0){
                    pref1[i][j] = pref1[i][j] + pref1[i - 1][j] + v[i][j];
                    continue;
                }
                pref1[i][j] = pref1[i - 1][j] + pref1[i][j - 1] - pref1[i - 1][j - 1] + v[i][j];
            }
        }
    }

    /*cout << endl;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << pref1[i][j] << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < n; i++){
        for(int j = n - 1; j > -1; j--){
            if (i == 0 && j == n - 1){
                pref2[i][j] = v[i][j];
            }else{
                if (i == 0){
                    pref2[i][j] = pref2[i][j] + pref2[i][j + 1] + v[i][j];
                    continue;
                }

                if (j == n - 1){
                    pref2[i][j] = pref2[i][j] + pref2[i - 1][j] + v[i][j];
                    continue;
                }
                pref2[i][j] = pref2[i - 1][j] + pref2[i][j + 1] - pref2[i - 1][j + 1] + v[i][j];
            }
        }
    }

    /* cout << endl;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << pref2[i][j] << " ";
        }
        cout << endl;
    }*/
    //bool g = false;
    int answ = -1e9 - 7;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    if (i > k || j > l)
                        continue;
                    int a, b, c;
                    if (j == 0)
                        a = 0;
                    else
                        a = pref1[k][j - 1];

                    if (i == 0)
                        b = 0;
                    else
                        b = pref1[i - 1][l];

                    if (i == 0 || j == 0)
                        c = 0;
                    else
                        c = pref1[i - 1][j - 1];
                    int current = pref1[k][l] - a - b + c;
                    answ = max(answ, current);
                    /*if ((answ == 17) && (!g)){
                        g = true;
                        cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
                    }*/
                }
            }
        }
    }

    cout << answ;

    return 0;
}
