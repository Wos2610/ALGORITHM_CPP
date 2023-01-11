#include<iostream>
#include<algorithm>
#include<stdbool.h>

using namespace std;

// Khoi tao cau hinh ban dau (0...0)
// Bien mark de danh dau dieu kien dung
int a[1000006], mark = 0, n = 0;

void sinhNP(int n){
    // Xet tu cuoi cua day nhi phan do dai n
    int i = n;
    // Tim phan tu 0 dau tien xuat hien trong day 
    // Doi cac phan tu sau no thanh 0
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0){
        // Neu khong tim duoc phan tu 0 nao thi ket thuc qua trinh sinh
        mark = 1;
    }
    else{
        // Doi phan tu 0 dau tien thanh 1
        a[i] = 1;
    }
}
void process(){
    int n;
    cin >> n;
    while(mark == 0){
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << "\n";
        sinhNP(n);
    } 
}

int main(){
    process();
}
    