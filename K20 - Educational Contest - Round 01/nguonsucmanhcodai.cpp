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
    ll n, ans = 0;
    cin >> n;
    ll oddS = 0, evenS = 0;
    ll oddC = 0, evenC = 0;

    FOR(i, 0, n)
    {
        ll x;
        cin >> x;
        if (x % 2 == 0)
        {
            evenS += x;
            evenC++;
        }
        else
        {
            oddS += x;
            oddC++;
        }
    }

    ans = oddS * evenC + evenS * oddC;

    cout << ans; // Tự nhiên thấy mình ngu toán :)
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