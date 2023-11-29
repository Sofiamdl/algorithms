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

// g++ -std=c++17 daydreamin.cpp -o daydreamin && time ./daydreamin < input.txt

void solve(){
  string alph = "abcdefghijklmnopqrstuvwxyz";
  int input;
  
  cin >> input;
  while (input--) {
    unordered_map<char, int> dict;
    string string1;
    string string2;
    cin >> string1;
    cin >> string2;


    for (auto x: string1) {
      dict[x] += 1;
    }
    for (auto x: string2) {
      dict[x] += 1;
    }

    string1 = "";

    for (auto x: alph) {
      if (dict.count(x)){
        while(dict[x]--){
          string1 += x;
        }

      }
    }
    cout << string1 << endl;
  }

  
  

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}