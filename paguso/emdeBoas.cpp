#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class VEB
{
public:
  ll m, M;
  
  VEB *summary;  
  VEB **cluster;
  ll u;
  ll subSize;

  VEB(ll U) {
    u = U;
    m = U;
    M = -1;
    subSize = (ll)sqrt(u);
    
    if (u == 2)
    {
      this -> summary = NULL;
      this -> cluster = NULL;
    }
    
    else
    {
      summary = new VEB(subSize);
      cluster = new VEB*[subSize];
      for ( int i = 0; i < subSize; ++i ) cluster[i] = new VEB(subSize);
    }
  }

  ll insert(ll x)
  {
    if (x == m || x == M) {
      return 0;
    }

    if(u == 2) {
      m = min(m, x);
      M = max(M, x);
      return 1;
    } 

    if (m == u) {
      m = x;
      M = x;
      return 1;
    }

    if (x < m) {
      swap(x, m);
    }

    M = max(M, x);

    ll h = x / subSize, l = x % subSize;
    
    
    if (cluster[h]->m == cluster[h]->u) {
      summary->insert(h);
    }
    ll aux2 = cluster[h]->insert(l);
    if (aux2 == 0) return 0;
    return aux2+1;
  }

  ll index ( ll high, ll low )
  {
    return high * subSize + low;
  }

  ll sucessor(ll x)
  {
    if (x < m) {
      return m;
    }    

    if (x > M) {
      return u;
    }       

    if (u == 2) {
      if (x == 0 && M == 1) return 1;
      else return 2;
    }
     
    ll h = x / subSize;
    ll l = x % subSize;
    
    if (l < cluster[h]->M) {
      ll s = cluster[h]->sucessor(l);
      return index(h, s);
    } else {
      h = summary->sucessor(h);
      if (h == summary->u) {
        return u;
      } else {
        ll s = cluster[h]->m;
        return index(h, s);
      }
    }
  }


   ll remove(ll x)
  {
    ll aux = 0;

    if (u == 2) {
      if (x == m) {
        aux = 1;
        m = M != m ? M : u;
      }
      if (x == M) {
        aux = 1;
        M = m != u ? m : -1;
      }
      return aux;
    }

    if (x == m) {

      ll i = summary->m;
      if (i == summary->u){
        m = u;
        M = -1;
        return 1;
      } 

      m = index(i, cluster[i]->m);
      x = m;
    }

    ll h = x / subSize, l = x % subSize;

    ll aux2 = (cluster[h]->remove(l));
    if (aux2 != 0) aux = aux + aux2 + 1;

    if (cluster[h]->m == cluster[h]->u) {
      summary->remove(h);
    }

    if(x == M) {
      ll i = summary->M;
      if (i == -1) {
        M = m;
      } else {
        M = index(i, cluster[i]->M);
      }
    }
    return aux;
  }
};



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



ll pow2(ll M) {
  if (M == 0) {
    return 1;
  } else {
    return 1 << (1 << (M ));
  }
}

void solve()
{
  ll S, M, B, N, I, F, D, P;

  while (cin >> S >> M >> B >> N >> I >> F >> D >> P)
  {
    RNG rng(S);

    ll U = pow2(M);

    VEB T(U);

    for (ll i = 0; i < B; i++) {
      T.insert(rng.next()%U);
    }

    for (ll i = 0; i < N; i++){
      ll X = rng.next() % (I+F+D);

      if (X < I) {
        ll x = rng.next() % U;
        ll result = T.insert(x);
        if(i % P == 0) cout << "I " << result << endl;
      } else if (I <= X && X < (I+F)) {
       ll X = rng.next() % U;

        if(i % P == 0) cout << "S " << T.sucessor(X) << endl;
      } else {
        ll Y = rng.next() % U;
        ll aux = T.sucessor(Y);
        if (aux < U) {
          X = aux;
        } else {
          X = Y;
        }
        ll result = T.remove(X);
        if(i % P == 0) cout << "D " << result << endl;
      }
    }

  }
}



int main()
{
  solve();
  return 0;
}