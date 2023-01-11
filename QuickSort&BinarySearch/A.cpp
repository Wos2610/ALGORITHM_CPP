#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int a[100006] = {0};

void quickSort(int a[], int l, int r){
    int i = l;
    int j = r;
    int pivot = a[(l + r)/2];
    while(i <= j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j){
        quickSort(a, l, j);
    }
    if(r > i){
        quickSort(a, i, r);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    quickSort(a, 0, n - 1);
    
    cout << a[k - 1];
}