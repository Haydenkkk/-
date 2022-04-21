#include"BTree.h"
#include<iostream>
int BTree::key(Item &item)
{
    if(item.course){
        if(keyKind==Name){
            return (unsigned int)item.course->name[0]*256+(unsigned int)item.course->name[1];
        }else if(keyKind==BeginTime){
            return item.course->beginTime;
        }
    }else if(item.activity){
        if(keyKind==Name){
            return (unsigned int)item.activity->name[0]*256+(unsigned int)item.activity->name[1];
        }else if(keyKind==BeginTime){
            return item.activity->beginTime;
        }
    }
    return 0;
}
void BTree::insertItem(Item &item)
{
    ItemList *theList=search(key(item));
    if(!theList){
        ItemList t_itemList;
        t_itemList.addItem(item);
        insertItemList(t_itemList);
    }else{
        theList->addItem(item);
    }
}
bool BTree::insertItemList(ItemList &itemlist)
{
        if(pRoot==nullptr){
            pRoot=new Node();
        }
        if(pRoot->itemListNum==KEY_MAX){
            Node *pNode=new Node();
            pNode->isLeaf=false;
            pNode->pChild[0]=pRoot;
            splitChild(pNode, 0, pRoot);
            pRoot=pNode;
        }
        insertNoFull(pRoot, itemlist);
        return true;
}
void BTree::insertNoFull(Node *pNode, ItemList &itemlist)//前提为节点未满
{
    int i=pNode->itemListNum;
    if(pNode->isLeaf){
        while(i>0&&key(itemlist.example())<key(pNode->itemListArray[i-1].example())){//一个list键值相同,从中取一个item比较键值
            pNode->itemListArray[i]=pNode->itemListArray[i-1];
            i--;
        }
        pNode->itemListArray[i]=itemlist;//叶子结点直接插入
        ++(pNode->itemListNum);
    }else{
        while(i>0&&key(itemlist.example())<key(pNode->itemListArray[i-1].example())) --i;
        Node *pChild=pNode->pChild[i];
        if(pChild->itemListNum==KEY_MAX){
            splitChild(pNode, i, pChild);
            if(key(itemlist.example()) > key(pNode->itemListArray[i].example()))
                pChild=pNode->pChild[i+1];
        }
        insertNoFull(pChild, itemlist);
    }
}
void BTree::splitChild(Node *pParent, int childIndex, Node *pChild)
{
    Node *pRightNode =new Node();
    pRightNode->isLeaf=pChild->isLeaf;
    pRightNode->itemListNum=KEY_MIN;
    int i;
    for(i=0; i<KEY_MIN; ++i){
        pRightNode->itemListArray[i]=pChild->itemListArray[i+KEY_MIN+1];//拷贝数据域
    }
    if(!pChild->isLeaf){
        for(i=0; i<CHILD_MIN; ++i){
            pRightNode->pChild[i]=pChild->pChild[i+CHILD_MIN];//非叶子结点要拷贝指针
        }
    }
    pChild->itemListNum=KEY_MIN;
    for(i=pParent->itemListNum; i>childIndex; --i){
        pParent->pChild[i+1]=pParent->pChild[i];
        pParent->itemListArray[i]=pParent->itemListArray[i-1];
    }
    ++(pParent->itemListNum);
    pParent->pChild[childIndex+1]=pRightNode;
    pParent->itemListArray[childIndex]=pChild->itemListArray[KEY_MIN];
}
void BTree::r_dump(Node *pNode) const
{
    if(pNode!=nullptr){
        int i, j;
        for(i=0; i<pNode->itemListNum; ++i){
            if(!pNode->isLeaf){
                r_dump(pNode->pChild[i]);
                std::cout<<"\n";
            }
            ItemList itemlist=pNode->itemListArray[i];
            std::cout<<"dumplist"<<'\n';
            itemlist.dump();
        }
        if(!pNode->isLeaf){
            std::cout<<"\n";
            r_dump(pNode->pChild[i]);
        }
    }
}
ItemList *BTree::search(int keyword)
{
    Node *pNode=*pPosition;
    if(pNode==nullptr){
        return nullptr;
    }else{
        int i;
        for(i=0; i < pNode->itemListNum && keyword > key(pNode->itemListArray[i].example()); ++i);
        if(i < pNode->itemListNum && keyword==key(pNode->itemListArray[i].example())){
            pPosition=&pRoot;
            return &pNode->itemListArray[i];
        }else{
            if(pNode->isLeaf){
                pPosition=&pRoot;
                return nullptr;
            }else{
                pPosition=&(pNode->pChild[i]);
                return search(keyword);
            }
        }
    }
}
ItemList *BTree::search(String keyword)
{
    int _keyword=(unsigned int)keyword[0]*256+(unsigned int)keyword[1];
    return search(_keyword);
}
void BTree::mergeChild(Node *pParent, int index)
{
    Node *pChild1=pParent->pChild[index];
    Node *pChild2=pParent->pChild[index+1];
    pChild1->itemListNum=KEY_MAX;
    pChild1->itemListArray[KEY_MIN]=pParent->itemListArray[index];
    for(int i=0; i<KEY_MIN; ++i){
        pChild1->itemListArray[i+KEY_MIN+1]=pChild2->itemListArray[i];
    }
    if(!pChild1->isLeaf){
        for(int i=0; i<CHILD_MIN; ++i){
            pChild1->pChild[i + CHILD_MIN]=pChild2->pChild[i];
        }
    }
    --(pParent->itemListNum);
    for(int i=index; i<pParent->itemListNum; i++){
        pParent->itemListArray[i]=pParent->itemListArray[i+1];
        pParent->pChild[i+1]=pParent->pChild[i+2];
    }
    deleteNode(pChild2);
}
void BTree::deleteNode(Node *pNode)
{
    if(pNode!=nullptr){
        delete pNode;
        pNode=nullptr;
    }
}
ItemList BTree::getPredecessor(Node *pNode)
{
    while(!pNode->isLeaf){
        pNode=pNode->pChild[pNode->itemListNum];
    }
    return pNode->itemListArray[pNode->itemListNum-1];
}
ItemList BTree::getSuccessor(Node *pNode)
{
    while(!pNode->isLeaf){
        pNode=pNode->pChild[0];
    }
    return pNode->itemListArray[0];
}
void BTree::r_remove(Node *pNode, Item &item)//根据样例item来删除有对应键值的itemlist
{
    int i=0;
    while(i<pNode->itemListNum && key(item)>key(pNode->itemListArray[i].example())) ++i;
    if(i<pNode->itemListNum && key(item)==key(pNode->itemListArray[i].example())){ //在节点找到关键字
        if(pNode->isLeaf){//叶节点
            --(pNode->itemListNum);
            for(; i<pNode->itemListNum; ++i){
                pNode->itemListArray[i]=pNode->itemListArray[i+1];
            }
            return;
        }else{//内结点
            Node *pChildPre=pNode->pChild[i];//到前子节点找前驱
            Node *pChildSuc=pNode->pChild[i+1];//到后子节点找后继
            if(pChildPre->itemListNum>=KEY_MIN+1){
                ItemList pre_itemlist=getPredecessor(pChildPre);
                r_remove(pChildPre, pre_itemlist.example());
                pNode->itemListArray[i]=pre_itemlist;
                return;
            }else if(pChildSuc->itemListNum>=KEY_MIN+1){//左结点关键字数小于KEY_MIN+1,且右节点不小于
                ItemList suc_itemlist=getSuccessor(pChildSuc);
                r_remove(pChildSuc, suc_itemlist.example());
                pNode->itemListArray[i]=suc_itemlist;
                return;
            }else{//左右结点关键字数都为KEY_MIN,则合并
                mergeChild(pNode, i);
                r_remove(pNode->pChild[i], item);
            }
        }
    }else{ //在节点中未找到关键字
        Node *pChildNode=pNode->pChild[i];
        if(pChildNode->itemListNum==KEY_MIN){//只有KEY_MIN个关键字
            Node* pLeft=(i==0)?nullptr:pNode->pChild[i-1];
            Node *pRight=(i==pNode->itemListNum)?nullptr:pNode->pChild[i+1];
            int j;
            if(pLeft && pLeft->itemListNum>=KEY_MIN+1){//左边能借
                for(j=pChildNode->itemListNum; j>0; --j){
                    pChildNode->itemListArray[j]=pChildNode->itemListArray[j-1];
                }
                pChildNode->itemListArray[0]=pNode->itemListArray[i-1];
                if(!pLeft->isLeaf){
                    for(j=pChildNode->itemListNum+1; j>0; --j){
                        pChildNode->pChild[j]=pChildNode->pChild[j-1];
                    }
                    pChildNode->pChild[0]=pLeft->pChild[pLeft->itemListNum];
                }
                ++(pChildNode->itemListNum);
                pNode->itemListArray[i-1]=pLeft->itemListArray[pLeft->itemListNum-1];
                --(pLeft->itemListNum);
            }else if(pRight && pRight->itemListNum>=KEY_MIN+1){//右边能借
                pChildNode->itemListArray[pChildNode->itemListNum]=pNode->itemListArray[i];
                ++(pChildNode->itemListNum);
                pNode->itemListArray[i]=pRight->itemListArray[0];
                --(pRight->itemListNum);
                for(j=0; j<pRight->itemListNum; ++j){
                    pRight->itemListArray[j]=pRight->itemListArray[j+1];
                }
                if(!pRight->isLeaf){
                    pChildNode->pChild[pChildNode->itemListNum]=pRight->pChild[0];
                    for(j=0; j<pRight->itemListNum+1; ++j){
                        pRight->pChild[j]=pRight->pChild[j+1];
                    }
                }
            }else if(pLeft){
                mergeChild(pNode, i-1);
                pChildNode=pLeft;
            }else if(pRight){
                mergeChild(pNode, i);
            }
        }
        r_remove(pChildNode, item);
    }
}
bool BTree::remove(Item &item)
{
    ItemList *foundItemList;
    if(foundItemList=search(key(item))){
        if(foundItemList->removeItem(item.beginTime())){
            if(foundItemList->len()<1){
                r_remove(pRoot, item);//当链表为空再从BTree中删除该键值的链表
            }
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}