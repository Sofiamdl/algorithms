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

// g++ -std=c++17 algo.cpp -o algo && time ./algo < input.txt
vector<int> chess;
int row; int column;
int solNum = 1;
    
void backtrack(int clm, string word) {
  if (clm == word.size()) {
    cout << word << endl;
    return; 
  } 

  if (word[clm] == 'S' && word[clm+1] == 'S')  {
    string helper = word;
    helper[clm] = 'B';
    helper[clm+1] = '0';
    helper = helper.substr(0, clm+1) + helper.substr(clm+2, helper.size()-clm-2);
    backtrack(clm+1, helper);
  }
  word[clm] = tolower(word[clm]);
  backtrack(clm+1, word);

}

void solve(){
  string word;

  cin >> word;


  backtrack(0, word);

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}