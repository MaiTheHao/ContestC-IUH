#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define R0F(i, a) for (int i = (a); i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define debug(x) cerr << #x << " = " << x << endl

const int MOD = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
const db PI = acos((db)-1);
const int MAXN = 1e5 + 5;

void solve()
{
    ll row, col;
    cin >> row >> col;

    vector<vector<ll>> arr(row, vector<ll>(col)), dp(row, vector<ll>(col, INF));
    for (vector<ll> &r : arr)
    {
        for (ll &x : r)
        {
            cin >> x;
        }
    }
    /*
    3 3
    9 1 9
    1 9 2
    0 1 9
    */

    row -= 1;
    col -= 1;
    dp[row][0] = 0;
    for (ll r = row; r >= 0; r--)
    {
        for (ll c = 0; c <= col; c++)
        {   
            if(r > 0) dp[r - 1][c] = min(dp[r - 1][c], arr[r - 1][c] + dp[r][c]);
            if(r > 0 && c < col) dp[r - 1][c + 1] = min(dp[r - 1][c + 1], arr[r - 1][c + 1] + dp[r][c]);
            if(c < col) dp[r][c + 1] = min(dp[r][c + 1], arr[r][c + 1] + dp[r][c]);
        }
    }

    cout << dp[0][col] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}