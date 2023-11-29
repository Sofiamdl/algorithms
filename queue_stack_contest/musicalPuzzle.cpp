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


void solve(){
    int inputNum;
    cin >> inputNum;

    while (inputNum--)
    {
        int melodySize;
        string melody;
        map<vector<char>,string> toRecord;
        cin >> melodySize;
        cin >> melody;

        for (int i = 0; i < melodySize-1; i++) {
            vector<char> teste;

            teste.push_back(melody[i]);
            teste.push_back(melody[i+1]);

            toRecord[teste] = 1;
        } 
        
        cout << toRecord.size() << endl;

        
    }
    
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}