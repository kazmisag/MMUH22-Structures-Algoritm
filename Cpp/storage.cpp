
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
    }

    // Constructor with data
    Node(int data)
    {
        this->data = data; /*assign data */
    }
};

class Storage
{
public:
    Node *head;

    /** Default constructor
     *
     */
    Storage()
    {
        this->head = nullptr; // initialize the head
    }

    /** Create a Node to hold the data, then put it at the head of the list.
     * @param data The data for the new node
     */
    void push(int data)
    {
        Node *new_node = new Node(data);

        new_node->next = head;
        head = new_node; // point head at the new node
    }

    /** Remove the head Node and return its data.
     *
     * @param [out] The data (only valid if return true)
     * @return True if there is a node to return
     */
    bool pop(int &data)
    {
        if (head == nullptr)
        {
            return false;
        }
        else
        {
            Node *temp = head;
            data = temp->data; // return data by reference

            //       cout<<data<<" popped\n"; // Test popping

            head = temp->next; // move head to next node
            // cout<<"Next Data is "<<head->data<<endl;
            delete temp; // free memory
            return true;
        }
    }

    /**
     * Return the data from the head Node, without removing it.
     *
     * @param [out] The data (only valid if return true)
     * @return True if text has been returned successfully (there is a node)
     */
    bool peek(int &data)
    {
        if (isEmpty())
            return false;

        data = head->data;
        return true;
    }

    /**
     * Return True if the list is empty, otherwise False
     *
     * @return True if the list is empty, otherwise False
     */
    bool isEmpty()
    {
        bool is_empty = false; // flag set to not empty
        if (head == nullptr)
            is_empty = true;

        return is_empty;
    }

    /**
     * Swaps the nodes at position i and j.
     *
     * @return Returns true if successful, otherwise false (e.g. outside range)
     */
    /**  Frivillig, avkommentera om du implementerar. Avkommentera även i test_storage.cpp
    */
   /* bool swap(int i, int j){

        Node *iNode, *jNode, *iPrev, *jPrev, *temp;
        *temp = head;

        //find i and j nodes
        while(j>)
        retrurn true;
    }
*/
    // Print data by looping through the stack list
    void print_stack()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next; // Get next node
        }
    }
}; // END OF Class Storage

/*
int main(int argc, char *argv[])
{
    Storage *s = new Storage();
    // Check if stack is empty

    if (s->isEmpty())
        cout << "Empty Stack List\n";
    else
        cout << "Stack list contains data\n";

    for (int i = 0; i < 5; i++)
    {
        s->push(i); // Push some data
    }
    // if (s->isEmpty())
    //     cout << "Empty Stack List\n";
    // else
    //     cout << "Stack list contains data\n";
    // printf(s->isEmpty() ? "Empty not Stack" : "Stack Empty");

    int d;
    s->pop(d);
    cout << d << "popped" << endl;
   
    s->print_stack();
     
        s->pop(d);
    return 0;
}
*/