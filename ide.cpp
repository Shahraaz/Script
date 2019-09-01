//Optimise
#include <bits/stdc++.h>

using namespace std;
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
using ld = long double;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	ll tot = 0;
	for (auto &x : a)
	{
		cin >> x;
		tot += x;
	}
	const int Lim = 1 << (n);
	vector<ld> DpCom(Lim, 0);
	cerr << fixed << setprecision(9);
	for (int mask = 1; mask < Lim; ++mask)
	{
		ll now = 0, cnt = 0;
		// cerr << DpCom[mask] << ' ' << cnt << '\n';
		for (int can = 0; can < n; ++can)
			if (mask & (1 << can))
			{
				now += a[can];
				cnt++;
			}
		for (int can = 0; can < n; ++can)
			if (mask & (1 << can))
			{
				int maskRem = mask ^ (1 << can);
				ll num = a[can];
				ld y = ld(num) / tot;
				DpCom[mask] += y * DpCom[maskRem];
				// db(num, den, y);
				// ld y2 = 1 - ld(now) / tot;
				// DpCom[mask] += y / (1 - y2) / (1 - y2);
			}
		DpCom[mask] *= tot / (tot - now);
		db(mask, DpCom[mask], cnt);
	}
	// cerr << Lim - 1 << '\n';
	cout << fixed << setprecision(9);
	cout << DpCom[Lim - 1] << '\n';
	return 0;
}