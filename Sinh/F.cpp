#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0);
int mark = 0;

void HV(int n){
    int i = n - 1;
    while(i >= 1 && a[i] >= a[i + 1]){
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        int k = i;
        int temp = -1;
        int min = 9999999;
        for(int j = k + 1; j <= n; j++){
            if(a[j] > a[k] && min > a[j]){
                min = a[j];
                temp = j;
            }
        }
        swap(a[k], a[temp]);
        sort(a.begin() + 1 + k, a.begin() + 1 + n);
    }
}

void process(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    while(mark == 0){
        for(int i = 1; i <= n; i++){
            printf("%d", a[i]);
        }
        printf(" ");
        HV(n);
    }
}

int main(){
    process();
    return 0;
}