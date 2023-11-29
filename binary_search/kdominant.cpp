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

// g++ -std=c++17 kdominant.cpp -o kdominant && time ./kdominant < input.txt

bool tester(string string, int mid) {
  for (int ch = 0; ch < 26; ch++) {
    char c = 'a' + ch;
    int counter = 0;
    bool found = true;

    for (auto y: string){
      if (counter < mid) {
        if (c==y) {
          counter = 0;
        } else {
          counter++;
        }
      } else {
        found = false;
        break;
      }
    }
    if (counter < mid) {
      if (found == true) return true;
    }


  }
  return false;
}

void solve(){
  string mainString;
  cin >> mainString;

  int right; int left;

  right = mainString.size();
  left = 1;

  while (right > left) {
    int mid = left + ((right - left) >> 1);
    if (tester(mainString, mid)) {
      right = mid;
    } else {
      left = mid +1;
    }
  }
  cout << left << endl;



}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}