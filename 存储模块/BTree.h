#include"struct.h"
class BTree
{
public:
    BTree(Key keyKind)
    {
        this->keyKind=keyKind;
        pRoot=nullptr;
        pPosition=&pRoot;
    }
    // ~BTree()
    // {
    //     clear();
    // }
    

    // bool contain(const int key) const;
    // void clear();
private:
    static const int M=3;
    static const int KEY_MAX=2*M-1;
    static const int KEY_MIN=M-1;
    static const int CHILD_MAX=KEY_MAX+1;
    static const int CHILD_MIN=KEY_MIN+1;
    struct Node
    {
        Node(bool arg1=true, int arg2=0)
                :isLeaf(arg1),itemListNum(arg2){}
        bool isLeaf;
        int itemListNum;
        ItemList itemListArray[KEY_MAX];
        Node *pChild[CHILD_MAX];
    };
    Node *pRoot;
    Node **pPosition;

    Key keyKind; 
public:
    void insertItem(Item &item);//插入数据项
    bool insertItemList(ItemList &itemlist);
    void splitChild(Node *pParent, int childIndex, Node* pChild);
    void insertNoFull(Node *pNode, ItemList &itemlist);
    void r_dump(Node *pNode) const;
    void dump() const {r_dump(pRoot);}
    ItemList* search(int keyword); //查找对应关键字的项表
    ItemList* search(String keyword); //查找对应String类型关键字的项表
    void mergeChild(Node *pParent, int index);
    void deleteNode(Node *pNode);
    bool remove(Item &item); //构造一个样例item查找B-Tree并删除对应item
    void r_remove(Node *pNode, Item &pItem);
    ItemList getPredecessor(Node *pNode);
    ItemList getSuccessor(Node *pNode);
    int key(Item &item);
};