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

// g++ -std=c++17 angry.cpp -o angry && time ./angry < input.txt

bool tester(vector<unsigned long long> array, unsigned long long elem, unsigned long long stall) {
  unsigned long long distance = 0;
  unsigned long long lastNum = 0;
  unsigned long long cowNum = 0;

  for (unsigned long long x: array){
    if (lastNum == 0) {
      lastNum = x;
    } else if (distance + x - lastNum <= elem) {
      distance += x - lastNum;
      lastNum = x;
    } else {
      lastNum = x;
      distance = 0;
      cowNum++;
    }
  }
  cowNum++;
  return (cowNum >= stall);
}

void solve(){
  unsigned long long testCase;
  cin >> testCase;
  
  while (testCase--) {
    unsigned long long stalls;
    unsigned long long cows;
    cin >> stalls >> cows;
    vector<unsigned long long> stallPlace;

    unsigned long long sum = 0;

    while (stalls--) {
      unsigned long long elem;
      cin >> elem;
      stallPlace.push_back(elem);
      sum += elem;
    }

    sortall(stallPlace);

    unsigned long long left = 1;
    unsigned long long right = sum;

    while (right > left) {
      unsigned long long mid = left + ((right - left) >> 1);
      
      if (tester(stallPlace, mid,cows )){
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    cout << left << endl;

  }

  

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}