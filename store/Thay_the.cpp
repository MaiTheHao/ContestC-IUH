#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORE(i, a, b) for (ll i = (a); i <= b; i++)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define debug(x) cerr << #x << " = " << x << endl

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);
const ll MAXN = 1e5 + 5;

void solve()
{
    ll n;
    cin >> n;

    while (n--)
    {
        // Biến đếm số các chữ cái mà xuất hiện lẻ lần.
        ll total_le = 0;
        // Biến đếm xem có bao nhiêu kí tự trong 3 kí tự 'a', 'b', 'c' tồn tại.
        ll appeared = 0;
        // Mảng lưu số lần xuất hiện lần lượt của 3 kí tự.
        ll store[3] = {0, 0, 0};

        string s;
        cin >> s;

        for (char &ch : s)
        {
            /*
                c - 'a' có ý nghĩa là, vì các kí tự 'a', 'b', 'c' liền kề nhau.
                Nên => trong bảng mã ASCII thì độ chênh lệch tương ứng giữa các kí tự là 1.
                Dựa vào tính chất đó => c - 'a'. (Với c = 'a' => 'a' - 'a' = 0)
            */
            store[ch - 'a']++;
        }

        for (ll &count : store)
        {
            // Kiểm tra nếu lẻ thì cộng vào
            total_le += (count % 2 != 0);
            // Kiểm tra nếu có tồn tại thì cộng vào
            appeared += (count != 0);
        }

        /*
            Bài toán gồm 3 TH cơ sở:
                - TH1: Chỉ có một loại chữ cái được nhập => appeared == 1.
                - TH2: Tất cả đều xuất hiện chẵn/ lẻ lần => total_le == 3 || total_le == 0.
                - TH3: Trường hợp còn lại.
        */

        if (appeared == 1)
        {
            // Nếu chỉ có 1 loại kí tự => không thể ghép đôi => res = số lượng kí tự đó.
            cout << *max_element(store, store + 3) << endl;
            continue;
        }

        if ((total_le == 3 || total_le == 0))
        {
            // Nếu tất cả đều xuất hiện chẵn/ lẻ lần => kết quả luôn là 2.
            cout << 2 << endl;
            continue;
        }

        cout << 1 << endl;
    }
}

void setupIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
}

int main()
{
    setupIO();
    int t = 1, count = 0;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}