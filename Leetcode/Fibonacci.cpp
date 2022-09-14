#include<iostream>
using namespace std;

class Solution {
public:
    void fib(int n) {
        int fi = 0;
        int fs = 1;
        int* arr = new int[n+1] {0};
        int sum = 0; 
        int i=1;
        while(true){
            if(i == n+1){
                break;
            }
            arr[i++] = fs;
            
            sum = fi + fs;            
            fi = fs;
            fs = sum;               
            
        }
        for (int i = 0; i <= n; i++)
        {
            cout<<arr[i]<<" + ";        
        }
        
        cout<<endl<<arr[n];
    }
};


int main(){
    int n = 5;
    Solution *sol =new Solution;
    sol->fib(n);     
    return 0;
}