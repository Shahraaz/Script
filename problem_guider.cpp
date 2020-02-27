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
    ifstream inFile;
    ofstream outFile;
    int belowCurr, belowTotal, belowLim;
    int aboveCurr, aboveTotal, aboveLim;
    int A2OJCurr, A2OJTotal, A2OJLim;
    int myRating, cycleCount;

private:
    void read()
    {
        cout << "Read\n";
        inFile.open("problem_status");
        inFile >> myRating >> cycleCount;
        inFile >> belowCurr >> belowTotal >> belowLim;
        inFile >> aboveCurr >> aboveTotal >> aboveLim;
        inFile >> A2OJCurr >> A2OJTotal >> A2OJLim;
    }
    void write()
    {
        cout << "Write\n";
        inFile.close();
        outFile.open("problem_status");
        outFile << myRating << ' ' << cycleCount << '\n';
        outFile << belowCurr << ' ' << belowTotal << ' ' << belowLim << '\n';
        outFile << aboveCurr << ' ' << aboveTotal << ' ' << aboveLim << '\n';
        outFile << A2OJCurr << ' ' << A2OJTotal << ' ' << A2OJLim << '\n';
        outFile.close();
    }
    void printDetails()
    {
        cout << "Details\n";
        db(myRating, cycleCount);
        db(belowCurr, belowTotal, belowLim);
        db(aboveCurr, aboveTotal, aboveLim);
        db(A2OJCurr, A2OJTotal, A2OJLim);
        cout << '\n';
    }
    void refactor()
    {
        cout << "Start Refactor\n";
        if (belowCurr >= belowLim && aboveCurr >= aboveLim && A2OJCurr >= A2OJLim)
        {
            cout << "Congrats you have finished a cycle\n";
            cycleCount++;
            belowCurr -= belowLim;
            aboveCurr -= aboveLim;
            A2OJCurr -= A2OJLim;
        }
        cout << "End Refactor\n";
    }
    void printMenu()
    {
        cout << "What rating Problem have you solved?" << '\n';
        int rating;
        cin >> rating;
        cout << "Is it from A2oj(1/0)" << '\n';
        bool isA2oj;
        cin >> isA2oj;
        if (isA2oj)
        {
            A2OJCurr++;
            A2OJTotal++;
        }
        if (rating <= myRating)
        {
            belowCurr++;
            belowTotal++;
        }
        else
        {
            aboveCurr++;
            aboveTotal++;
        }
    }
    void recommendation()
    {
        cout << "Recommendatons\n";
        if(belowCurr < belowLim)
            cout << "Try Solving a belowRating\n";
        if (A2OJCurr < A2OJLim)
            cout << "Try Solving an A2oj Problem\n";
        if(aboveCurr < aboveLim)
            cout << "Try Solving an aboveRating\n";
        cout << '\n';
    }

public:
    Solution()
    {
        read();
    }
    ~Solution()
    {
        write();
    }
    void Solve();
};

void Solution::Solve()
{
    while (true)
    {
        read();
        printDetails();
        recommendation();
        printMenu();
        refactor();
        write();
    }
}

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
        mySolver.Solve();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
