#include<iostream>

using namespace std;

long long a[1000006];
long long s[1000006] = {0};
int n = 0;
int indexx = 0;
long long maxx = -99999999999999;

void process(){
    long long min = 99999999999999;
    int l = 0;
    int r = 0;
    for(int i = 0; i <= n; i++){
        if(min > s[i]){
            min = s[i];
            indexx = i;
        }

        long long temp = s[i] - min;
        if(maxx < temp){
            maxx = temp;
            l = indexx + 1;
            r = i;
        }
    }
    cout << l << " " << r << " " << maxx;
}

int main(){
    scanf("%d", &n);
    int mark = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        if(a[i] > 0){
            mark = 1;
        }
        s[i] = s[i - 1] + a[i];
    }
    
    if(mark == 1){
        process();
    }
    else{
        for(int i = 1; i <= n; i++){
            if(maxx < a[i]){
                maxx = a[i];
                indexx = i;
            }
        }
        cout << indexx << " " << indexx << " " << maxx;
    }
    
}