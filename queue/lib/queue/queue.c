#include <stdio.h>
#include "queue.h"

int front= -1;
int rear= -1;

int queue[MAX_SIZE];

// Check if queue  is empty
bool is_empty(void)
{
    bool status = false;
    if (front == -1)
        {status = true;}
    
        return status;
}

// If Queue is full
bool is_full(void)
{
    bool status = false;
    if (front == MAX_SIZE - 1)
        status = true;

    return status;
}

// Insert a value in queue
int equeue(int data)
{
    if (is_full())
    {
        return OVER_FLOW_ERR;
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            // Set both pointers at the first index
            front = 0;
            rear = 0;
        }
        else
        {
            front += 1; // move the index number
        }
    }
    queue[front] = data; // store data in the queue
    return OKAY;
}

// remove a value from the queue FIFO
int dqueue()
{
    // bool status =false;

    if (is_empty())
    {
        return -1;
    }
    else
    {
        rear+=1;
        return queue[rear];
    }
}

bool peek(void)
{
    return true;
}
/*
int main(void)
{

    while (true)
    {

        int data =
    }
    return 0;
}
*/