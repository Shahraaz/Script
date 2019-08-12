//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
#ifdef Debug
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

void solve()
{
	// db("Here");
	freopen("FilterNew.txt", "r", stdin);
	string txt;
	vector<string> USER, PASS;
	bool b = false;
	// db("Here");
	while (cin >> txt)
	{
		if (b)
		{
			string temp = "";
			int cnt = 2, i = 0;
			while (cnt)
			{
				if (txt[i] == '-')
					cnt--;
				temp += txt[i];
				++i;
			}
			while (txt[i])
			{
				temp += txt[i];
				++i;
			}
			PASS.pb(temp);
		}
		else
			USER.pb(txt);
		b = !b;
		// db("Here");
	}
	int cnt = USER.size();
	db(cnt);
	while (cnt--)
	{
		int i = rand() % USER.size();
		ofstream fout("certificate.txt");
		fout << USER[i] << '\n';
		fout << PASS[i] << '\n';
		// db(cnt, USER[i], PASS[i]);
		fout.close();
		system("python test.py");
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	srand(time(NULL));
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
#ifdef TIME
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}