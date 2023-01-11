#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

int n;
long long res = 99999999999999999;
string a[56], b[56];

int c[56][26];

long long change(int index, string s, string a[], string b[]){
    long long dem = 0;
    int k = a[0].size();
    int mark = 0;
    for(int i = 0; i < n; i++){
        if(i != index){
            long long temp = 0;
            while(s == a[i]){
                mark = 1;
                i++;
                
            }
            for(int j = 1; j <= k; j++){
                a[i].push_back(a[i][0]);
                a[i].erase(0, 1);
                // cout << i << " " << a[i] << " ";
                temp++;
                if(s == a[i]){
                    mark = 1;
                    if(temp < k){
                        dem += temp;
                    }
                    // cout << temp << " ";
                    a[i] = b[i];
                    break;
                }
            }
            if(mark == 0){
                return -1;
            }
        }
        
    }
    
    return dem;
}

int check(){
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(c[i][j] != c[0][j]){
                return -1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        long long temp = change(i, a[i], a, b);
        // cout << temp << " ";
        res = min(temp, res);
    }
    
    return res;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
        for(int j = 0; j < a[i].size(); j++){
            c[i][a[i][j] - 'a']++;
        }
    }

    cout << check();
    
}
