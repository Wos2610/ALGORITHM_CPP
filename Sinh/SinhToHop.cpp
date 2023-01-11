#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0); 
int mark = 0, n = 0;

void sinhTH(int n, int k){
    int i = k;
    // Tim phan tu dau tien ma chua la gioi han tren n - k + i
    while(i >= 1 & a[i] == n - k + i){
        i--;
    }

    if(i == 0){
        mark = 1;
    }
    else{
        // Tang phan tu tim duoc len 1 don vi
        a[i]++;
        // Doi cac phan tu sau phan tu tim duoc thanh can duoi
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
    
}
void process(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
    while(mark == 0){
        for(int i = 1; i <= k; i++){
            cout << a[i];
        }
        cout << "\n";
        sinhTH(n, k);
    } 
}

int main(){
    process();
}
    