#include <bits/stdc++.h>
using namespace std;

int l1[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

string left1(string a) // quay bên trái ở trạng thái đầu
{
    string b = "";
    for (int i = 0; i < 10; i++)
        b += a[l1[i]];
    return b;
}

string right1(string a) // quay bên phải ở trạng thái đầu
{
    string b = "";
    for (int i = 0; i < 10; i++)
        b += a[r1[i]];
    return b;
}

string left2(string a) // quay bên trái ở trạng thái đích
{
    string b = "";
    for (int i = 0; i < 10; i++)
        b += a[l2[i]];
    return b;
}

string right2(string a) // quay bên phải ở trạng thái đích
{
    string b = "";
    for (int i = 0; i < 10; i++)
        b += a[r2[i]];
    return b;
}

int main()
{
    string a, b, s;
    int x, ans = 1e9;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        a += to_string(x);
    }
    b = "1238004765";

    pair<string, int> u;
    map<string, int> m;
    queue<pair<string, int>> q1;
    queue<pair<string, int>> q2;

    q1.push({a, 0});
    q2.push({b, 0});
    while (q1.size()) // xét trạng thái ban đầu
    {
        u = q1.front();
        q1.pop();
        s = left1(u.first);
        if (m[s] == 0) 
            m[s] = u.second + 1; // lưu số lần quay của trạng thái đang xét vào map
        q1.push({s, u.second + 1});
        s = right1(u.first);
        if (m[s] == 0)
            m[s] = u.second + 1;
        q1.push({s, u.second + 1});
        if (u.second == 14)
            break;
    }

    while (q2.size())
    {
        u = q2.front();
        q2.pop();
        if (m[u.first] > 0)
            ans = min(ans, m[u.first] + u.second); // lấy min của các trường hợp để được đáp án
        s = left2(u.first);
        q2.push({s, u.second + 1});

        s = right2(u.first);
        q2.push({s, u.second + 1});
        if (u.second == 14)
            break;
    }
    cout << ans;
}