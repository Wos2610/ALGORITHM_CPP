#include<iostream>
#include<queue>
#include<string>

using namespace std;

priority_queue <long long, vector<long long>> q;

long long a[36];
int k;
string s;

void process(){
    for(int i = 0; i < 26; i++){
        a[i] = 0;
    }

    int n = s.size();
    if(k >= n){
        cout << "0\n";
        return;
    }
    for(int i = 0; i < n; i++){
        a[s[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(a[i] != 0){
            q.push(a[i]);
        }
    }

    while(k > 0){
        if(q.size() != 0){
            int temp = q.top();
            q.pop();
            temp--;
            q.push(temp);
            k--;
        }
        else{
            break;
        }
    }

    // cout << q.size() << " ";
    long long res = 0;
    while(q.size() != 0){
        long long k = q.top();
        res += k * k;
        // cout << k << " ";
        q.pop();
    }
    
    cout << res << "\n";
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cin >> k;
        cin >> s;
        process();
    }
    return 0;
}