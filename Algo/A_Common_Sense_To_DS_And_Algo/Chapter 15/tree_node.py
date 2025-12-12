class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left_child = left
        self.right_child = right

    def search(self, search_value, node):
        # Return none even if the node we are looking for is non-existent
        if node is None or node.value == search_value:
            return node
        elif search_value < node.value:
            return self.search(search_value, node.left_child)
        else:
            return self.search(search_value, node.right_child)

    def insert(self, value, node):
        if value < node.value:
            # If the left child does not exist, we want to insert the value as the left child
            if node.left_child is None:
                node.left_child = TreeNode(value)
            else:
                self.insert(value, node.left_child)
        elif value > node.value:
            # If the right child does not exist, we want to insert the value as the right child
            if node.right_child is None:
                node.right_child = TreeNode(value)
            else:
                self.insert(value, node.right_child)

    """
    Finds the successor node to replace the node to be deleted
    """

    def lift(self, node, node_to_delete):
        # If the current node has a left child, recursively search for the successor node
        if node.left_child:
            node.left_child = self.lift(node.left_child, node_to_delete)
            return node
        # If the current node has no left child, it's the successor node
        else:
            node_to_delete.value = node.value
            return node.right_child

    def delete(self, value_to_delete, node):
        # Reaching bottom of the tree, and the parent node has no children
        if node is None:
            return None
        # Switch recursive searching to the right or left subtree from the current node
        # NOTE:
        elif value_to_delete < node.value:
            # Overwrite the current node's left child to be the result of the recursive calls
            node.left_child = self.delete(value_to_delete, node.left_child)
        elif value_to_delete > node.value:
            node.right_child = self.delete(value_to_delete, node.right_child)
        # If we find the node to delete, then the current node's left or right child will change
        elif value_to_delete == node.value:
            # Return its right child and its subtree (if existent) to be its parent's new subtree
            if node.left_child is None:
                return node.right_child
            elif node.right_child is None:
                return node.left_child
            # If the node to delete has both left and right children, find its successor node
            else:
                node.right_child = self.lift(node.right_child, node)
                return node

    def traverse_inorder(self, node):
        if node is None:
            return
        self.traverse_inorder(node.left_child)
        print(node.value)
        self.traverse_inorder(node.right_child)

    def traverse_preorder(self, node):
        if node is None:
            return
        print(node.value)
        self.traverse_preorder(node.left_child)
        self.traverse_preorder(node.right_child)

    def traverse_postorder(self, node):
        if node is None:
            return
        self.traverse_postorder(node.left_child)
        self.traverse_postorder(node.right_child)
        print(node.value)

    def find_greatest(self, node):
        """
        1. Start at the root: Begin by visiting the root node of the binary search tree.
        2. Traverse right: Since the greatest value in a binary search tree is located at the rightmost node, move to the right child of the current node.
        3. Check for a right child: If the current node has a right child, move to that child and repeat step 3. Otherwise, continue to step 4.
        4. Found the greatest value: If the current node does not have a right child, it means you have reached the rightmost node of the tree, which contains the greatest value.
        5. Backtrack if necessary: If you have moved to a right child in step 3, but that right child also has a right child, you need to backtrack to the parent node and visit its left child. Repeat steps 3 and 4 until you reach a node without a right child.
        """
        if node.right_child is None:
            return node.value
        else:
            return self.find_greatest(node.right_child)


node3 = TreeNode(20)
node4 = TreeNode(40)
node5 = TreeNode(35)
node6 = TreeNode(85)
node1 = TreeNode(25, node3, node4)
node2 = TreeNode(75, node5, node6)

root = TreeNode(50, node1, node2)

# print(root.search(85, root))

# root.traverse_inorder(node2)
greatest = root.find_greatest(root)
print(greatest)
