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

// g++ -std=c++17 sumOfTwo.cpp -o sumOfTwo && time ./sumOfTwo < input.txt


void solve(){
  int size;
  int sum;
  cin >> size >> sum;

  map<int, int> dict;

  int counter = 0;
  bool didntFound = true;


  while (size--) {
    int elem;
    cin >> elem;
    counter ++;

    if (dict.count(elem)) {
      cout << dict[elem] << " " << counter << endl;
      didntFound = false;
      break;
    } else {
      dict[sum-elem] = counter;
    }

  }
  if (didntFound) {
    cout <<  "IMPOSSIBLE" << endl;
  }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}