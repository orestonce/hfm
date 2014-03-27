#include "node.h"
#include "haffuman.h"
#include <vector>
#include <algorithm>

Haffuman::Haffuman(std::istream& infile) {
    // read every char
    std::vector<Node> nodes;
    for (int i=infile.get() ; infile ; i=infile.get() ) {
        auto it = std::find(nodes.begin() ,nodes.end() , Node(i));
        if (it == nodes.end()) {
            nodes.push_back(Node(i));
        } else {
            ++ (*it);
        }
    }

    // build tree
    while (nodes.size() != 1) {
        auto mit1 = std::min_element(nodes.begin() ,nodes.end());
        Node* m1 = new Node(*mit1);
        nodes.erase(mit1);

        auto mit2 = std::min_element(nodes.begin() ,nodes.end());
        Node*m2 = new Node(*mit2);
        nodes.erase(mit2);

        nodes.push_back(Node(m1 , m2));
    }
    getCoding(nodes[0] ,"1");
}

void Haffuman::getCoding(const Node& node ,const std::string& curCode) {
    if (node.isLeaf()) {
        dict.insert(std::make_pair(node.getData() , curCode));
    } else {
        getCoding(node.getLeft() , curCode+"0");
        getCoding(node.getRight(), curCode+"1");
    }
}

bool Haffuman::encoding(std::istream& infile , std::ostream&  outfile ) {
    for ( int i=infile.get(); infile ; i=infile.get()){
        auto it = dict.find(i);
        if (it == dict.end()) {
            return false;
        }
        outfile << it->second;
    }
    return true;
}

bool Haffuman::decoding(std::istream& infile, std::ostream &outfile) {
    char ch ;
    std::string str;
    int i ;

    for (infile.get(ch); infile ; infile.get(ch) ) {
        if (ch != '0' && ch != '1') {
            return false;
        }
        str += ch;
        if (find(str ,i)) {
            outfile.put(i);
            str.clear();
        }
    }
    return true;
}

bool Haffuman::find(const std::string& str , int& save) const {
    for (const auto& p : dict) {
        if (p.second == str) {
            save = p.first;
            return true;
        }
    }
    return false;
}
