#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

char s[1000006];
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
        for(int j = n; j > i; j--){
            if(a[j] > a[k]){
                temp = j;
                break;
            }
        }
        swap(a[k], a[temp]);
        sort(a.begin() + 1 + k, a.begin() + 1 + n);
    }

}


void process(){
    int stt;
    scanf("%d", &stt);
    cin.ignore();
    scanf("%s", &s);
    mark = 0;
    int n = strlen(s);
    for(int i = 1; i <= n; i++){
        a[i] = s[i - 1] - '0';
    }
    HV(n);
    printf("%d ", stt);
    if(mark == 0){
        for(int i = 1; i <= n; i++){
            printf("%d", a[i]);
        }
        printf(" ");
        
    }
    else{
        printf("BIGGEST");
    }
    
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
        printf("\n");
    }
    return 0;
}