/*
遍历方法
前序遍历：根左右
中序遍历：左根右
后序遍历：左右根
层序遍历：从根结点从上往下逐层遍历，在同一层，按从左到右的顺序对结点逐个访问
*/
#include "../common.h"
#include <queue>

using namespace std;

template<typename T>
struct tree_node
{
    /* data */
    T data;
    tree_node<T> *left;
    tree_node<T> *right;
    tree_node(T d) : data(d),left(nullptr),right(nullptr) {};
};

class test_binary_tree
{
private:
    /* data */
public:
    test_binary_tree(/* args */);
    ~test_binary_tree();

    template<typename T>
    bool is_complete(tree_node<T> *pt){
        if(pt == nullptr){
            return false;
        }
        std::queue<tree_node<T>*> q;
        q.push(pt);
        while (!q.empty())
        {
            tree_node<T>* top = q.front();
            if((top->left != nullptr)&&(top->right != nullptr)){
                q.push(top->left);
                q.push(top->right);
                q.pop();
            }
            else if((top->left == nullptr)&&(top->right != nullptr)){
                return false;
            }
            else{
                if(top->left != nullptr){
                    q.push(top->left);
                }
                q.pop();
                while (!q.empty())
                {
                    top = q.front();
                    if(top->left != nullptr || top->right != nullptr){
                        return false;
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
    //满二叉树
    void test1()
    {
        //       1
        //   2       3
        // 4    5  6   7
        tree_node<int> *node1 = new tree_node<int>(1);
        tree_node<int> *node2 = new tree_node<int>(2);
        tree_node<int> *node3 = new tree_node<int>(3);
        tree_node<int> *node4 = new tree_node<int>(4);
        tree_node<int> *node5 = new tree_node<int>(5);
        tree_node<int> *node6 = new tree_node<int>(6);
        tree_node<int> *node7 = new tree_node<int>(7);
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->left = node6;
        node3->right = node7;
        cout <<"test1: "<< is_complete<int>(node1) << endl;
    }
        
    //二叉树为空
    void test2()
    {
        cout << is_complete<int>(NULL) << endl;
    }
    
    //3.二叉树不为空，也不是满二叉树，遇到一个结点左孩子为空，右孩子不为空
    void test3()
    {
        //       1
        //   2       3
        // 4    5      7
        tree_node<int> *node1 = new tree_node<int>(1);
        tree_node<int> *node2 = new tree_node<int>(2);
        tree_node<int> *node3 = new tree_node<int>(3);
        tree_node<int> *node4 = new tree_node<int>(4);
        tree_node<int> *node5 = new tree_node<int>(5);
        tree_node<int> *node7 = new tree_node<int>(7);
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->right = node7;
        cout << is_complete<int>(node1) << endl;
    }
    
    //4.二叉树不为空，也不是满二叉树，遇到叶子节点,则该叶子节点之后的所有结点都为叶子节点
    void test4()
    {
        //        1
        //    2       3
        // 4    5
        tree_node<int> *node1 = new tree_node<int>(1);
        tree_node<int> *node2 = new tree_node<int>(2);
        tree_node<int> *node3 = new tree_node<int>(3);
        tree_node<int> *node4 = new tree_node<int>(4);
        tree_node<int> *node5 = new tree_node<int>(5);
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        cout << is_complete<int>(node1) << endl;
    }
    
    //4.二叉树不为空，也不是满二叉树，遇到左孩子不为空，右孩子为空的结点，则该节点之后的所有结点都为叶子节点
    void test5()
    {
        //        1
        //    2       3
        // 4    5   6
        tree_node<int> *node1 = new tree_node<int>(1);
        tree_node<int> *node2 = new tree_node<int>(2);
        tree_node<int> *node3 = new tree_node<int>(3);
        tree_node<int> *node4 = new tree_node<int>(4);
        tree_node<int> *node5 = new tree_node<int>(5);
        tree_node<int> *node6 = new tree_node<int>(6);
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->left = node6;
        cout << is_complete<int>(node1) << endl;
    }
};

test_binary_tree::test_binary_tree(/* args */)
{
    ilog("test_binary_tree in");
    test1();
    test2();
    test3();
    test4();
    test5();
}

test_binary_tree::~test_binary_tree()
{
}
