#include<iostream>
#include<algorithm>
#include<queue>
#define M 1000006
using namespace std;

int n, sum, m1, m2, mark;
int a[M], d[M];
priority_queue <int> pq;

void in(priority_queue<int> x){
    while(x.size() != 0){
        printf("%d", x.top());
        x.pop();
    }
}

void process(){
    sort(a, a + n);

    for(int i = 0; i < n; i++){
        if(a[i] % 3 == 0){
            d[i] = 0;
        }
        if(a[i] % 3 == 1){
            d[i] = 1;
        }
        if(a[i] % 3 == 2){
            d[i] = 2;
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] % 3 == 1){
            m1 = i;
            break;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] % 3 == 2){
            m2 = i;
            break;
        }
    }

    if(sum == 0){
        printf("0\n");
        return;
    }

    if(sum % 3 == 1){
        if(m1 != -1){
            for(int i = 0; i < n; i++){
                if(i != m1){
                    pq.push(a[i]);
                    // cout << a[i] << " ";
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(d[i] == 0){
                    pq.push(a[i]);
                }
            }
        }
    }
    else if(sum % 3 == 2){
        if(m2 != -1){
            for(int i = 0; i < n; i++){
                if(i != m2){
                    pq.push(a[i]);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(d[i] == 0){
                    pq.push(a[i]);
                }
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            pq.push(a[i]);
        }
    }

    if(pq.size() != 0){
        in(pq);
    }
    else{
        printf("-1");
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        sum = 0;
        while(pq.size() != 0){
            pq.pop();
        }
        m1 = -1, m2 = -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        process();
    }
    return 0;
}