#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > stars;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }
    sort(stars.begin(), stars.end());
    for (int i = 0; i < n; i++){
        int current = 1;
        int last = stars[i].first;
        while ()
    }
    return 0;
}
