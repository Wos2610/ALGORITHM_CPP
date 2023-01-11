#include<iostream>
#include<math.h>
#define M 1000006
using namespace std;

void process(){
    double x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1)*(y2 - y1));
    int res = d/(2*r);
    int du = d - res*2*r;
    if(du != 0){
        res++;
    }
    cout << res;
}

int main(){
    process();
    return 0;
}