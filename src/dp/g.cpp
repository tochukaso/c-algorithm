#include <bits/stdc++.h>
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define PERM(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int dx[4] = { 1, 0,-1, 0};
const int dy[4] = { 0, 1, 0,-1};

vector<vector<ll>> G;
ll dp[100100];

ll rec(ll i) {
  if(dp[i] >= 0) return dp[i];

  ll res = 0;
  for (auto nv: G[i]) {
    chmax(res, rec(nv) + 1);
  }
  return dp[i] = res;
}

int main() {
  ll N, M; cin >> N >> M;
  G.assign(N, vector<ll>());
  REP(i, M) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
  }

  REP(i, N) dp[i] = -1;
  REP(i, N) rec(i);

  ll res = 0;
  REP(i, N) chmax(res, dp[i]);

  cout << res << endl;
  return 0;
}
