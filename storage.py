
class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
        #""" Store the data, and set next to None"""

            #""" Return a string representation of the data """
        def __str__(self):
           return str(self.data)
  


class Storage:
    def __init__(self):
        self.head = None

        #""" Creates an empty Storage class. Sets head to None. """


                    
    #""" Create a Node to hold the data, then put it at the head of the list. """
    def push(self, data):
        # Check if head is None
        if(self.head == None):
            self.head = Node(data)
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

        #""" Remove the head Node and return its data. """
    def pop(self):
        if(self.head == None):
            return None
        else:
            popped_data = self.head.data
            self.head = self.head.next
            return popped_data


    # """ Return the data from the head Node, without removing it. """
    def peek(self):
        if(self.isempty()):
            print("Nothing to peek in the Storage")
        return self.head.data

    #""" Return True if the list is empty, otherwise False """
    def isempty(self):
        return self.head == None
