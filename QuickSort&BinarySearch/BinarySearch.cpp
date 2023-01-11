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

int binarySearch(int a[], int n, int x){
    int l = 0;
    int r = n - 1;
    
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] < x){
            l = mid + 1;
        }
        if(a[mid] > x){
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;

    quickSort(a, 0, n - 1);
    
    cout << binarySearch(a, n, x);
}