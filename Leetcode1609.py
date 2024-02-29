class Solution(object):
    def isEvenOddTree(self, root):
        # Check if the tree is empty
        if not root:
            return True  # Empty tree is an even-odd tree

        queue = deque([root])
        level = 0

        while queue:
            size = len(queue)
            temp = []  # Temporary list to store values at the current level

            for i in range(size):
                current = queue.popleft()
                temp.append(current.val)

                # Enqueue child nodes for the next level
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)

            # Check values at the current level based on the level's parity
            if level % 2 == 0:
                # For even levels, 
                # 1) values should be odd
                # 2) strictly increasing
                for i in range(len(temp)):
                    if temp[i] % 2 != 1 or (i > 0 and temp[i] <= temp[i - 1]):
                        return False  # Not an even-odd tree
            else:
                # For odd levels,
                # 1) values should be even
                # 2) strictly decreasing
                for i in range(len(temp)):
                    if temp[i] % 2 != 0 or (i > 0 and temp[i] >= temp[i - 1]):
                        return False  # Not an even-odd tree

            level += 1

        return True  # The tree is an even-odd tree