//http://acm.timus.ru/problem.aspx?space=1&num=1049

#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt(10000, 0);

void update_prime(int number){
    for (int i = 2; i * i <= number; i++){
        while (number % i == 0){
            cnt[i]++;
            number /= i;
        }
    }
    if (number != 1)
        cnt[number]++;
    cout << endl;
    return;
}

int main()
{
    for (int i = 0; i < 10; i++){
        int current;
        cin >> current;
        update_prime(current);
    }

    long long ans = 1;

    for (int i = 0; i < 10000; i++){
        ans *= cnt[i] + 1;
        ans %= 10;
    }

    cout << ans;
    return 0;
}
