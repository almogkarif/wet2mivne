#ifndef HW2_RANK_NODE_H
#define HW2_RANK_NODE_H

template<class T, class RankFunc>
class Node {
public:
    T* data;
    Node<T, RankFunc>* right;
    Node<T, RankFunc>* left;
    Node<T, RankFunc>* parent;
    RankFunc calcNodeSize;
    int height;
    int rank;

    Node(): data(nullptr), right(nullptr), left(nullptr), parent(nullptr), height(0), rank(0) {}

    Node(const T& n_data) : data(nullptr), right(nullptr), left(nullptr), parent(nullptr) , height(0){
        data = new T(n_data);
        rank = calcNodeSize(*data);
    }

    virtual ~Node() {
        delete left;
        delete right;
        delete data;
    }

    int getBalance() const
    {
        int l_h =-1;
        int r_h =-1;
        if(left != nullptr)
            l_h=left->height;
        if(right!= nullptr)
            r_h = right->height;
        return l_h-r_h;
    }

    int calcHeight()
    {
        int l_h = -1;
        int r_h =-1;
        if(left != nullptr)
            l_h = left->height;
        if(right!= nullptr)
            r_h = right->height;
        int n_height = (l_h<r_h ? r_h+1:l_h+1);
        height = n_height;
        return height;
    }

    int calcRank()
    {
        int l_rank = 0;
        int r_rank = 0;
        
        if(left != nullptr)
            l_rank = left->rank;

        if(right != nullptr)
            r_rank = right->rank;

        rank = l_rank + r_rank + calcNodeSize(*data);
        return rank;
    }


    bool isALeaf() const
    {
        return (left == nullptr && right == nullptr);
    }
};

template<class T ,class RankFunc>
void deleteOnlyThisNodePtr(Node<T, RankFunc>* node)
{
    if(node == nullptr)
        return;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    delete node;
}

template<class T, class RankFunc>
void deleteNodePtr(Node<T, RankFunc>* node)
{
    if(node == nullptr)
        return;
    delete node;
}

template<class T, class RankFunc>
Node<T, RankFunc>* newNode(T& n_data)
{
    Node<T, RankFunc>* node = new Node<T, RankFunc>(n_data);
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;

    return  node;
}

template<class T, class RankFunc>
bool NodeIsALeaf(Node<T, RankFunc>* node)
{
    if(node == nullptr)
        return false;
    return node->isALeaf();
}

template<class T, class RankFunc>
int calcNodeHeight(Node<T, RankFunc>* node)
{
    if(node == nullptr)
        return -1;
    return node->calcHeight();
}

template<class T, class RankFunc>
int calcNodeRank(Node<T, RankFunc>* node)
{
    if(node == nullptr)
        return 0;
    return node->calcRank();
}

template<class T, class RankFunc>
int getElementsSize(Node<T, RankFunc>* node)
{
    if(node == nullptr)
        return 0;
    
    return node->calcNodeSize(*(node->data))
}



template<class T, class RankFunc>
int getNodesBalance(const Node<T, RankFunc>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return  node->getBalance();
}


#endif //HW2_RANK_NODE_H
