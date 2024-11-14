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
const ll INF = 1e18;
const db PI = acos((db)-1);
const int MAXN = 1e5 + 5;

void solve()
{
    ll n, k, total = 0;
    cin >> n >> k;
    vector<vector<ll>> arr(n, vector<ll>(n));
    vector<vector<ll>> prfSum(n + 1, vector<ll>(n + 1, 0));
    F0R(i, n)
    {
        F0R(j, n)
        {
            cin >> arr[i][j];
            prfSum[i + 1][j + 1] = arr[i][j] + prfSum[i][j + 1] + prfSum[i + 1][j] - prfSum[i][j];
        }
    }

    for (ll row = 1; row <= n; row++)
    {
        for (ll col = 1; col <= n; col++)
        {
            ll size = min(n - row + 1, n - col + 1),
               left = 1,
               right = size,
               res = 0;

            while (left <= right)
            {
                ll mid = (left + right) / 2,
                   x2 = row + mid - 1,
                   y2 = col + mid - 1,
                   sum = prfSum[x2][y2] - prfSum[row - 1][y2] - prfSum[x2][col - 1] + prfSum[row - 1][col - 1];

                if (sum <= k)
                {
                    res = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            total += res;
        }
    }

    cout << total << endl;
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