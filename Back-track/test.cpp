#include <bits/stdc++.h>
using namespace std;

int n, k, s;
int a[25];               // mảng nhập
vector<int> v;           // vector quay lui
vector<vector<int>> ans; // vector lưu đáp án

void Try(int x)          // quay lui từ x -> n
{
    for (int i = x; i <= n; i++)
    {
        v.push_back(a[i]);
        s += a[i];
        if (s < k) // nếu như s + a[i] nhỏ hơn k thì tiếp tục quay lui từ i -> n
            Try(i);
        else if (s == k) // bằng rồi thì đưa vào vector lưu đáp án
            ans.push_back(v);
        s -= a[i];
        v.pop_back();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        s = 0;
        v.clear();
        ans.clear();

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);

        Try(1);

        if (ans.size()) // in
        {
            cout << ans.size() << " ";
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "{" << ans[i][0];
                for (int j = 1; j < ans[i].size(); j++)
                    cout << " " << ans[i][j];
                cout << "} ";
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}