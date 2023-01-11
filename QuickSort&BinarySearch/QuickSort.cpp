#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int a[1000006] = {0};

void quickSort(int a[], int left, int right){
    int i = left;
    int j = right;
    int pivot = a[(right + left)/2];
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
    if(left < j){
        quickSort(a, left, j);
    }
    if(right > i){
        quickSort(a, i, right);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}