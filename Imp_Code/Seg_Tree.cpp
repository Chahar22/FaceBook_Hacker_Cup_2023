#include <bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pb push_back
using namespace std;

// https://codeforces.com/contest/1878/problem/E


int a[200005], seg[4 * 200005];

void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;

    build(2 * ind + 1, low, mid);

    build(2 * ind + 2, mid + 1, high);

    seg[ind] = seg[2 * ind + 1] & seg[2 * ind + 2];
}

// (0,0,5,3,3)

int query(int ind, int low, int high, int l, int r)
{
    // Lies Inside {l,r}.
    if (low >= l and high <= r)
    {
        return seg[ind];
    }

    // Lies outside the range.

    if (high < l || low > r)
    {
        return -1;
    }

    // Overlap.

    int mid = (low + high) / 2;

    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    if (left == -1 && right == -1)
        return 0;

    if (right == -1)
        return left;
    if (left == -1)
        return right;

    return left & right;
}

int find(int low, int k, int n)
{
    int st = low;

    int l = low, r = n - 1;

    while (l <= r)
    {

        int mid = (l + r) / 2;

        int ltm = query(0, 0, n - 1, st, mid);

        if (ltm >= k)
            l = mid + 1;
        else
        {
            r = mid - 1;
        }
    }

    if (l == st)
    {
        if (a[st] < k)
            return -1;

        return l + 1;
    }

    return r + 1;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int q;
        cin >> q;
        int idx, k;
        int qq = q;
        vector<vector<int>> que;

        while (qq--)
        {
            cin >> idx >> k;

            que.pb({idx, k});
        }

        build(0, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < q; i++)
        {

            int id = que[i][0], kk = que[i][1];
            // cout<<id<<" "<<kk<<endl;
            ans.pb(find(id - 1, kk, n));
        }

        for (int x : ans)
        {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}
