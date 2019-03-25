//http://acm.timus.ru/problem.aspx?space=1&num=1073

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 1; i + j * j <= n; j++){
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }

    /*for (int i = 0; i < n + 1; i++)
        cout << dp[i] << ' ';
    cout << endl;*/

    cout << dp[n];
    return 0;
}
