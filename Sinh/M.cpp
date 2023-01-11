#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long a[1000006], b[1000006];
int n = 0, c = 0;
// s : tinh tong tat ca cac phan tu
// s1: tinh tong cac phan tu 1 o nua dau
// s2: tinh tong cac phan tu 1 o nua sau
long long s = 0, s1 = 0, s2 = 0, res = 99999999, mark = 0;
// save1 : luu cac gia tri cua s1
// save2 : luu cac gia tri cua s2

vector<long long> save1, save2;
void process(){
    while(!mark){
        s1 = 0;
        s2 = 0;
        for(int i = 1; i <= n/2; i++){
            if(b[i]){
                s1 += a[i];
                s2 += a[i + n/2];
            }
        }
        save1.emplace_back(s1);
        save2.emplace_back(s2);
        c++;
        int i = n/2;
        while(i >= 1 && b[i] == 1){
            b[i] = 0;
            i--;
        }
        if(i == 0){
            mark = 1;
        }
        else{
            b[i] = 1;
        }
    }
    sort(save2.begin(), save2.end());
    // for(int i = 0; i < c; i++){
    //     cout << save1[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i < c; i++){
    //     cout << save2[i] << " ";
    // }
    // cout << "\n";
    for(int i = 0; i < c; i++){
        int index = lower_bound(save2.begin(), save2.end(), s/2 - save1[i]) - save2.begin();
        // cout << s - 2*(save1[i] + save2[index]) << " ";
        res = min(res, abs(s - 2*(save1[i] + save2[index])));
        // if(index > 0){
        //    res = min(res, abs(s - 2*(save1[i] + save2[index - 1])));  
        // }
    }
    printf("%lld", res); 
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s += a[i];
    }
    process();
    return 0;
}