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

// g++ -std=c++17 addAll.cpp -o addAll && time ./addAll < input.txt

void solve(){

  int number;
  int otherNumber;
  int value;
  int value2;
  int totalSum;

  while(cin >> number && number) {

  priority_queue<int, vector<int>, greater<int> > pq;

    while (number--) {
      cin >> otherNumber;

      pq.push(otherNumber);
    }
    totalSum = 0;

    while (pq.size() > 1)
    { 
      value = pq.top();
      pq.pop();

      value2 = pq.top();
      pq.pop();

      pq.push(value+value2);

      totalSum = totalSum+value+value2;
    }

    cout << totalSum << endl;

  }

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}