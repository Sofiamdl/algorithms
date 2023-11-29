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

// g++ -std=c++17 main.cpp -o main && time ./main < input.txt

void solve(){
  int finalAmount;
  int result = 1;

  cin >> finalAmount;

  while (finalAmount > 1) {
  
    result += finalAmount % 2;

    finalAmount = finalAmount/2;
  }
  cout << result << endl;
    
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}