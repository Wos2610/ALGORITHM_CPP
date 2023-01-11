#include<iostream>
#include<algorithm>
#include<queue>
#define M 1000006

using namespace std;

queue <int> q;


int main(){
    int n, temp;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        if(temp == 1){
            cout << q.size() << "\n";
        }
        else if(temp == 2){
            if(q.empty()){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else if(temp == 3){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(temp == 4){
            if(!q.empty()){
                q.pop();
            }
        }
        else if(temp == 5){
            if(!q.empty()){
                cout << q.front() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
        else if(temp == 6){
            if(!q.empty()){
                cout << q.back() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }
}
