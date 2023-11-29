#include <bits/stdc++.h>
using namespace std;

typedef uint32_t ll;
int counter = 0;

class SparseTable
{
public:
  uint32_t N;
  uint32_t NLOG;

  static uint32_t minn(uint32_t a, uint32_t b) { return (a < b) ? a : b; }
  static uint32_t maxx(uint32_t a, uint32_t b) { return (a > b) ? a : b; }
  static uint32_t summ(uint32_t a, uint32_t b) { return a + b; }
  ll starter;

  uint32_t (*func)(uint32_t, uint32_t);

  ll **st;

  SparseTable(string op, ll *array, uint32_t n, uint32_t nlog)
  {
    N = n;
    NLOG = nlog;

    if (op == "MAX")
    {
      func = maxx;
      starter = numeric_limits<ll>::min();
    }
    else if (op == "MIN")
    {
      func = minn;
      starter = numeric_limits<ll>::max();
    }
    else
    {
      func = summ;
      starter = 0;
    }

    st = new ll *[NLOG];

    for (int i = 0; i < NLOG; i++)
    {
      st[i] = new ll[N];
    }

    for (int j = 0; j < N; j++)
    {
      st[0][j] = array[j];
    }

    precompute();
    return;
  }

  void precompute()
  {
    for (int i = 1; i < NLOG; i++)
      for (int j = 0; j + (1 << i) <= N; j++)
      {
        st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    return;
  }

  ll query(ll left, ll right)
  {
    ll result = starter;

    int l = (int)left;
    int r = (int)right;

    while (l < r)
    {
      double indAux = log2(r - l);
      int index = (int)indAux;

      result = func(result, st[index][l]);

      l += pow(2, index);
    }
    return result;
  }

  void update(ll newValue, int indAux)
  {
    int index = indAux;
    st[0][index] = newValue;

    int k = 1;

    for (int i = 1; i < NLOG; i++)
    {
      int lAux = (int)max(0, index - (2 * k) + 1);

      for (int l = lAux; l <= index; l++)
      {
        if (l + k >= N)
        {
          st[i][l] = st[i - 1][l];
        }
        else
        {
          st[i][l] = func(st[i - 1][l], st[i - 1][l + k]);
        }
      }
      k *= 2;
    }
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
  uint32_t S, N, O, Q, U;
  string F;

  while (cin >> S >> N >> F >> O >> Q >> U)
  {

    uint32_t MAXLOG = log2(N) / 1 + 1;

    uint32_t st[MAXLOG][N];

    ll *arr = new ll[N];

    ll M = 4 * N;

    arr[0] = S % M;

    RNG rng(S);

    for (int i = 1; i < N; i++)
    {
      arr[i] = rng.next() % M;
    }

    SparseTable sparseTable(F, arr, N, MAXLOG);

    cout << "caso " << counter << endl;

    for (int i = 0; i < O; i++)
    {
      ll X = rng.next();

      if (X % (Q + U) < Q)
      {
        ll L = rng.next() % N;
        ll R = L + 1 + (rng.next() % (N - L));
        cout << sparseTable.query(L, R) << '\n';
      }
      else
      {
        ll I = rng.next() % N;
        ll V = rng.next() % M;

        sparseTable.update(V, I);

        cout << sparseTable.query(I, N) << '\n';
      }
    }

    counter++;
    std::cout << '\n';
  }
}

int main()
{
  solve();
  return 0;
}