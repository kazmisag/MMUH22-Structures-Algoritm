#include <unity.h>
#include "queue.h"

void setUp(void) {}

void tearDown(void) {}

// write down your test functions here

void test_queue(void)
{

    TEST_ASSERT_TRUE(is_empty());

    TEST_ASSERT_FALSE(is_full());

    TEST_ASSERT_EQUAL_INT(-1, dqueue()); // empty queue if front = -1

    equeue(1); // Insert a value
    TEST_ASSERT_FALSE(is_empty());
    
    for(uint16_t i =0; i< MAX_SIZE; i++)
    {
    equeue(i); // Insert a value
    }
    TEST_ASSERT_FALSE(is_empty()); // Check if queue is empty
    TEST_ASSERT_TRUE(is_full()); // Check if queue is Full
}


int main(void)
{

    UNITY_BEGIN();

    // Call your test functions
    RUN_TEST(test_queue);

    return UNITY_END();
}
