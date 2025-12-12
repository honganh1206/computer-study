class Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None
        self.previous_node = None


class LinkedList:
    def __init__(self, first_node):
        self.first_node = first_node

    def read(self, index):
        current_node = self.first_node
        current_index = 0
        while current_index < index:
            current_node = current_node.next_node
            current_index += 1
            # Check if we reach the end
            # Return none if the index we are searching is not in the list
            if not current_node:
                return None
        return current_node.data

    def index_of(self, value):
        current_node = self.first_node
        current_index = 0
        while True:
            if current_node is None:
                break
            if current_node.data == value:
                return current_index
            current_node = current_node.next_node
            current_index += 1

    def insert_at_index(self, index, value):
        new_node = Node(value)
        # Insert at the beginning
        if index == 0:
            new_node.next_node = self.first_node
            self.first_node = new_node
            return  # End the method early as we have nothing to do
        current_node = self.first_node
        current_index = 0
        # Insert somewhere else
        while current_index < (index - 1):
            current_node = current_node.next_node
            current_index += 1
        # Have the new node linked to the next node
        new_node.next_node = current_node.next_node
        current_node.next_node = new_node

    def print_elements(self):
        current_node = self.first_node
        while current_node:
            print(current_node.data)
            current_node = current_node.next_node

    def return_last_element(self):
        current_node = self.first_node
        while current_node:
            if current_node.next_node is None:
                return current_node.data
            else:
                current_node = current_node.next_node
        return None

    def reverse_list(self):
        current_node = self.first_node
        previous_node = None
        while current_node:
            next_node = current_node.next_node
            current_node.next_node = previous_node
            previous_node = current_node
            current_node = next_node
        self.first_node = previous_node

    # Ex5
    def delete_middle_node(self, target_node):
        # Overwrite the target node's data
        target_node.data = target_node.next_node.data
        # Link the copied node with the node that is two nodes to the right of it
        target_node.next_node = target_node.next_node.next_node


class DoublyLinkedList:
    def __init__(self, first_node=None, last_node=None):
        self.first_node = first_node
        self.last_node = last_node

    def read(self, index):
        current_node = self.first_node
        current_index = 0
        while current_index < index:
            current_node = current_node.next_node
            current_index += 1
            # Check if we reach the end
            # Return none if the index we are searching is not in the list
            if not current_node:
                return None
        return current_node.data

    def insert_at_end(self, value):
        new_node = Node(value)
        # If there is no element in the linked list
        if not self.first_node:
            self.first_node = new_node
            self.last_node = new_node
        else:
            new_node.previous_node = self.last_node
            self.last_node.next_node = new_node
            self.last_node = new_node

    def remove_from_front(self):
        removed_node = self.first_node
        self.first_node = self.first_node.next_node
        return removed_node

    # Ex4
    def reverse(self):
        current_node = self.first_node
        previous_node = None
        while current_node:
            next_node = current_node.next_node # Keep a ref to the next node before modifying the current node
            current_node.next_node = previous_node # Reverse the link of the current node
            previous_node = current_node # current_node becomes the previous_node for the next iteration
            current_node = next_node
        self.first_node = previous_node # The the last node of the original list to the 1st node

    def print_elements(self):
        current_node = self.first_node
        while current_node:
            print(current_node.data)
            current_node = current_node.next_node


class Queue:
    def __init__(self):
        self.data = DoublyLinkedList()

    def enqueue(self, element):
        self.data.insert_at_end(element)

    def dequeue(self):
        removed_node = self.data.remove_from_front()
        return removed_node.data

    def read(self):
        if not self.data.first_node:
            return None
        return self.data.first_node.data


node_1 = Node("Hello")
node_2 = Node("World")
node_3 = Node("!")
node_4 = Node("Nope")

node_1.next_node = node_2
node_2.next_node = node_3
node_3.next_node = node_4

list = LinkedList(node_1)
# list.delete_middle_node(node_2)
# list.print_elements()
doubly_list = DoublyLinkedList(node_1, node_2)
# doubly_list.insert_at_end(node_3)
# doubly_list.insert_at_end(node_4)

doubly_list.reverse()
doubly_list.print_elements()
# print(list.return_last_element())
# list.reverse_list()
# print(list.first_node)
# doubly_list.insert_at_end("Suck")
# list.print_elements()
# doubly_list.print_elements_reverse()
# print(doubly_list.read(2))

# print(list.index_of("Hello"))

# list.insert_at_index(1, "My")
# list.insert_at_index(2, "My2")
# list.insert_at_index(3, "My3")

# print(list.read(1))
# print(list.read(2))
# print(list.read(3))
