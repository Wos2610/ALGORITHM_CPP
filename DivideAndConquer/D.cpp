#include<iostream>
#include<string>

#define M 10000006

using namespace std;

string s1, s2;

long long change(string s){
    int n = s.size();
    long long temp = 1;
    long long sum = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1'){
            sum += temp;
        }
        temp *= 2;
    }
    return sum;
}

void process(){
    cin >> s1 >> s2;
    long long ans = change(s1) * change(s2);
    printf("%lld\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        process();
    }
    return 0;
}