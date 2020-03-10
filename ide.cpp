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
    map<pair<int, pair<int, int>>, int> dp;
    int grundy(int x, int y, int z)
    {
        if (dp.count({x, {y, z}}))
            return dp[{x, {y, z}}];
        int ret = 0;
        if (x == 0)
        {
            if (y == 0)
            {
                ret = z & 1;
            }
            else
            {
                ret = z & 1;
            }
            db(x, y, z, ret);
            return dp[{x, {y, z}}] = ret;
        }
        set<int> temp;
        if (x > 0)
            temp.insert(grundy(x - 1, y + 1, z));
        if (y > 0)
            temp.insert(grundy(x, y - 1, z + 1));
        if (z > 0)
            temp.insert(grundy(x, y, z - 1));
        while (temp.count(ret))
        {
            ret++;
        }
        db(x, y, z, ret);
        return dp[{x, {y, z}}] = ret;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        grundy(3, 3, 3);
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto &x : p)
            cin >> x;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                a.pb(p[0] - 1);
            }
            else
                a.pb(p[i] - p[i - 1] - 1);
        }
        pc(a);
        reverse(all(a));
        while (a.size() && a.back() == 0)
            a.pop_back();
        reverse(all(a));
        pc(a);
        if (a.size() == 0)
        {
            cout << "Johnny wins\n";
        }
        else
        {
            if (a.size() % 2 == 0)
            {
                if (a.back() % 2 == 0)
                    cout << "Johnny wins\n";
                else
                    cout << "Mary wins\n";
            }
            else
            {
                if (a.back() & 1)
                    cout << "Johnny wins\n";
                else
                    cout << "Mary wins\n";
            }
        }
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