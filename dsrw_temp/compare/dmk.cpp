#include <cstdio>
#include <cstring>
#include <algorithm>
#include <random>
using namespace std;

const int maxn = 10000000;
const int maxm = 300;
const int maxr = 1000000000;

#define rand _rand
random_device rand;

int main(void) {
  int n = maxn;
  printf("%d\n", n);

  int L = 0, R = rand() % maxr + 1;
  int L2 = L - max(5, R - L >> 1);
  int R2 = R + max(5, R - L >> 1);

  for (int i = 0; i < n; ++i) {
    char op=(rand()%2)?'i':'r';
    int a,b;
    if(op=='i'){
        a = rand() % (R - L + 1) + L;
        b = -1;  // not used
    }
    else{
      a = (int)(rand() % (R2 - L2 + 1)) + L2;
      b = (int)(rand() % (R2 - L2 + 1)) + L2;
      if(a>b)swap(a,b);
    }
    printf("%c %d %d\n", op, a,b);
  }
  return 0;
}
