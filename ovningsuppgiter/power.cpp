#include<iostream>

int power(int n , int po)
{
    if(po==0) return 1;
    
    else return n*power(n, po-1);

}

int main(void)
{

    printf("%d\n",power(5,3));

    std::cout<<power(5,1)<<std::endl;
    return 0;
}