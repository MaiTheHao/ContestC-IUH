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
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> left(n, 1), right(n, 1);
    stack<ll> st;

    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            debug(st.top());
            debug(a[st.top()]);
            debug(a[i]);
            left[i] += left[st.top()];
            st.pop();
        }

        st.push(i);
    }

    for (ll i = 0; i < n; i++) {
        cout << left[i] << " ";
    }
    cout << endl;

    while (!st.empty())
        st.pop();

    for (ll i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            right[i] += right[st.top()];
            st.pop();
        }

        st.push(i);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        x--;
        cout << right[x] + left[x] - 1 << endl;
    }
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