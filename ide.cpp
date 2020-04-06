#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 50;

vector<int> pos[5000 + 50];

int a[5000 + 50];

int dp[5000 + 50][5000 + 50];
bool vis[5000 + 50][5000 + 50];

int xorr[5000 + 50][5000 + 50];

int solve(int le, int ri)
{
    if (le > ri)
    {
        return 0;
    }
    if (vis[le][ri] == true)
    {
        return dp[le][ri];
    }
    int ans = solve(le + 1, ri);
    if (le == pos[a[le]][0])
        for (int i = le; i <= ri; i++)
        {
            int cur = a[i];
            if (le > pos[a[i]][0])
                break;
            if (i == pos[cur][0])
            {

                int last = pos[cur].size();
                last--;
                if (pos[cur][last] <= ri)
                {
                    // cout<<le<<" : "<<ri<<" --> ";
                    // cout<<xorr[pos[cur][0]][pos[cur][last]]+solve(pos[cur][last]+1,ri)<<"\n";
                    ans = max(ans, xorr[pos[cur][0]][pos[cur][last]] + solve(pos[cur][last] + 1, ri));
                }
            }
        }

    // cout << le << " -> " << ri << " ,, " << ans << "\n";
    dp[le][ri] = ans;
    vis[le][ri] = true;
    return dp[le][ri];
}

void fill(int n)
{
    for (int j = 0; j <= 5000; j++)
    {
        if (pos[j].size() > 0)
        {

            int le = pos[j][0];
            int ri = pos[j][pos[j].size() - 1];
            int val = 0;
            int cc = 0;
            for (int i = le; i <= ri; i++)
            {
                int cur = a[i];
                int lee = pos[cur][0];
                int rii = pos[cur][pos[cur].size() - 1];

                if (i == lee)
                {
                    cc++;
                }
                if (i == rii)
                {
                    cc--;
                    val ^= a[i];
                }
                // cout<<val<<",";
            }
            if (cc == 0)
            {
                // cout<<j<<" : "<<val<<"\n";
                xorr[le][ri] = val;
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         cout<<xorr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    fill(n);
    vector<pair<int, int>> bc;
    // for(int i=1;i<=5000;i++){
    //     if(pos[i].size()>0){
    //         bc.push_back({pos[i][0],pos[i][pos[i].size()-1]});
    //     }
    // }
    // sort(bc.begin(),bc.end());
    cout << solve(1, n);
    return 0;
}
/*
Mistakes to take care of-
1. For string s, s+=a is similar to appending to s. s = s + a takes O|s| + O|a| time. 
Relevant problem where I made mistake - https://codeforces.com/contest/1326/problem/D2
2. Try using constant value of N to declare arrays, etc. Else you might get hacked / FST.
Relevant problem where I made a mistake - https://codeforces.com/contest/1307/problem/D
3. While exponentiation, avoid modding the exponent. Or mod with mod-1.
Relevant problem where I made a mistake - https://codeforces.com/contest/1332/problem/E
*/