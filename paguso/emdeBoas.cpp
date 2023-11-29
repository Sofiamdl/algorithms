#include <bits/stdc++.h>
using namespace std;

typedef uint32_t llu;

// g++ -std=c++17 emdeBoas.cpp -o emdeBoas && time ./emdeBoas < input.txt

class VEB
{
public:
  llu *m, *M;
  *(V.m) = 2;
  VEB *summary;  
  VEB **cluster;
  llu u;

  void insert(VEB V, llu x)
  {
    if(V.u == 2) {
      *(V.m) = min(*(V.m), x);
      cout << *(V.m);
    }
  }

  void remove()
  {
  }

  llu sucessor()
  {
    return 1;
  }
};

class RNG
{
public:
  RNG(uint32_t S) : current(S) {}

  uint32_t next()
  {
    unsigned long long num = 1ULL << 32;
    current = (1664525 * current + 1013904223) % num;
    return current;
  }

private:
  uint32_t current;
};

void solve()
{
  uint32_t S, M, B, N, I, F, D, P;

  while (cin >> S >> M >> B >> N >> I >> F >> D >> P)
  {

    cout << S << M << B << N << I << F << D << P;

    RNG rng(S);
  }
}

int main()
{
  solve();
  return 0;
}