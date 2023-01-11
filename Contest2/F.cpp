#include<iostream>
#include<vector>
#define M 46
using namespace std;



void process(){
    int n,k;
    scanf("%d%d", &n, &k);

    int res = 0;
    int du = n % (k + 1);
    if(du % 2 == 0 && du < k){
        res = 2;
    }
    else{
        res = 1;
    }
    if(res == 1){
        printf("Taro");
    }
    else{
        printf("Hanako");
    }

}

int main(){
    process();
    return 0;
}