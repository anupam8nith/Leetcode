# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode], head: Optional[ListNode]) -> bool:
            if not head:
                return True
            if not root:
                return False
            
            if head.val == root.val:
                return dfs(root.left, head.next) or dfs(root.right, head.next)
            
            return False

        if not root or not head:
            return False
        
        return dfs(root, head) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)