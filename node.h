#ifndef _NODE_H_
#define _NODE_H_
// 哈夫曼树的节点
class Node {
private :
    //  若是叶子节点，保存节点保存的数据；否则保存0
    int data ;
    // 节点的权重
    int weight;
    // 节点的左右子节点
    Node *left ,*right;
public :
    Node() :data(0) ,weight(0) ,left(0) ,right(0){}
    Node(int d) // 构造对应一个字符的节点
        : data(d) , weight(1), left(0) ,right(0) {}
    // 复制构造函数，偷了点懒
    Node(const Node &n) : Node(0) { *this = n; }
    // 用两个节点构造一个节点，需要两个节点都是new出来的，并且交给当前节点来管理
    Node(Node* l ,Node* r);
    Node& operator= (const Node& n) ;
    ~Node() { delete left; delete right; }
    // 判断是否为叶子节点
    bool isLeaf() const { return left ==0; }
    // 比较权重的大小
    friend bool operator< (const Node&l ,const Node&r ) { return l.weight < r.weight; }
    // 相等则是数据相等
    friend bool operator==(const Node&l ,const Node&r ) { return l.data == r.data; }
    // 增加权重
    Node& operator++();
    // 读取节点数据
    int getData() const { return data; }
    // 左边节点
    const Node& getLeft() const { return *left; }
    const Node& getRight() const { return *right; }
};
#endif
