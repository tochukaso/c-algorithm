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

const ll INF = 1LL << 60;

int main() {
  int N; cin >> N;
  int K; cin >> K;

  ll h[100010];
  ll dp[100010];
  REP(i, N) cin >> h[i];
  REP(i,100010) dp[i] = INF;
  dp[0] = 0;
  REPS(i, N) RREPS(j, min(i, K)) chmin(dp[i], dp[i - j] + abs(h[i] - h[i - j]));

  cout << dp[N-1] << endl;
  return 0;
}
