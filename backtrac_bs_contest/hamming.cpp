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

// g++ -std=c++17 hamming.cpp -o hamming && time ./hamming < input.txt

void backtrack(int clm, vector<int> number, int currentAmount, int distance) {
  if (currentAmount > distance) {
    return;
  }

  if (clm == number.size() && (currentAmount == distance)) {
    for (int i = 0; i < number.size(); i++) {
      cout << number[i];
    }
    cout << endl;
    return; 
  } else if (clm == number.size())  {
    return;
  }

  backtrack(clm+1, number, currentAmount, distance);
  vector<int> helper = number;
  helper[clm] = 1;
  currentAmount++;
  backtrack(clm+1, helper, currentAmount, distance);
  
}

void solve(){
  int dataset;

  cin >> dataset;

  while(dataset--){
    vector <int> number;
    int amount;
    int distance;

    cin >> amount >> distance;

    number.assign(amount, 0);

    backtrack(0, number, 0, distance);
    if (dataset != 0) {
      cout << endl;
    }
  }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}