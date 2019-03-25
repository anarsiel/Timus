#include <iostream>

using namespace std;

int pow(int number, int power){
    if (power == 0)
        return 1;
    if (power == 1)
        return number;
    if (power % 2 == 0){
        int a = pow(number, power / 2);
        return a * a;
    }
    return number * pow(number, power - 1);
}

int main()
{
    long long n;
    cin >> n;
    long long m = 1;
    long long k = 1;
    for (long long i = 2; i * i <= n; i++){
        long long cnt = 0;
        while (n % i == 0){
            //cout << i << ' ';
            cnt++;
            n /= i;
        }
        if (cnt % 2)
            k *= i;
        m *= pow(i, (cnt + 3 * (cnt % 2)) / 2);
    }
    k *= n;
    m *=  n * n;
    cout << m << '\n' << k;
    return 0;
}
