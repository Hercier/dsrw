#include <cstdio>
#include <cstring>
#include <algorithm>
#include <random>
using namespace std;

const int maxn = 100000;
const int maxm = 100000;
const int maxr = 100000;

#define rand _rand
random_device rand;

int main(void) {
  int n = rand() % maxn + 1;
  printf("%d %d\n", n, m);

  int L = 0, R = rand() % maxr + 1;
  int L2 = L - max(5, R - L >> 1);
  int R2 = R + max(5, R - L >> 1);

  for (int i = 0; i < n; ++i) {
    int key = rand() % (R - L + 1) + L;
    int val = -1;  // not used
    printf("%d %d\n", key, val);
  }

  for (int i = 0; i < m; ++i) {
    int l = (int)(rand() % (R2 - L2 + 1)) + L2;
    int r = (int)(rand() % (R2 - L2 + 1)) + L2;
    if (l > r) swap(l, r);
    printf("%d %d\n", l, r);  // CAUTION do we need to deal with l > r?
  }
  return 0;
}
