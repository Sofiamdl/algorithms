#include <bits/stdc++.h>

using namespace std;

void solve(){

   int number;
  cin >> number;
  stack<pair<int, int> > bag;

  int pushToStack;

  string operation;

  while (number--){

    cin >> operation;
    if (operation == "PUSH"){
      
      cin >> pushToStack;
      if (bag.empty()) {
        bag.push(make_pair(pushToStack, pushToStack));
      }
      else if (pushToStack >= bag.top().second) {
        bag.push(make_pair(pushToStack, bag.top().second));
      } else {
        bag.push(make_pair(pushToStack, pushToStack));
      }
    }

    else if (operation == "POP")
    {
      if (bag.empty()) {
        cout << "EMPTY\n";
      } else {
        bag.pop();
      }
    }
    else if (operation == "MIN")
    {
      if (bag.empty()) {
        cout << "EMPTY\n";
      } else {
        cout << bag.top().second << "\n";
      }
    }
  }

}

int main(){

  cin.tie(NULL);
  ios::sync_with_stdio(false);

  solve();
  return 0;
}