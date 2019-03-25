#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long answ = 0;
    vector<vector<long long> > dp(n + 1);
    for (int i = 0; i < n + 1; i++)
        dp[i].resize(n + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int k = j + 1; k <= n - i; k++){
                dp[i + k][k] += dp[i][j];
            }
        }
    }

    /*for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/

    for (int i = 0; i < n; i++){
        answ += dp[n][i];
    }
    cout << answ;
    return 0;
}
