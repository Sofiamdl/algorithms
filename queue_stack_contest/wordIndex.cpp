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

// g++ -std=c++17 main3.cpp -o main3 && time ./main3 < input.txt

void solve(){
  string alph = "abcdefghijklmnopqrstuvwxyz";
  map<vector<char>, int> dict;
  int counter = 1;


  for (int i = 0; i < alph.size(); i++) {
    vector<char> vec;
    vec.push_back(alph[i]);
    dict[vec] = counter;
    counter+=1;
  }
  for (int j = 0; j < alph.size()-1; j++) {
    for (int i = j+1; i < alph.size(); i++) {
      vector<char> vec;
      vec.push_back(alph[j]);
      vec.push_back(alph[i]);
      dict[vec] = counter;
      counter+=1;
    }
  }

  for (int k = 0; k < alph.size()-2; k++) {
    for (int j = k+1; j < alph.size()-1; j++) {
      for (int i = j+1; i < alph.size(); i++) {
        vector<char> vec;
        vec.push_back(alph[k]);
        vec.push_back(alph[j]);
        vec.push_back(alph[i]);
        dict[vec] = counter;
        counter+=1;
      }
    }
  }

  for (int l = 0; l < alph.size()-3; l++) {
    for (int k = l+1; k < alph.size()-2; k++) {
      for (int j = k+1; j < alph.size()-1; j++) {
        for (int i = j+1; i < alph.size(); i++) {
          vector<char> vec;
          vec.push_back(alph[l]);
          vec.push_back(alph[k]);
          vec.push_back(alph[j]);
          vec.push_back(alph[i]);
          dict[vec] = counter;
          counter+=1;
        }
      }
    }
  }

  for (int m = 0; m < alph.size()-4; m++) {
    for (int l = m+1; l < alph.size()-3; l++) {
      for (int k = l+1; k < alph.size()-2; k++) {
        for (int j = k+1; j < alph.size()-1; j++) {
          for (int i = j+1; i < alph.size(); i++) {
            vector<char> vec;
            vec.push_back(alph[m]);
            vec.push_back(alph[l]);
            vec.push_back(alph[k]);
            vec.push_back(alph[j]);
            vec.push_back(alph[i]);
            dict[vec] = counter;
            counter+=1;
          }
        }
      }
    }
  }

  string input;
  
  while (cin >> input){
    vector<char> vec;

    for (int j = 0; j < input.size(); j++) {
      vec.push_back(input[j]);
    }


    cout << dict[vec] << endl;

  }

  

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}