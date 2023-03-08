#include <iostream>
#include <vector>

using namespace std;
// Define a recursive function

int list_sum_rec(vector<int> &vec_list, int size)
{
    if (size < 0)
    {
        return 0; // empty
    }
    else
    {
        cout << size << endl;
        return vec_list[size] + list_sum_rec(vec_list, size - 1);
    }
}

// Find a negative number

bool is_negative(vector<int> &v, int size)
{
    if (size < 0)
        return false; // no number in the vector
    else
    {
        return v[size] < 0 || is_negative(v, size - 1);
    }
}
int main(void)
{
    int sum;
    vector<int> vec_list;
    for (int i = 0; i < 10; i++)
    {
        sum += i;
        vec_list.push_back(i);
    }
    vec_list.push_back(-11); // push a negative number`
    // Call Recursive function
    cout << list_sum_rec(vec_list, vec_list.size()) << endl;
    cout << "sum " << sum;

    // Call func to check negative number

    printf("%s", is_negative(vec_list, vec_list.size()) ? "\nNegative number" : "\nNo negative number");

    return 0;
}