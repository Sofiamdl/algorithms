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

// g++ -std=c++17 dictionary.cpp -o dictionary && time ./dictionary < input.txt > output.txt


void solve(){
  map<string, string> dict;
  string first;
  string second;

  string line;
  int findLine;
  while (getline(cin, line))
  {
    findLine = line.find(' ');

    if (line.empty()){

    } else if (findLine!= std::string::npos){
      dict[line.substr(findLine+1, line.size())] = line.substr(0, findLine);
    } else {
      if (dict.count(line)) {
        cout << dict[line] << endl;
      } else {
        cout << "eh" << endl;
      }
    }
  }

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}