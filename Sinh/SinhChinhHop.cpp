#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0); 
int mark = 0, n = 0;

void sinhTH(int n, int k){
    int i = k;
    while(i >= 1 & a[i] == n - k + i){
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        a[i]++;
        for(int j = i + 1; j <= n; j++){
            a[j] = a[j - 1] + 1;
        }
    }
    
}

void sinhHV(int n){
    int i = n - 1;
    while(i >= 1 && a[i] >= a[i + 1]){
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        int k = i;
        int min = 9999999;
        int temp = -1;
        for(int i = k + 1; i <= n; i--){
            if(a[i] > a[k] && a[i] < min){
                min = a[i];
                temp = i;
            }
        }
        swap(a[k], a[temp]);
        sort(a.begin() + k + 1, a.begin() + n);
    }
}

void process(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
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
    