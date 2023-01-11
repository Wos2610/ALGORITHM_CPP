#include<iostream>
#include<string>

using namespace std;
#define M 1000006

int dem, n;
int minn = 999999;
string s[16], s1[16];
// Mang s1[] luu cac hoan vi cua mang s
int mark[36], a[36];
// Mang mark[] dung de danh dau trong khi sinh hoan vi vi tri
// Mang a[] dung de luu cac hoan vi vi tri

// Ham tinh so lan lap (so ki tu xuat hien trong 2 xau lien tiep)
void tinh(string s[]){
    dem = 0;
    for(int i = 1; i < n; i++){
        int a = s[i].size();
        int b = s[i + 1].size();
        for(int j = 0; j < a; j++){
            for(int k = 0; k < b; k++){
                if(s[i + 1][k] == s[i][j]){
                    dem++;
                }
            }
        }
    }
}

// Thuc hien sinh hoan vi cac vi tri cua cac xau
void Try(int i){
    for(int j = 1; j <= n; j++){
        if(mark[j] == 0){
            a[i] = j;
            mark[j] = 1;
            if(i == n){
                for(int k = 1; k <= n; k++){
                    s1[k] = s[a[k]];
                }
                tinh(s1);
                minn = min(minn, dem);
            }
            else{
                Try(i + 1);
            }
            mark[j] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    Try(1);
    cout << minn;
}
    