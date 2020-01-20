#include <bits/stdc++.h>
using namespace std;
#define int long long
int add[500006] = {0}, zero[500006] = {0}, one[500006] = {0}, temp;
void build_tree(int l, int r, int pos)
{
    if (l == r)
    {
        zero[pos] = 1;
        return;
    }
    else if (l < r)
    {
        int mid = (l + r) / 2;
        build_tree(l, mid, 2 * pos);
        build_tree(mid + 1, r, 2 * pos + 1);
        zero[pos] = zero[2 * pos] + zero[2 * pos + 1];
    }
    return;
}
void update(int l, int r, int pos, int ql, int qr)
{
    if (ql > r || qr < l || r > l)
        return;
    if (add[pos] > 0)
    {
        if (add[pos] % 3 == 1)
        {
            temp = one[pos];
            one[pos] = zero[pos];
            zero[pos] = (r - l + 1) - zero[pos] - temp;
        }
        if (add[pos] % 3 == 2)
        {
            temp = one[pos];
            one[pos] = (r - l + 1) - zero[pos] - one[pos];
            zero[pos] = temp;
        }
        if (l != r)
        {
            add[2 * pos] += add[pos];
            add[2 * pos + 1] += add[pos];
        }
        add[pos] = 0;
    }
    if (ql <= l && qr >= r)
    {
        temp = one[pos];
        one[pos] = zero[pos];
        zero[pos] = (r - l + 1) - zero[pos] - temp;
        if (l != r)
        {
            add[2 * pos] += 1;
            add[2 * pos + 1] += 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * pos, ql, qr);
    update(mid + 1, r, 2 * pos + 1, ql, qr);
    one[pos] = one[2 * pos] + one[2 * pos + 1];
    zero[pos] = zero[2 * pos] + zero[2 * pos + 1];
    return;
}
int query(int l, int r, int pos, int ql, int qr)
{
    if (ql > r || qr < l || r > l)
        return 0;
    int ans;
    if (add[pos] > 0)
    {
        if (add[pos] % 3 == 1)
        {
            temp = one[pos];
            one[pos] = zero[pos];
            zero[pos] = (r - l + 1) - zero[pos] - temp;
        }
        if (add[pos] % 3 == 2)
        {
            temp = one[pos];
            one[pos] = (r - l + 1) - zero[pos] - one[pos];
            zero[pos] = temp;
        }
        if (l != r)
        {
            add[2 * pos] += add[pos];
            add[2 * pos + 1] += add[pos];
        }
        add[pos] = 0;
    }
    if (ql <= l && qr <= r)
    {
        return zero[pos];
    }
    int mid = (l + r) / 2;
    ans = query(l, mid, 2 * pos, ql, qr) + query(mid + 1, r, 2 * pos + 1, ql, qr);
    return ans;
}
signed main()
{
    int n, q, ty, x, y;
    cin >> n >> q;
    build_tree(0, n - 1, 1);
    for (int i = 0; i < q; i++)
    {
        cin >> ty >> x >> y;
        if (ty == 0)
        {
            update(0, n - 1, 1, x, y);
        }
        else if (ty == 1)
        {
            int ans = query(0, n - 1, 1, x, y);
            cout << ans << endl;
        }
    }
    return 0;
}