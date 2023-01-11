#include<iostream>
#include<algorithm>

using namespace std;
#define M 1000006

int n, dem;
int x[M], c[M], l[M], r[M];
// x[M] : quan hau o hang i
// c[M] : danh dau cot da bi chiem
// l[M] : duong cheo trai bị chiem
// r[M] : duong cheo phai bi chiem

void Try(int i){
    // Xet quan hau o hang i cot j
    for(int j = 1; j <= n; j++){
        if(c[j] == 0 && l[i - j + n] == 0 && r[i + j - 1] == 0){
            x[i] = j;
            c[j] = 1;
            l[i - j + n] = 1;
            r[i + j - 1] = 1;

            if(i == n){
                dem++;
            }
            else{
                Try(i + 1);
            }
            
            x[j] = 0;
            c[j] = 0;
            l[i - j + n] = 0;
            r[i + j - 1] = 0;
        } 
    }
}
int main(){
    cin >> n;
    Try(1);
    cout << dem;
}
    