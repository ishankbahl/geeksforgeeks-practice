#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    
    int i, num, j;
    
    cin>>num;
    
    for(i = 0; num >= pow(2, i); i++);
    
    i--;
    
    for(j = 0; i > -1; i--, j++){
        ((num / (int)pow(2, i)) != 0)? cout<<1 : cout<<0;
        num = ((num / (int)pow(2, i)) != 0)? num % (int)pow(2, i) : num;
    }
    
    return 0;
}