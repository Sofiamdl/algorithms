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

// g++ -std=c++17 frosh.cpp -o frosh && time ./frosh < input.txt

void solve(){
  int n;
  int number;

  while (cin >> n && n) {
    map< vector<int>, int> dict;
    int bigger = 0;
    int total = n;
    int amountToMultiply = 1;
    while (n--) {
      int amount = 5;
      vector<int> keyVector;

      while (amount--) {
        cin >> number;
        keyVector.push_back(number);
      }

      sortall(keyVector);


      if (dict.count(keyVector)) {
        dict[keyVector] += 1;
      } else {
        dict[keyVector] = 1;
      }

      if (dict[keyVector] > bigger) {
        bigger = dict[keyVector];
        amountToMultiply = 1;
      } else if (dict[keyVector] == bigger) {
        amountToMultiply += 1;
      }
    }

    if (bigger == 1) {
      cout << total << endl;
    } else {
      cout << bigger * amountToMultiply << endl;
    }
  }

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}