#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> keys;

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int k, v;
    scanf("%d%d", &k, &v);
    keys.push_back(k);
  }
  sort(keys.begin(), keys.end());
  keys.erase(unique(keys.begin(), keys.end()), keys.end());
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = lower_bound(keys.begin(), keys.end(), r) -
              lower_bound(keys.begin(), keys.end(), l);
    if (l >= r)
      ans = 0;
    printf("%d\n", ans);
  }
  return 0;
}
