//http://acm.timus.ru/problem.aspx?space=1&num=1654

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.size(); i++){
        if (v.size() == 0){
            v.push_back(s[i]);
            continue;
        }
        if (v[v.size() - 1] == s[i])
            v.pop_back();
        else
            v.push_back(s[i]);
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    return 0;
}
