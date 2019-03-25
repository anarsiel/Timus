#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> fib(n + 2);
    fib[0] = 1;
    fib[1] = 1;
    string s = "";
    for (int i = 2; i < n + 2; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = n; i > 0; i--){
        int sp = fib[i];
        if (sp < k){
            k -= sp;
            sp = fib[i - 1];
            if (sp < k){
                cout << -1;
                return 0;
            }else{
                s += "1";
            }
        }else{
            s += "0";
        }
    }
    cout << s;
    return 0;
}
