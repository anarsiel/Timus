#include <iostream>
#include <cmath>

using namespace std;

bool sq_n(long long n){
    int m = sqrt(n);
    for (int i = m - 1; i <= m + 1; i++){
        if (1LL * i * i == n)
            return 1;
    }
    return 0;
}

bool sq2_n(long long n){
    for (long long i = 1; i * i <= n / 2; i++){
        if (sq_n(n - i * i))
            return 1;
    }
    return 0;
}

bool sq3_n(long long n){
    while (n % 4 == 0)
        n /= 4;
    n -= 7;
    return !(n % 8 == 0);
}

int main()
{
    long long n;
    cin >> n;
    if (sq_n(n)){
        cout << 1;
        return 0;
    }
    if (sq2_n(n)){
        cout << 2;
        return 0;
    }
    if (sq3_n(n)){
        cout << 3;
        return 0;
    }
    cout << 4;
    return 0;
}
