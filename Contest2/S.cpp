#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void process(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    
    int m[100006] = {0};
    int d[100006] = {0};
    m[0] = d[0] = 0;
    
    for(int i = 1; i <= n; i++){
        if(s[i] == 'M'){
            m[i] = m[i - 1];
            d[i] = d[i - 1] + 1;
            if(d[i] > m[i] + 1){
                d[i] = m[i] + 1;
            }
            // cout << m[i] << " ";
            
        }
        else{
            d[i] = d[i - 1];
            m[i] = m[i - 1] + 1;
            if(m[i] > d[i] + 1){
                m[i] = d[i] + 1;
            }
        }
        // cout << m[i] << " ";
    }

    // cout << m[n] << " " << d[n] ;
    int res = min(m[n], d[n] + 1);

    cout << res << "\n";

}
int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
       process();
    }
    return 0;
}