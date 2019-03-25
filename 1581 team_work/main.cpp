//http://acm.timus.ru/problem.aspx?space=1&num=1581

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int last;
    cin >> last;
    if (n == 1){
        cout << 1 << ' ' << last;
        return 0;
    }
    int cnt = 1;
    for (int i = 0; i < n - 1; i++){
        int h;
        cin >> h;
        if (h == last){
            cnt++;
        }else{
            cout << cnt << ' ' << last << ' ';
            cnt = 1;
            last = h;
        }
    }
    cout << cnt << ' ' << last << ' ';
    return 0;
}
