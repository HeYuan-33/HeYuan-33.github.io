// 算法5.2.1 先序遍历的非递归算法
#include <iostream>
using namespace std;

// 二叉树的二叉链表存储表示
typedef struct BiNode {
  char data;                       // 结点数据域
  struct BiNode *lchild, *rchild;  // 左右孩子指针
} BiTNode, *BiTree;

// 链栈的定义
typedef struct StackNode {
  BiTNode data;
  struct StackNode *next;
} StackNode, *LinkStack;

// 用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T) {
  // 按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
  char ch;
  cin >> ch;
  if (ch == '#')
    T = NULL;  // 递归结束，建空树
  else {
    T = new BiTNode;
    T->data = ch;             // 生成根结点
    CreateBiTree(T->lchild);  // 递归创建左子树
    CreateBiTree(T->rchild);  // 递归创建右子树
  }                           // else
}  // CreateBiTree

void InitStack(LinkStack &S) {
  // 构造一个空栈S，栈顶指针置空  
  S = NULL;
}

bool StackEmpty(LinkStack S) {
  if (!S) return true;
  return false;
}

void Push(LinkStack &S, BiTree e) {
  // 在栈顶插入元素*e
  StackNode *p = new StackNode;
  p->data = *e;
  p->next = S;
  S = p;
}

void Pop(LinkStack &S, BiTree e) {
  if (S != NULL)  // 原书上写的是if(S==NULL)return ERROR;
  {
    *e = S->data;
    StackNode *p = S;
    S = S->next;
    delete p;
  }
}

void PreOrderTraverse1(BiTree T) {
  // 先序遍历二叉树T的非递归算法
  LinkStack S;
  BiTree p = new BiTNode;
  InitStack(S);

  if (T == NULL) return;

  Push(S, T);  // 根节点进栈

  while (!StackEmpty(S)) {
    Pop(S, p);                          // 弹出栈顶元素p
    cout << p->data;                    // 访问p结点
    if (p->rchild) Push(S, p->rchild);  // 右孩子进栈
    if (p->lchild) Push(S, p->lchild);  // 左孩子进栈
  }                                     // while
}  // PreOrderTraverse

int main() {
  BiTree tree;
  cout << "请输入建立二叉链表的序列：\n";
  CreateBiTree(tree);
  cout << "先序遍历的结果为：\n";
  PreOrderTraverse1(tree);
  cout << endl;
  return 0;
}
6