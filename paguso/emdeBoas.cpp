#include <bits/stdc++.h>
using namespace std;

typedef uint32_t llu;

// g++ -std=c++17 emdeBoas.cpp -o emdeBoas && time ./emdeBoas < input.txt

class VEB
{
public:
  llu m, M;
  
  VEB *summary;  
  VEB *cluster;
  llu u;

  VEB(llu M) {

  }

  void insert(VEB V, llu x)
  {
    if(V.u == 2) {
      V.m = min(V.m, x);
      V.M = max(V.M, x);
      return;
    } 
    if (V.m == V.u) {
      V.m, V.M = x ,x;
      return;
    }
    if (x < V.m) {
      llu aux;
      aux = V.m;
      V.m = x;
      x = aux;
    }

    V.M = max(V.M, x);

    llu subSize = (llu)sqrt(u);
    llu h = x / subSize, l = x % subSize;

    if (V.cluster[h].m == V.cluster[h].u) {
      insert(*(V.summary), h);
    }
    insert(V.cluster[h], l);
  }

  float lowerSqrt ( int val )
  {
    return pow ( 2, floor ( log2 ( val )  / 2 ) );
  }

  int index ( VEB * tree, int high, int low )
  {
    return high * lowerSqrt ( tree->u ) + low;
  }

  void remove(VEB V, llu x)
  {
    if (V.u == 2) {
      if (x == V.m) {
        if (V.M != V.m) {
          V.m = V.M;
        } else {
          // n sei se ta certo
          V.m = V.u;
        }
      }
      if (x == V.M) {
        if (V.m != V.u) {
          V.M = V.m;
        } else {
          V.M = (-1);
        }
      }
      return;
    }
    if (x == V.m) {

      llu i = V.summary->m;
      if (i == V.summary->u){
        V.m, V.M = V.u, -1;
        return;
      } else {
        // V.m = V.index(i, V.cluster[i].m);
        x = V.m;
      }
    }
    llu subSize = (llu)sqrt(u);
    llu h = x / subSize, l = x % subSize;
    remove(V.cluster[h], l);

    if (V.cluster[h].m == V.cluster[h].u) {
      remove(*(V.summary), h);
    }

    if(x == V.M) {
      llu i = V.summary->M;
      if (i == -1) {
        V.M = V.m;
      } else {
        V.M = index(&V, i, V.cluster[i].M);
      }
    }
  }



  llu sucessor(VEB V, llu x)
  {
    if (V.u == 2) {
      if (x == -1 && V.m == 0) return 0;
      else if (x <= 0 && V.M == 1) return 1;
      else return V.u;
    }
    llu subSize = (llu)sqrt(u);
    llu h = x / subSize, l = x % subSize;

    if (l < V.cluster[h].M) {
      llu s = sucessor(V.cluster[h], l);
      return index(&V, h, s);
    } else {
      llu h = sucessor(*(V.summary), h);
      if (h == V.summary->u) {
        return V.u;
      } else {
        llu s = V.cluster[h].m;
        return index(&V, h, s);
      }
    }
    // return 1;
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

llu pow2(int M) {
    if (M == 0) {
        return 1;
    } else {
        return 1LL << (1 << (M - 1));
    }
}

void solve()
{
  uint32_t S, M, B, N, I, F, D, P;

  while (cin >> S >> M >> B >> N >> I >> F >> D >> P)
  {

    cout << S << M << B << N << I << F << D << P;

    RNG rng(S);

    llu U = pow2(M);
    VEB T(U);
    
    T.insert(T, S%U);

    for (llu i = 0; i < B; i++) {
      T.insert(T, rng.next()%U);
    }

    llu X = rng.next() % (I+F+D);
    if (X < I) {
      X = rng.next() % U;
      T.insert(T, X);
    } else if (I <= X && X < (I+F)) {
      X = rng.next() % U;
      T.sucessor(T, X);
    } else {
      llu Y = rng.next() % U;
      llu aux = T.sucessor(T, Y);
      if (aux) {
        X = aux;
      } else {
        X = Y;
      }
      T.remove(T, X);
    }
  }
}



int main()
{
  solve();
  return 0;
}