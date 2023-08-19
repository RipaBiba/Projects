#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int n;

void merge_sort(int n, int ara[]){
    if(n==1){
        return;
    }
    int leftSize=n/2;
    int rightSize=n-leftSize;
    int left[leftSize];
    int right[rightSize];
    for(int i=0; i<leftSize; i++){
        left[i]=ara[i];
    }
    for(int i=leftSize; i<n; i++){
        right[i-leftSize]=ara[i];
    }
    merge_sort(leftSize, left);
    merge_sort(rightSize, right);
    int leftMarker=0, rightMarker=0, ind=0;
    while(leftMarker<leftSize && rightMarker<rightSize){
        if(left[leftMarker]<right[rightMarker]){
            ara[ind]=left[leftMarker];
            ind++;
            leftMarker++;
        }
        else{
            ara[ind]=right[rightMarker];
            ind++;
            rightMarker++;
        }
    }
    while(rightMarker<rightSize){
        ara[ind]=right[rightMarker];
        ind++;
        rightMarker++;
    }
    while(leftMarker<leftSize){
        ara[ind]=left[leftMarker];
        ind++;
        leftMarker++;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &ara[i]);
    }
    merge_sort(n, ara);
    for(int i=0; i<n; i++){
        printf("%d ", ara[i]);
    }
    return 0;
}
