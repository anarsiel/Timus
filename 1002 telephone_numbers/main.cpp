//http://acm.timus.ru/problem.aspx?space=1&num=1002

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_numeber(string s){
    string out = "";
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'i' || s[i] == 'j')
            out += "1";
        if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
            out += "2";
        if (s[i] == 'd' || s[i] == 'e' || s[i] == 'f')
            out += "3";
        if (s[i] == 'g' || s[i] == 'h')
            out += "4";
        if (s[i] == 'k' || s[i] == 'l')
            out += "5";
        if (s[i] == 'm' || s[i] == 'n')
            out += "6";
        if (s[i] == 'p' || s[i] == 'r' || s[i] == 's')
            out += "7";
        if (s[i] == 't' || s[i] == 'u' || s[i] == 'v')
            out += "8";
        if (s[i] == 'w' || s[i] == 'x' || s[i] == 'y')
            out += "9";
        if (s[i] == 'o' || s[i] == 'q' || s[i] == 'z')
            out += "0";
    }
    return out;
}

int main()
{
    string s;
    while (cin >> s){
        if (s == "-1") {
            return 0;
        }
        int n;
        cin >> n;
        vector<string> v;
        vector<string> initial;
        for (int i = 0; i < n; i++){
            string ss;
            cin >> ss;
            initial.push_back(ss);
            ss = get_numeber(ss);
            v.push_back(ss);
            //cout << ss << '\n';
        }
        vector<int> pred(s.size() + 1, -1);
        vector<int> dp(s.size() + 1, 1e9);

        dp[0] = 0;
        for (int i = 1; i <= s.size(); i++){
            for (int j = 0; j < n; j++){
                if (i < v[j].size())
                    continue;
                if (v[j] == s.substr(i - v[j].size(), v[j].size())){
                    if (dp[i] > dp[i - v[j].size()] + 1){
                        dp[i] = dp[i - v[j].size()] + 1;
                        pred[i] = j;
                    }
                }
            }
        }
        //cout << "--------------------------------" << endl;
        for (int l = 0; l < dp.size(); l++){
            //cout << dp[l] << ' ';
        }
        //cout << endl << "--------------------------------" << endl;
        if (dp[s.size()] == 1e9){
            cout << "No solution." << endl;
            continue;
        }
        string answ = "";
        for (int i = s.size(); i > 0;){
            answ = initial[pred[i]] + " " + answ;
            i -= initial[pred[i]].size();
        }
        cout << answ << endl;
    }
    return 0;
}
