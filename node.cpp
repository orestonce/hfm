#include "node.h"

Node& Node::operator ++() {
    ++weight ;
    return *this;
}
Node::Node(Node* l ,Node* r) {
    weight = l->weight + r->weight;
    data =0;
    if (*l < *r) {
        left = l ;
        right= r;
    } else {
        left = r;
        right= l;
    }
}

Node& Node::operator= (const Node& n) {
    if (n.isLeaf()) {
        data = n.data ;
        weight = n.weight;
    } else {
        weight = n.left->weight + n.right->weight;
        data =0;
        left = new Node(*n.left);
        right= new Node(*n.right);
    }
    return *this;
}
