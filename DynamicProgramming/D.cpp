#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define MOD 1000000007

using namespace std;
int n, k;
int a[10006];

struct Number{
    int f; // luu gia tri
    int s; // luu so lan bam
};

Number b[10006];

bool cmp(Number b1, Number b2){
    if(b1.f == b2.f){
        return b1.s < b2.s;
    }
    return b1.f > b2.f;
}

void process(){
    
    b[0].f = a[0];
    b[0].s = 1;
    for(int i = 1; i < n; i++){
        int begin = 0;
        if(i >= k){
            begin = i - k;
        }
        int maxf = -999999999;
        int index = -1;

        for(int j = begin; j < i; j++){
            if(maxf < b[j].f){
                maxf = b[j].f;
                index = j;
            }
            else if(maxf == b[j].f){
                if(b[j].s < b[index].s){
                    index = j;
                }
            }
        }
        if(maxf < 0 && i < k){
            b[i].f = a[i];
            b[i].s = 1;
        }
        else{
            b[i].f = maxf + a[i];
            b[i].s = b[index].s + 1;
        }
        
    }

    for(int i = 0; i < n; i++){
        cout << b[i].f << " " << b[i].s << "\n";
    }
    sort(b, b + n, cmp);
    cout << b[0].f << " " << b[0].s;
}

int main(){
    int T;
    T = 1;
    
    while(T--){
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        process();
    }
    return 0;
}