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
    ll n, m;
    cin >> n >> m;

    // first: Số lượng; second: index
    vector<pair<ll, ll>> students(n);
    FOR(i, 0, n)
    {
        cin >> students[i].f;
        students[i].s = i;
    }

    // 0: Sức chứa; 1: Giá tiền; 2: index; 3: check hay chưa
    vector<vector<ll>> store(m, vector<ll>(4));

    // Nhập các ngôi nhà
    trav(x, store) cin >> x[0];
    FOR(i, 0, m)
    {
        cin >> store[i][1];
        store[i][2] = i;

        // Giá trị này dùng để đánh dấu là căn hộ được lấy hay chưa (0 = false, khác 0 = true)
        store[i][3] = 0;
    }

    // Sắp xếp các sinh viên theo thứ tự giảm dần số lượng
    sort(all(students), [&](pair<ll, ll> &a, pair<ll, ll> &b)
         { return a.f > b.f; });

    // Sắp xếp các ngôi nhà theo giá tiền tăng dần, nếu các giá tiền bằng nhau ưu tiên sức chứa tăng dần
    sort(all(store), [](vector<ll> &a, vector<ll> &b)
         { return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]; });

    // Lưu các index kết quả
    vector<ll> store_res(n);

    // Lặp qua mỗi cụm học sinh
    trav(student, students)
    {
        // Biến kiểm tra có pass hay không
        bool impossible = true;

        // Lặp qua từng ngôi nhà
        trav(house, store)
        {
            // Kiểm tra nếu sức chứa đủ và ngôi nhà chưa được check thì thêm vào mảng index kết quả store_res
            if (house[0] >= student.f && house[3] == 0)
            {
                // Lưu kết quả theo index ban đầu của cụm học sinh
                store_res[student.s] = (house[2] + 1);
                house[3] = 1;
                impossible = false;
                break;
            }
        }

        // Nếu không pass thì dừng chương trình
        if (impossible)
        {
            cout << "impossible";
            return;
        }
    }

    // In ra các kết quả
    trav(res, store_res)
    {
        cout << res << " ";
    }
    cout << endl;
}

void setupIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
// freopen("output.out", "w", stdout);
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