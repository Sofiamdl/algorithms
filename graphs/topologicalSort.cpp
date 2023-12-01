#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define pf push_front
// #define x first
// #define y second
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define sortall(x) sort(all(x))
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pii> vpii;


const int INF = 0x3f3f3f3f;

// g++ -std=c++17 topologicalSort.cpp -o topologicalSort && time ./topologicalSort < input.txt

vector<bool> visited;
vector<int> ans;

void dfs(int v, vector<vector<int> > graph) {
  visited[v] = true;
  for (int u : graph[v]) {
    if (!visited[u])
      dfs(u, graph);
  }
  ans.push_back(v);
}

void solve(){

  int n; int m;
  cin >> n >> m;

  vector<vector<int> > graph(n);


  while (m--) {
    int x; 
    int y;

    cin >> x >> y;

    graph[y-1].push_back(x-1);
  }

  for (int i = 0; i < graph.size(); ++i) {

    sortall(graph[i]);
 
  }

  visited.assign(n, false);
  ans.clear();

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) dfs(i, graph);
  }

  // reverse(ans.begin(), ans.end());

  for (auto n: ans) {
    cout << n+1 << " ";
  }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}