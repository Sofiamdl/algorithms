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

// g++ -std=c++17 geo.cpp -o geo && time ./geo < input.txt

// bool tester(pair<int, int> laptop, pair<int, int> projector) {
//   int n1;
//   int n2;
//   int n3;
//   int n4;

//   n1 = projector.second + h + laptop.second + abs(laptop.first - projector.first);
//   n2 = d - projector.second + h + d - laptop.second +  abs(laptop.first - projector.first);
//   n3 = projector.first + h + laptop.first + abs(laptop.second - projector.second);
//   n4 = w - projector.first + h + w - laptop.first + abs(laptop.second - projector.second);

// }

void solve(){
  int testCase;
  cin >> testCase;

  while (testCase--) {
    int w; int d; int h;
    int a; int b; int f; int g;

    pair<int, int> laptop;
    pair<int, int> projector;

    cin >> w >> d >> h >> a >> b >> f >> g;

    laptop = make_pair(a, b);
    projector = make_pair(f,g);

    int n1;
    int n2;
    int n3;
    int n4;
    n1 = projector.second + h + laptop.second + abs(laptop.first - projector.first);
    int smaller = n1;
    n2 = d - projector.second + h + d - laptop.second +  abs(laptop.first - projector.first);
    if (n2 < smaller) {
      smaller = n2;
    }
    n3 = projector.first + h + laptop.first + abs(laptop.second - projector.second);
    if (n3 < smaller) {
      smaller = n3;
    }
    n4 = w - projector.first + h + w - laptop.first + abs(laptop.second - projector.second);
    if (n4 < smaller) {
      smaller = n4;
    }
    cout << smaller << endl;
  }

 




}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}