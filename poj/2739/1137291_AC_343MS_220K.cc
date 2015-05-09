#include<iostream.h> 
#include<stdlib.h> 
#include<string.h> 

bool PrimeNumber(int Num){ 
int i; 
if(Num==2) return true; 

for(i=3; i<Num; i+=2){ 
if(Num%i==0) 
return false; 
} 
return true; 
} 

// 소수들이 들어있는 배열 arr, 
// 이미 들어있는지 검사할 n 
// 배열의 길이 k 
bool have(int arr[],int n, int k){     
    int i; 
    for(i=0; i<=k; ++i){ 
        if(arr[i]==n) 
            return true; 
    }     
    return false; 
} 

int main() 
{ 
    int Num,result,count,i,j,k; 
    int pn[1500]; 

    pn[0] = (int)malloc(sizeof(int)); 
    pn[0] = 2; 
    k= 0; 
     
    while(1){ 
        cin >> Num; 
        if(Num==0) break; 

        count = 0; 

        for(i=2; i<=Num; ++i){ 
            if(i%2!=0){                    // 2의 배수가 아니라면  
                if(!have(pn,i,k)){        // 들어 있지 않은 수 라면 
                    if(PrimeNumber(i)){    // 소수라면 
                        k++; 
                        pn[k] = (int)malloc(sizeof(int)); 
                        pn[k] = i; 
                    } 
                } 
            } 
        } 
        for(i=0; i<=k; ++i){ 
            if(pn[i]>Num) 
                break; 
            result = 0; 
            for(j=i; j<=k; ++j){ 
                result+=pn[j]; 
                if(result>Num){ 
                    break; 
                } 
                if(result==Num){ 
                    count++; 
                    break; 
                } 
            } 
        } 
         
        cout << count << endl; 
    } 
    return 0; 
} 
