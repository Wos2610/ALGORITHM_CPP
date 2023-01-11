#include<iostream>
#include<string>

using namespace std;

string sample = "IVXLCDM";
int value[7] = {1, 5, 10, 50, 100, 500, 1000};

void change(string s, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 7; j++){
            if(s[i] == sample[j]){
                sum += value[j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'I' && s[i + 1] == 'V'){
            sum -= 2;
        }
        if(s[i] == 'I' && s[i + 1] == 'X'){
            sum -= 2;
        }
        if(s[i] == 'X' && s[i + 1] == 'L'){
            sum -= 20;
        }
        if(s[i] == 'X' && s[i + 1] == 'C'){
            sum -= 20;
        }
        if(s[i] == 'C' && s[i + 1] == 'D'){
            sum -= 200;
        }
        if(s[i] == 'C' && s[i + 1] == 'M'){
            sum -= 200;
        }
    }
    cout << sum;
}
int main(){
    string s;
    cin >> s;
    int n = s.size();
    change(s, n);
}