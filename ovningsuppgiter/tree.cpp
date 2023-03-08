#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

}; // End Class Node

// Managing class for binary nodes

class BinaryTree
{
public:
    Node *root; // head node

    BinaryTree() { this->root = nullptr; }

    // Add a node

    void add_child(int data)
    {
        Node *new_child = new Node(data); // create a new node

        // Check if this is first node
        if (root == nullptr)
        {
            root = new_child; // set new node as root/head node
        }
        else
        {
            Node *current_node = root; // get the root/head node

            Node *parent;

            while (true)
            {
                parent = current_node;
                // move to left if the data is less than the current node data
                if (data > current_node->data)
                {
                    current_node = current_node->left;
                    if (current_node == nullptr)
                    {
                        parent->left = new_child; // add this new node to the left of this node
                        return;                   // end loop
                    }
                }
                else

                // check if we have reached to the depth of tree and this node is NULL
                {
                    current_node = current_node->right; // move to the right node of current node
                    if (current_node == nullptr)
                    {
                        parent->right = new_child; // add new node to the right
                        return;
                    }
                }
            }
        }
    }
    // check if the tree is binary

    // print the sorted binary tree
    void print_binary_tree(Node *current_node)
    {
        if (current_node != nullptr)
        {
            cout << current_node->data<<" "; // print

            // Use recursion to print both left and right
            print_binary_tree(current_node->left);
            print_binary_tree(current_node->right);
        }
    }
}; // End Class BinaryTree

///////////////////// MAIN FUNC//////////////

int main(void)
{
    BinaryTree tree;

    tree.add_child(13);
    tree.add_child(12);
    tree.add_child(3);
    tree.add_child(4);
    tree.add_child(5);
    tree.add_child(77);
    tree.add_child(66);
    tree.add_child(88);
    tree.add_child(9);
    tree.add_child(10);
    tree.add_child(11);
    tree.add_child(2);
    tree.add_child(1);

    tree.print_binary_tree(tree.root);
    return 0;
}