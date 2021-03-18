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

ll N;
double dp[3100][3100];
double coins[3100];

int main() {
  cin >> N;
  dp[0][0] = 1.0;

  REP(i, N) {
    double c;
    cin >> c;
    coins[i] = c;
  }

  REP(i, N) REP(j, N) {
    dp[i+1][j] += dp[i][j] * (1 - coins[i]);
    dp[i+1][j + 1] += dp[i][j] * coins[i];
  }

  double res = 0;
  for (int i = N/2 + 1; i < N + 1; i++) {
    res += dp[N][i];
  }

  cout << res << endl;

  return 0;
}
