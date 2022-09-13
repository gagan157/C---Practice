#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

void printarray(string *arr){
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(string* arr, int start, int end)
{
 
    int pivot = arr[start][0];
    int pivs = arr[start][1];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i][0] <= pivot){
            if(arr[i][0] == pivot){
                if(arr[i][1] <= pivs){
                    count++;
                }                
            }
            else
                count++;
        }
    }
    printarray(arr);
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    printarray(arr);
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
         while (arr[i][0] <= pivot) {
            if(arr[i][0] == pivot){
                if(arr[i][1] <= pivs){
                    i++;
                }
            }
            else{
                i++;
            }
        }
 
        while (arr[j][0] > pivot ) {
            if(arr[j][1] == pivot){
                if(arr[j][i] > pivs){
                    j--;
                }
            }
            else{
                j--;
            }
            
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
        printarray(arr);
    }
 
    return pivotIndex;
}

void quickSort(string* arr,int low,int high){
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 

}


int main() {

	string *arr = new string[5];
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    quickSort(arr,0,5-1);
   
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}