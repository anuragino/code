#include<bits/stdc++.h>
using namespace std;

long long reversedBits(long long X) {
    // code here
    long long rev =0;
    int pw = 31;
    
    while(X != 0){
        rev += ((X&1)<<pw); // by left shift add bit 
        pw--;
        X=X>>1;  //X>>=1 by right shift removing last bit
    }
    return rev;
}
int main(){
    long long N = 1;
    cout<<reversedBits(N)<<endl;

    return 0;
}
