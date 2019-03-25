//http://acm.timus.ru/problem.aspx?space=1&num=1639

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (!((n * m) % 2))
        cout << "[:=[first]";
    else
        cout << "[second]=:]";
    return 0;
}
