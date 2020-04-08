#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k, c;
char a[N];
int storeL[N], idxL[N];
int storeR[N], idxR[N];

int32_t main()
{
    IOS;
    cin >> n >> k >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int prv = -1e9, val = 0;
    for (int i = 1; i <= n; i++)
    {
        idxL[i] = prv;
        if (a[i] == 'x')
        {
            storeL[i] = val;
            continue;
        }
        if (i - prv > c)
        {
            val++;
            prv = i;
            storeL[i] = val;
        }
    }
    prv = 1e9, val = 0;
    for (int i = n; i >= 1; i--)
    {
        idxR[i] = prv;
        if (a[i] == 'x')
        {
            storeR[i] = val;
            continue;
        }
        if (prv - i > c)
        {
            val++;
            prv = i;
            storeR[i] = val;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int l = idxL[i];
        int r = idxR[i];
        cout << i << ' ' << l << ' ' << r << ' ' << storeL[i] << ' ' << storeR[i] << '\n';
        if (l == -1e9 && r == 1e9)
            ans.push_back(i);
        else if (l == -1e9)
        {
            if (storeR[r] < k)
                ans.push_back(i);
        }
        else if (r == 1e9)
        {
            if (storeL[l] < k)
                ans.push_back(i);
        }
        else
        {
            if (abs(r - l) > c)
            {
                if (storeL[l] + storeR[r] < k)
                    ans.push_back(i);
            }
            else
            {
                if (storeL[l] + storeR[r] - 1 < k)
                    ans.push_back(i);
            }
        }
    }
    for (auto &it : ans)
        cout << it << endl;
    return 0;
}
