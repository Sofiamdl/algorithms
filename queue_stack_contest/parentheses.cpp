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
  int amount;
  string tester;

  cin >> amount;
  getline(cin, tester);

  while(amount--){
    vector<char> array;
    string tester;

    // cin >> tester;
    getline(cin, tester);
    // cout << tester << endl;

    for (char& c: tester) {
      array.push_back(c);
    }
    bool isTrue = true;

    while (!array.empty() && isTrue) {
      bool helper = false;
      for (int i = 0; i < array.size()-1; i++) {
        if (array[i] == '(' && array[i+1] == ')') {
          array.erase(array.begin() + i);
          array.erase(array.begin() + i);
          helper = true;
          break;
        } else if (array[i] == '[' && array[i+1] == ']') {
          array.erase(array.begin() + i);
          array.erase(array.begin() + i);
          helper = true;
          break;
        }
      }
      isTrue = helper;
    }
    if (isTrue) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}



int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}