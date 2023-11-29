#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define pf push_front
#define x first
#define y second
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define sortall(x) sort(all(x))
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pii> vpii;


const int INF = 0x3f3f3f3f;

// g++ -std=c++17 fourValuesSum.cpp -o fourValuesSum && time ./fourValuesSum < input.txt


void solve(){
  int samples;
  
  cin >> samples;
  unordered_map<long long,long long> dictAB;
  vector<long long> As;
  vector<long long> Bs;
  vector<long long> Cs;
  vector<long long> Ds;
  int range = samples;

  while (samples--) {
    long long A;     long long B;     long long C;     long long D;
    cin >> A >> B >> C >> D;
    As.push_back(A); Bs.push_back(B); Cs.push_back(C); Ds.push_back(D);
  }

  vector<long long> arrAB;
  vector<long long> arrCD;

  for (int i = 0; i < range; i++) {
    for (int j = 0; j < range; j++) {
      arrAB.push_back(As[i]+Bs[j]);
      arrCD.push_back(Cs[i]+Ds[j]);
    }
  }

  for (long long x: arrAB) {
    dictAB[x] ++;
  }

  long long result = 0;

  // sortall(arrCD);

  // for (int x: arrAB) {
  //   result += upper_bound(all(arrCD), -x) - lower_bound(all(arrCD), -x);
  // }
  
  for (int x: arrCD) {
    result += dictAB[-x];
  }

  cout << result << endl;
 
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}