#include<iostream>
#include<queue>

using namespace std;
long long a, b;
priority_queue <long long, vector<long long>, greater<long long>> q, q1;


long long cs[26];
long long c[2] = {6, 8};

void Try(int index, int i){
    for(int  j = 0; j < 2; j++){
        cs[index] = c[j];
        if(index == i){
            long long temp = 0;
            for(int k = 1; k <= i; k++){
                temp = temp * 10 + cs[k];
            }
            q.push(temp);
        }
        else{
            Try(index + 1, i);
        }
        cs[index] = 0;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= 18; i++){
        Try(1, i);
    }
    // cout << q.size() << " ";
    // while(q.size() != 0){
    //     cout << q.top() << " ";
    //     q.pop();
    // }
    while(T--){
        scanf("%lld%lld", &a, &b);
        long long count = 0;
        q1 = q;
        while(q1.size() != 0 && q1.top() < a){
            q1.pop();
        }
        while(q1.size() != 0 && q1.top() <= b){
            count++;
            // cout << q1.top() << " ";
            q1.pop();
        }
        printf("%lld\n", count);
    }
    return 0;
}