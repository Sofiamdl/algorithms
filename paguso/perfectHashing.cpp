#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class RNG
{
public:
  bool isFirst = true;

  RNG(ll S) : current(S) {}

  ll next()
  {
    if (isFirst) {
      isFirst = false;
      return current;
    }
    long long num = 1ULL << 32;
    current = (1664525 * current + 1013904223) % num;
    return current;
  }

private:
  ll current;
};

ll const P = (1u << 31) - 1;

class OpenHashTable
{
  public:
  ll M = 0;
  RNG *rng;

  vector<ll>* table;
  function<ll(ll)> H;
  ll N = 0;

  OpenHashTable(ll Minput, RNG *rngInput) {
    rng = rngInput;
    M = Minput;
    table = new vector<ll>[M];
    ll a = 1 + rng->next() % (P - 1);
    ll b = rng->next() % P;
    H= [=](ll x) { return ((a * x + b) % P) % M; };
  }

  ll get(ll K)
  {
    ll i = H(K);

    for(ll j = 0; j < table[i].size(); j++)
      if(table[i][j] == K)
        return j;
    return -1;
  }

  pair<ll, ll> set(ll K, bool flag = false)
  {
    ll j = get(K);

    if (flag || j == -1) {
      if (2*N > M) rehash();

      ll position = H(K);
      table[position].push_back(K);
      N+=1;

      return {position, table[position].size() - 1};
    }

    ll position = H(K);
    return {position, j};
  }

  void rehash()
  {
    ll m = M;

    M = 2*M + 1;

    vector<ll>* t = table;
    table = new vector<ll>[M];

    ll a = 1 + rng->next() % (P - 1);
    ll b = rng->next() % P;
    H= [=](ll x) { return ((a * x + b) % P) % M; }; 

    for (ll i = 0; i < M; i++)
      for (ll j = 0; j < t[i].size(); j++)
        set(t[i][j], true);

    delete[] t;
  }

};

class PerfectHash
{
};



void solve()
{
  ll S, U, M0, I, Q, Pi, Pq;

  while (cin >> S >> U >> M0 >> I >> Q >> Pi >> Pq)
  {
    RNG rng(S);
    OpenHashTable T0(M0, &rng);

    for(int i = 0; i < I; i++)
    {
      int K = rng.next() % U;
      pair<int, int> result = T0.set(K);

      if(i % Pi == 0)
        cout << "I " <<  K << " " << result.first << " " << result.second << '\n';
    }


  }
}



ll main()
{
  solve();
  return 0;
}