#include <bits/stdc++.h>

#define sz(a) (int)a.size()
  
using namespace std;
 
const int maxn = 200; 

struct state
{  
  int l, r, cnt;
  state() {}
  state(int a, int b, int c) {l = a, r = b, cnt = c;}
};

string s;
int d[maxn][maxn];
state pr[maxn][maxn];
bool was[maxn][maxn];
string answer[maxn][maxn];

int digits(int n) {
  int ans = 0;
  while (n > 0)
    ans++, n /= 10;
  return ans;   
}

string get_ans(int l, int r)
{
  if (was[l][r])
    return answer[l][r];
  was[l][r] = true;
  string ans = "";
  state p = pr[l][r];
  if (p.l == -1 && p.r == -1) {
    string tmp = s.substr(l, r - l + 1);
    answer[l][r] = tmp;
    return tmp;
  }
  if (p.r == -1) {
    string tmp = get_ans(l, p.l) + get_ans(p.l + 1, r);
    answer[l][r] = tmp;
    return tmp;
  }
  ans = to_string(p.cnt) + '(' + get_ans(p.l, p.r) + ')';
  answer[l][r] = ans;
  return ans;
}

int main() {
  getline(cin, s);
  {
    int length = sz(s);
    for (int i = 0; i < length; i++)
      for (int j = 0; j < length; j++)
        d[i][j] = 1e9 + 100, pr[i][j] = state(-1, -1, 1);
    for (int len = 1; len <= length; len++) {
      for (int i = 0; i <= length - len; i++) {
        int j = i + len - 1;
        d[i][j] = len;
        pr[i][j] = state(-1, -1, 1);
        for (int sub_len = 1; sub_len < len - 1; sub_len++) {
          int now = i;
          bool ok = true;
          int cnt = 1;
          while (now + sub_len < j + 1) {
            if (s.substr(now, sub_len) != s.substr(now + sub_len, sub_len)) {
              ok = false;
              break;
            }
            now += sub_len;
            cnt++;
          }
          int val = d[i][i + sub_len - 1] + digits(cnt) + 2 + d[i + sub_len * cnt][j];
          state st = state(i, i + sub_len - 1, cnt);
          if (val > sub_len * cnt + d[i + sub_len * cnt][j]) {
          	val = sub_len * cnt + d[i + sub_len * cnt][j];
          	st = state(i + sub_len * cnt - 1, -1, 1);
          }                                   
          if (ok && d[i][j] > val) {
            d[i][j] = val;
            pr[i][j] = st;
          }
        }
      }
    }
    printf("%s\n", get_ans(0, length - 1).c_str());
  }
  return 0;
}