#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
#include<map>

void groupOfNumber(int* arr,int size){
    int *oucarr = new int[1000] {0};

    for(int i=0; i<size; i++){
        int incri = 0;
        if(oucarr[arr[i]] == 0){
            incri++;
            oucarr[arr[i]] = incri;
        }
        else{
            int val = oucarr[arr[i]];
            val++;
            oucarr[arr[i]] = val;
        }
    }
    for(int i=0; i<=1000; i++){
        int ans = -1;
        int maxo = INT_MIN;
        for(int j=0; j<=1000; j++){
            if(oucarr[j] != 0 && oucarr[j] >= maxo){
                maxo = max(maxo,oucarr[j]);
                ans = j;
            }
        }
        if(ans != -1){
            cout<<ans<<" ";
            oucarr[ans] = 0;
        }
    }
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
	groupOfNumber(arr,size);
    return 0;
}