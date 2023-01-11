#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0); 
int mark = 0, n = 0;

void sinhHV(int n){
    // Xet tu phan tu sat cuoi
    int i = n - 1;
    // Tim phan tu dau tien lam mat tinh khong giam cua day
    while(i >= 1 && a[i] >= a[i + 1]){
        i--;
    }
    int k = i;
    // Neu khong tim duoc thi ket thuc qua trinh sinh
    if(i == 0){
        mark = 1;
    }
    else{
        int temp = -1;
        // Xet tu cuoi day den sat phan tu duoc danh dau, tim phan tu dau
        // tien lon hon a[k]
        for(int i = n; i > k; i--){
            if(a[i] > a[k]){
                temp = i;
                break;
            }
        }
        // cout << k << " " << temp << " ";
        // Doi cho 2 phan tu cho nhau
        swap(a[k], a[temp]);
        // Sap xep cac phan tu tu sau k trơ di tang dan
        sort(a.begin() + k + 1, a.begin() + n + 1);
    }
    
}
void process(){
    int n;
    cin >> n;
    // Khoi tao cau hinh ban dau 12...n
    for(int i = 1; i <= n; i++){
        a[i] = 1;
    }
    while(mark == 0){
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << "\n";
        sinhHV(n);
    } 
}

int main(){
    process();
}
    