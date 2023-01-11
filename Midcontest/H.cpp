#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> save;

int main(){
    char a, b;
    while(1){
        cin >> a;
        if(a == 'E'){
            return 0;
        }
        if(a == '1'){
            cin >> b;
            save.emplace_back(b);
            cout << "NEW\n";
        }
        else{
            for(int i = 0; i < save.size(); i++){
                cout << save[i] - '0' <<  " ";
            }
            cout << "\n";
        }
    }

}
    