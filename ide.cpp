// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        ll dx = x2 - x1;
        ll dy = y2 - y1;
        if (dx == 0)
            if (a + b != 0)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                if (a < b)
                {
                    b -= a;
                    if (x2 - x <= b)
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                {
                    b -= a;
                    if (x2 - x <= b)
                    {
                        cout << "NO\n";
                        return;
                    }
                }

                a -= b;
                a = abs(a);
            }
        if (dy == 0)
            if (c + d != 0)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                if (c < d)
                {
                    swap(c, d);
                    swap(y1, y2);
                }
                c -= d;
                c = abs(c);
            }
        if (x - x1 >= a && y - y1 >= c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}