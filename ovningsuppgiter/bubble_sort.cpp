#include <iostream>

#define MAX_SIZE 5

using namespace std;

void bubble_sort(int unsorted_list[])
{
    int count = 0;   // total comparison counter
    int i_count = 0; // comparison counter in inner loop

    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        i_count = 0; // Reset the optimisation counter for next iteration of inner loop
        // Optimise the sorting by using i to reduce number to iterations
        for (int j = 0; j < MAX_SIZE - 1 - i; j++)
        {
            count++;
            if (unsorted_list[j] > unsorted_list[j + 1])
            {
                int temp = unsorted_list[j];
                unsorted_list[j] = unsorted_list[j + 1];
                unsorted_list[j + 1] = temp;
                i_count++; // increment
            }
        }
        // Check if we have not swapped any element in
        if (i_count == 0)
            break;
    }
    cout << "Comparison count " << count << endl;
}

int main(void)
{
    int unsorted_list[MAX_SIZE] = {5, 3, 4, 2, 7};
    int sorted_list[MAX_SIZE] = {1, 2, 3, 5, 7};
    int mixed_list[MAX_SIZE] = {2, 1, 3, 5, 7};

    // Call bubble sort function
    bubble_sort(unsorted_list);

    for (int i = 0; i < 5; i++)
    {
        cout << unsorted_list[i] << endl;
    }

    // pass a sorted list
    bubble_sort(sorted_list);
    for (int i = 0; i < 5; i++)
    {
        cout << sorted_list[i] << endl;
    }

    // Pass a mixed sorted list
    bubble_sort(mixed_list);
    for (int i = 0; i < 5; i++)
    {
        cout << mixed_list[i] << endl;
    }
    return 0;
}
