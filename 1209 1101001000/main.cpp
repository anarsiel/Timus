//http://acm.timus.ru/problem.aspx?space=1&num=1209

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    long long i = 1;
    long long to_plus = 0;
    while(i < 2147483648){
        i += to_plus++;
        s.insert(i);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        cout << s.count(h) << ' ';
    }
    return 0;
}
