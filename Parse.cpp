// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    while (*name == ',' || *name == ' ')
        name++;
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
    while (*names == ',' || *names == ' ')
        names++;
    const char *comma = strchr(names, ',');
    std::cerr.write(names, comma - names) << " { ";
    for (const auto &v : arg1)
        cerr << v << ' ';
    cerr << " }\n";
    PC(comma, args...);
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
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
        string str;
        while (getline(cin, str))
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '+')
                {
                    // db("a");
                    ++i;
                    string cnt;
                    if (str[i] == ' ')
                    {
                        cnt = "0";
                        // cout << 1 << ' ';
                    }
                    else
                    {
                        while (str[i] != ' ')
                        {
                            cnt += str[i];
                            ++i;
                        }
                        // cout << stoi(cnt) + 1 << ' ';
                    }
                    while (str[i] == ' ')
                        ++i;
                    string hr;
                    while (str[i] != ':')
                    {
                        hr += str[i];
                        ++i;
                    }
                    string min;
                    ++i;
                    while (i < str.length() && '0' <= str[i] && str[i] <= '9')
                    {
                        min += str[i];
                        ++i;
                    }
                    cout << stoi(hr) * 60 + stoi(min) << " # " << stoi(cnt) + 1;
                    --i;
                }
                else if (str[i] == '-')
                {
                    // db("b");
                    ++i;
                    string att;
                    while (i < str.length() && '0' <= str[i] && str[i] <= '9')
                    {
                        att += str[i];
                        ++i;
                    }
                    cout << att << " # --";
                    --i;
                }
                else if (str[i] == ',')
                {
                    // db("c");
                    cout << str[i];
                    if (i + 1 < str.length())
                        if (str[i + 1] == ',')
                            cout << "0 # --";
                }
                else
                    cout << str[i];
            }
            cout << '\n';
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