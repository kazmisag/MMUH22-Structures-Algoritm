#include<stdio.h>
#include<iostream>


int factorial(int n)
{
    if(n==1) return 1;
    else return n*factorial(n-1);
}

int main(void)
{
printf("%d ",factorial(5));

std::cout<<factorial(6)<<std::endl;
    return 0;
}