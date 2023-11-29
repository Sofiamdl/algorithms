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

// g++ -std=c++17 factoryMac.cpp -o factoryMac && time ./factoryMac < input.txt

bool tester(vector<unsigned long long> array, unsigned long long t, unsigned long long product) {
  unsigned long long sum = 0;

  for (int x: array) {
    sum += t/x;
  }

  // cout << sum<< endl;

  return (sum >= product);
}

void solve(){
  int numMachines;
  unsigned long long products;
  cin >> numMachines >> products;

  vector<unsigned long long> array;

  unsigned long long right = 0;
  unsigned long long left = 1;

  while (numMachines--) {
    int elem;
    cin >> elem;
    array.push_back(elem);

    right = products*elem;
  }
  
  while (right > left) {
    unsigned long long mid = (right+left)/2;
    
    if (tester(array, mid, products)) {
      right = mid;
    }
    else {
      left = mid + 1;
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