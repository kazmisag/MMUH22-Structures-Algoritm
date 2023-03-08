#include<iostream>
#include<vector>

#define MAX_SIZE 10
using namespace std;

int main(void)
{

vector<int> vec1; // vector of int type

for(int i =0; i< MAX_SIZE; i++)
{
vec1.push_back(i);
}

for(vector<int>::iterator it = vec1.begin();  it!=vec1.end(); it++)
{
    cout<<*it<<endl;// dereference vector to print its value

}
    return 0;
}