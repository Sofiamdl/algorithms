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
  deque<int> adaQueue;
  int runAmount;
  string entrada;
  int toPush;
  bool reverse;
  reverse = false;

  cin >> runAmount;

  while (runAmount--) 
  {
    cin >> entrada;

    // cout << runAmount << entrada << endl;
    
    if (entrada == "back") {
      if (adaQueue.empty()){
        cout << "No job for Ada?" << endl;
      } else if (reverse) {
        cout << adaQueue.front() << endl;
        adaQueue.pop_front();
      } else {
        cout << adaQueue.back() << endl;
        adaQueue.pop_back();
      };
    } else if (entrada == "front") {
      if (adaQueue.empty()){
        cout << "No job for Ada?" << endl;
      } else if (reverse) {
        cout << adaQueue.back() << endl;
        adaQueue.pop_back();
      } else {
        cout << adaQueue.front() << endl;
        adaQueue.pop_front();
      };
    } else if (entrada == "push_back") {
      cin >> toPush;

      if (reverse) {
        adaQueue.push_front(toPush);
      } else {
        adaQueue.push_back(toPush);
      };
    } else if (entrada == "toFront") {
      cin >> toPush;

      if (reverse) {
        adaQueue.push_back(toPush);
      } else {
        adaQueue.push_front(toPush);
      };
    } else if (entrada == "reverse") {
      reverse = !reverse;
    }
  }
  
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}
