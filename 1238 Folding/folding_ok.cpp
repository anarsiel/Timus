#include <bits/stdc++.h>

#define inf int(1e9)
#define forn(i, x, y) for (int i = (x); i <= (y); i++)
#define sz(a) (int)a.size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;

const int MaxN = 200;

struct state
{  
  int l, r, cnt;
  state() {}
  state(int a, int b, int c) {l = a, r = b, cnt = c;}
};

string s;
int d[MaxN][MaxN];
state pr[MaxN][MaxN];
bool was[MaxN][MaxN];
string answer[MaxN][MaxN];

inline int digits(int n)
{
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
  if (p.l == -1 && p.r == -1)
  {
    string tmp = s.substr(l, r - l + 1);
    answer[l][r] = tmp;
    return tmp;
  }
  if (p.r == -1)
  {
    string tmp = get_ans(l, p.l) + get_ans(p.l + 1, r);
    answer[l][r] = tmp;
    return tmp;
  }
  ans = to_string(p.cnt) + '(' + get_ans(p.l, p.r) + ')';
  answer[l][r] = ans;
  return ans;
}

int main()
{
  while (getline(cin, s))
  {
    int length = sz(s);
    forn(i, 0, length)
      forn(j, 0, length)
        d[i][j] = inf, pr[i][j] = state(-1, -1, 1);
    forn(len, 1, length)
    {
      forn(i, 0, length - len)
      {
        int j = i + len - 1;
        d[i][j] = len;
        pr[i][j] = state(-1, -1, 1);
        forn(sub_len, 1, len - 1)
        {
          if (len % sub_len != 0)
            continue;
          int now = i;
          bool ok = true;
          int cnt = 1;
          while (now + sub_len < j + 1)
          {
            if (s.substr(now, sub_len) != s.substr(now + sub_len, sub_len))
            {
              ok = false;
              break;
            }
            now += sub_len;
            cnt++;
          }
          assert(!ok || now + sub_len == j + 1);
          if (ok && d[i][j] > d[i][i + sub_len - 1] + digits(cnt) + 2)
          {
            d[i][j] = d[i][i + sub_len - 1] + digits(cnt) + 2;
            pr[i][j] = state(i, i + sub_len - 1, cnt);
          }
        }
        forn(k, i, j - 1)
        {
          if (d[i][j] > d[i][k] + d[k + 1][j])
          {
            d[i][j] = d[i][k] + d[k + 1][j];
            pr[i][j] = state(k, -1, 1);
          }
        }
      }
    }
    forn(i, 0, length - 1)
      forn(j, 0, length - 1)
        was[i][j] = false;
    printf("%s\n", get_ans(0, length - 1).c_str());
  }
  return 0;
}