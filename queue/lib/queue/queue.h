#ifndef QUEUE_H
#define QUEUE_H

#include<stdbool.h>

#define MAX_SIZE 5
#define OVER_FLOW_ERR -1
#define OKAY 1



bool is_empty(void);
bool is_full(void);
int equeue(int data);
int dqueue();
bool peek(void);


#endif