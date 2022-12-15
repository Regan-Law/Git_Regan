tu = ('TY', 'apple', 'boy', 'cat', 'dog', 'egg', 'fat', 'good', 'high', 'image', 'jaw', 'knock', 'look', 'money', 'new')

class BTnode(object):  # 创建树结点

    def __init__(self, data=-1, left_child=None, right_child=None):
        self.data = data
        self.left_child = left_child
        self.right_child = right_child

class BiTree(object):  # 定义二叉树类，并给一个root根结点，一开始为空，随后添加结点

    def __init__(self, root=None):
        self.root = root

    def add(self, data):  # 树的自定义添加结点操作，左右结点依次添加即按照层序遍历的方式添加
        node = BTnode(data)  # 实例一个结点
        if self.root is None:  # 如果树为空，即没有根结点
            self.root = node  # 给树创建一个根结点
            return  # 注意这个return # 遇到return推出函数
        queue = [self.root]  # 这一步表示，已经有了根结点，将它取出放到队列里
        while queue:  # 遍历队列，队列不为空时，执行以下序列
            cur = queue.pop(0)  # 弹出队列的第一个元素（结点），pop默认pop(-1)
            if cur.left_child is None:  # 如果结点左侧没有子结点
                cur.left_child = node
                return  # 遇到return推出函数
            else:  # 如果左侧存在子结点
                queue.append(cur.left_child)  # 将左侧的子结点添加到队列中
            if cur.right_child is None:  # 如果结点右侧没有子结点
                cur.right_child = node
                return
            else:
                queue.append(cur.right_child)

    def preorder(self, node):
        if node is None:
            return
        print(node.data, end=" ")
        self.preorder(node.left_child)
        self.preorder(node.right_child)

    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left_child)
        print(node.data, end=" ")
        self.inorder(node.right_child)

    def postorder(self, node):
        if node is None:
            return
        self.postorder(node.left_child)
        self.postorder(node.right_child)
        print(node.data, end=" ")

if __name__ == '__main__':
    t = BiTree()
    for i in range(15):
        t.add(tu[i])
    print("递归前序遍历:", end=" ")
    t.preorder(t.root)
    print()
    print("递归中序遍历:", end=" ")
    t.inorder(t.root)
    print()
    print("递归后序遍历:", end=" ")
    t.postorder(t.root)
    print()

tu14 = ('new')
tu13 = ('money')
tu12 = ('look')
tu11 = ('knock')
tu10 = ('jaw')
tu9 = ('image')
tu8 = ('high')
tu7 = ('good')
tu6 = ('fat', tu13, tu14)
tu5 = ('egg', tu11, tu12)
tu4 = ('dog', tu9, tu10)
tu3 = ('cat', tu7, tu8)
tu2 = ('boy', tu5, tu6)
tu1 = ('apple', tu3, tu4)
tu0 = ('TY', tu1, tu2)
tu = (tu0, tu1, tu2, tu3, tu4, tu5, tu6, tu7, tu8, tu9, tu10, tu11, tu12, tu13, tu14)
result = []

def add(t, i):
    result.append(t[i][0])

def dfs_before(t, i):
    t = tu[i][0]
    l = tu[i][1][0]
    f = tu[i][2][0]
    result.append(t)
    #if tu[i][1] and tu[i][2]:
    dfs_before(tu[i][1][0], i + 1)
    dfs_before(tu[i][2][0], i + 1)
    #else:
    #    return

# 中序遍历
def dfs_middle():
    #if root==None:
    #    return
    #dfs_middle(root.left)
    #result.append(root)
    #dfs_middle(root.right)
    result.append(tu[0])

# 后序遍历
def dfs_after():
    #if root==None:
    #    return
    #dfs_after(root.left)
    #dfs_after(root.right)
    #result.append(root)
    result.append(tu[0])

class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 用列表递归创建二叉树
def createTree(root, turtle, i):
    if i < len(turtle):
        if turtle[i] == 'null':
            return None
        else:
            root = TreeNode(val=turtle[i])
            root.left = createTree(root.left, turtle, 2 * i + 1)
            root.right = createTree(root.right, turtle, 2 * i + 2)
    return root

class Solution:

    def preorderTraversal(self, root: TreeNode):  # 前序

        def preorder(root: TreeNode):
            if not root:
                return
            res.append(root.val)
            preorder(root.left)
            preorder(root.right)

        res = []
        preorder(root)
        return res

    def inorderTraversal(self, root: TreeNode):  # 中序

        def inorder(root: TreeNode):
            if not root:
                return
            inorder(root.left)
            res.append(root.val)
            inorder(root.right)

        res = []
        inorder(root)
        return res

    def postorderTraversal(self, root: TreeNode):  # 后序

        def postorder(root: TreeNode):
            if not root:
                return
            postorder(root.left)
            postorder(root.right)
            res.append(root.val)

        res = []
        postorder(root)
        return res

if __name__ == "__main__":
    root = TreeNode()
    # 第一种
    list_n = TreeNode(val='A', left=TreeNode(val='B', left=TreeNode(val='D', left=TreeNode('G'), right=TreeNode('H'))),
                      right=TreeNode(val='C', left=TreeNode(val='E', right=TreeNode('I')), right=TreeNode('F')))
    # 第二种
    list_n = TreeNode('A', TreeNode('B', TreeNode('D', TreeNode('G'), TreeNode('H'))),
                      TreeNode('C', TreeNode('E', None, TreeNode('I')), TreeNode('F')))

    s = Solution()
    res_pre = s.preorderTraversal(list_n)
    res_in = s.inorderTraversal(list_n)
    res_post = s.postorderTraversal(list_n)
    print(res_pre)
    print(res_in)
    print(res_post)
dfs_before(tu[0], 0)
for e in result:
    print(e, end=' ')
