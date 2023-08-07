#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn = 100 + 5, mod = 1e9 + 7;
int n, m;
char s[maxn][15];
int ss[maxn], num[maxn];
int dp[maxn][maxn][maxn];

bool check(int x, int st) {
  for (int i = 0; i < m; ++i) {
    if ((st & (1 << i)) && s[x][i + 1] == 'H')
      return false;
  }
  return true;
}

int cal(ll num) {
  int tot = 0;
  while (num) {
    tot += num & 1;
    num >>= 1;
  }
  return tot;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> (s[i] + 1);
  }
  int cnt = 0;
  for (int i = 0; i < (1 << m); ++i) {
    if (!(i & (i << 1)) && !(i & (i << 2)))
      ss[++cnt] = i;
  }
  for (int i = 1; i <= cnt; ++i) {
    num[i] = cal(ss[i]);
    if (check(1, ss[i])) {
      dp[1][i][1] = num[i];
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= cnt; ++j) {
      if (check(i, ss[j])) {
        for (int k = 1; k <= cnt; ++k) {
          for (int l = 1; l <= cnt; ++l) {
            if (!(ss[j] & ss[k]) && !(ss[j] & ss[l]))
              dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][k][l] + num[j]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 1; j <= cnt; ++j) {
      ans = std::max(ans, dp[n][i][j]);
    }
  }
  std::cout << ans << endl;
  return 0;
}