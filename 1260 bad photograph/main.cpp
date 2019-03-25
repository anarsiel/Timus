#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    if (n == 1){
        cout << 1;
        return 0;
    }
    if (n == 2){
        cout << 1;
        return 0;
    }
    if (n == 3){
        cout << 2;
        return 0;
    }
    v[1] = 1;
    v[2] = 1;
    v[3] = 2;
    for (int i = 3; i <= n; i++){
        v[i] = v[i - 1] + v[i - 3] + 1;
    }
    cout << v[n];
    return 0;
}
