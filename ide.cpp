//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
#ifdef WIN32
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
	std::cerr << name << " { ";
	for (const auto &v : arg)
		cerr << v << ' ';
	cerr << " }\n";
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
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;
using ld = long double;

vector<ld> x, y;

ld profit(int _x, int _y)
{
	return min(x[_x], y[_y]) - (_x + _y);
}

void solve()
{
	int n;
	cin >> n;
	x = vector<ld>(n + 1);
	y = vector<ld>(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	sort(x.rbegin(), --x.rend());
	sort(y.rbegin(), --y.rend());
	// pc(x);
	// pc(y);
	for (int i = 1; i <= n; ++i)
		x[i] += x[i - 1];
	for (int i = 1; i <= n; ++i)
		y[i] += y[i - 1];
	ld ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		int le = 0, ri = n - 1;
		while (le <= ri)
		{
			int mid = (le + ri) / 2;
			if (profit(i, mid) <= profit(i, mid + 1))
				le = mid + 1;
			else
				ri = mid - 1;
		}
		ans = max(ans, profit(i, le));
	}
	cout << fixed << setprecision(4) << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}