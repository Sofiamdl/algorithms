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

// g++ -std=c++17 teste.cpp -o teste && time ./teste < input.txt

void solve(){
  int input;
  cin >> input;

  while (input--) {
    vector<pair<int, int> > fuels;
    int stopsAmount;
    cin >> stopsAmount;

    while(stopsAmount--) {
      int distanceFromTown;
      int fuelSuply;
      cin >> distanceFromTown >> fuelSuply;
      fuels.push_back(make_pair(fuelSuply, distanceFromTown));
    }

    sortall(fuels);

    int awayFromTown;
    int fuelLeft;

    cin >> awayFromTown >> fuelLeft;
    int counter = 0;
    int canFinish = true;

    while(awayFromTown > fuelLeft && canFinish) {
      int i;
      int changed = false;
      for (i = fuels.size()-1; i >= 0; i--) {
        if (fuelLeft >= awayFromTown-fuels[i].second) {
          changed = true;
          break;
        }
      }
      if (!changed) {
        canFinish = false;
        break;
      }
      fuelLeft += fuels[i].first;
      counter += 1;
      fuels.erase(fuels.begin() + i);

      int teste = fuels[fuels.size()-1].first;

    }
    if (!canFinish){
      cout << -1 << endl;
    } else {
      cout << counter << endl;
    }
  }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}