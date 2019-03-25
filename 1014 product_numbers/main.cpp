//http://acm.timus.ru/problem.aspx?space=1&num=1014

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 1;
    if (n == 0){
        cout << 10;
        return 0;
    }
    vector<int> v;
    for (int i = 9; i > 1; i--){
        while (n % i == 0){
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 9){
        cout << -1;
        return 0;
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    return 0;
}
