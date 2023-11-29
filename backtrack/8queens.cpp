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

// g++ -std=c++17 8queens.cpp -o 8queens && time ./8queens < input.txt
vector<int> chess;
int row; int column;
int solNum = 1;

bool isPossible(int clm, int rw) {
  for(int prev = 0; prev < clm; prev++){
    if (chess[prev] == rw || abs(chess[prev]-rw) == abs(prev-clm)) return false;
  }
  return true;
}
    
void backtrack(int clm) {
  if (chess[column] == row && clm == 8) {
    if (solNum == 1) {
      cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8" << endl;
      cout << endl;
    }
    if (solNum < 10) {
      cout << " "<< solNum << "     ";
    } else {
      cout << solNum << "     ";
    }
    for (int i = 0; i<8; i++) {
      cout << " " << chess[i]+1 ;
    }
    solNum ++;
    cout << endl;
    return; 
  } 

  for (int rw = 0; rw < 8; rw++) {
    if (isPossible(clm, rw)) {
      chess[clm] = rw;
      backtrack(clm+1);
    }
  }
}

void solve(){
  int dataset;

  cin >> dataset;

  while(dataset--){
    solNum = 1;

    cin >> row >> column;
    chess.assign(8, 0);

    row--;
    column--;

    backtrack(0);
    if (dataset > 0) {
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