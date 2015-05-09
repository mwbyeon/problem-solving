#include <iostream> 
using namespace std; 

int array[30] = {0}; 
int tril(int); 

int main() 
{ 
    int i,k,pos; 
     
    while(1){ 

        cin >> i; 
         
        array[2] = 3; 
        array[4] = 11; 
                 
        if( i == -1 || 0 > i || i > 30 ) 
            break; 
        if ( i == 0 ) 
            cout << "1" << endl; 
        else if ( i % 2 == 1) 
            cout << "0" << endl; 
        else if( i == 2 ) 
            cout << "3" << endl; 
        else if ( i == 4 ) 
            cout << "11" << endl;         
        else{ 
            for(pos=4; pos < i; pos+=2) 
                array[pos+2] = (array[2]*array[pos]) + tril(pos-2); 
             
            cout << array[pos] << endl; 
        } 

    } 

    return 0; 
} 

int tril(int k){ 
    if(k == 0) 
        return 2; 
    if(k == 2) 
        return 8; 
     
    return (array[k]*2)+tril(k-2); 
} 
