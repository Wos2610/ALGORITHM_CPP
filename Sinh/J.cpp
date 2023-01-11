#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> b(1000000);
int mark = 0, n = 0, k = 0, s = 0,c = 0;

void sinhTH(){
    int i = k;
    while(i >= 1 && b[i] == n - k + i){
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        b[i]++;
        for(int j = i + 1; j <= k; j++){
            b[j] = b[j - 1] + 1;
        }
    }
}

void hienThi(){
    printf("%d\n", c);
}

void process(){
    if(k > n){
        c = 0;
    }
    else{
        for(int i = 1; i <= k; i++){
            b[i] = i;
        }
        mark = 0;
        c = 0;
        while(mark == 0){
            int sum = 0;
            for(int i = 1; i <= k; i++){
                sum += b[i];  
            }
            if(sum == s){
                c++; 
            }
            sinhTH();
        }
    }
    hienThi();
    

}
int main(){
    while(1){
        scanf("%d%d%d", &n, &k, &s);
        if(n == 0 && k == 0 && s == 0){
            return 0;
        }
        process();
    }
}