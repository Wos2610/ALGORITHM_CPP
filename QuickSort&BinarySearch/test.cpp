//PTIT127J
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = " " + s; // xét dãy từ index 1 -> n cho dễ hiểu
    int fa[n + 1]; // fa[i] sẽ là số cách biến đổi ít nhất để i kí tự ban đầu về toàn A
    int fb[n + 1]; // fb[i] sẽ là số cách biến đổi ít nhất để i kí tự ban đầu về toàn B
    fa[0] = fb[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
        {
            fa[i] = fa[i - 1]; // L1
            // vì dãy 1 -> i-1 toàn là A nên thêm 1 kí tự A ở vị trí i thì không mất phép biến đổi nào
            fb[i] = fb[i - 1] + 1; // L2
            // vì dãy 1 -> i-1 toàn là B nên thêm 1 kí tự A thì cần phải chuyển nó về B thì mất 1 phép biến đổi
            if (fb[i] > fa[i - 1] + 1)
                fb[i] = fa[i] + 1; // L3
            // tuy nhiên, có thể biến đổi i kí tự đầu tiên từ A -> B nên ta kiểm tra xem sử dụng cách này có cần ít phép biến đổi hơn không
            // ví dụ của trường hợp này là như sau:
            // cho dãy BAAA
            // nếu như chỉ xét dòng L1 và L2 thì fa[4] = 1 (đúng) và fb[4] = 3 (sai) mà đáng ra fb[4] = 2 mới là đúng
            // nếu xét thêm L3 thì sẽ hiểu cách biến đổi như sau:
            // thay vì biến đổi 3 kí tự A về B làm fb[4] = 3 thì ta sẽ biến đổi kí tự B về A như việc xét fa[], đến i = 4 thì để dãy trở về toàn B thì ta sẽ biến 4 kí tự A về B nên fb[4] = 2 mới là đúng
            // ví dụ trên chủ yếu để xét trường hợp biến đổi trên fb[] nhưng đáp án vẫn là biến đổi trên fa[] nhưng nếu em lấy ví dụ trên 1 dãy dài hơn thì sẽ hiểu kĩ hơn (ABBBBAAA) :v
        }
        else // trường hợp ngược lại cũng tương tự
        {
            fb[i] = fb[i - 1];
            fa[i] = fa[i - 1] + 1;
            if (fa[i] > fb[i - 1] + 1)
                fa[i] = fb[i - 1] + 1;
        }
    }
    cout << min(fa[n], fb[n] + 1);
    // đáp án sẽ là min của số phép biến đổi dãy về dãy toàn A và số phép biến đổi dãy về toàn B + thêm 1 (vì mất thêm 1 phép biến đổi cả dãy B về toàn A)
}