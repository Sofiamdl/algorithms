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

// g++ -std=c++17 array.cpp -o array && time ./array < input.txt

bool tester(vector<unsigned long long> array, unsigned long long sumToSearch, unsigned long long k) {
  unsigned long long subarr = 0;
  unsigned long long currentSum = 0;

  for (unsigned long long x: array) {
    if (x > sumToSearch) return false;

    if (x+currentSum > sumToSearch) {
      currentSum = 0;
      subarr += 1;
    }
    currentSum += x;     
  }

  if (currentSum > 0 ) subarr += 1;

  return subarr <= k;
}

void solve(){
  unsigned long long arrayLen;
  unsigned long long k;
  cin >> arrayLen >> k;
  vector<unsigned long long> array;

  unsigned long long right = 0;
  unsigned long long left = 1;

  while (arrayLen--) {
    unsigned long long elem;
    cin >> elem;
    array.push_back(elem);
    right += elem;
  }

  while (right > left) {
    unsigned long long mid = (right + left) / 2;
    if (tester(array, mid, k)) {
      right = mid;
    } else {
      left = mid+1;
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