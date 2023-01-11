#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

int n;
int a[M], b[M];

void quickSort(int b[], int l, int r){
    int i = l;
    int j = r;
    int pivot = b[(l + r)/2];
    while(i <= j){
        while(b[i] < pivot){
            i++;
        }
        while(b[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if(l < j){
        quickSort(b, l , j);
    }
    if(i < r){
        quickSort(b, i, r);
    }
}

int binarySearch(int b[], int n, int x){
    int l = 0;
    int r = n - 1;
    
    while(l <= r){
        int mid = (l + r)/2;
        if(b[mid] == x){
            return mid;
        }
        if(b[mid] < x){
            l = mid + 1;
        }
        if(b[mid] > x){
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    quickSort(b, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        cout <<  binarySearch(b, n , a[i]) << " ";
    }

}
    