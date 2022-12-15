tu=('TY','apple','boy','cat','dog','egg','fat','good','high','image','jaw','knock','look','money','new')
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

    def preorder(self,node):
        if node is None:
            return
        print(node.data, end=" ")
        self.preorder(node.left_child)
        self.preorder(node.right_child)
    def inorder(self,node):
        if node is None:
            return
        self.inorder(node.left_child)
        print(node.data, end=" ")
        self.inorder(node.right_child)
    def postorder(self,node):
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
print('童言', 2015301332, '软工')