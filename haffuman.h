#ifndef HAFFUMAN_H
#define HAFFUMAN_H

#include "node.h"
#include <iostream>
#include <map>

class Haffuman
{
public:
    Haffuman(std::istream& in) ;  // 从输入流中统计频率,用于构建哈夫曼树
    // 根据输入文件中的自负编码和自身的哈夫曼字典,对输入字符进行编码，若存在输入字符不在字典中,返回false
    // 输出为01字符
    bool encoding(std::istream& infile , std::ostream& outfile=std::cout);
    // 解压
    bool decoding(std::istream& infile=std::cin ,std::ostream& outfile=std::cout);
private :
    // 构造的字典
    std::map<int , std::string> dict;
    // 获取当前以下节点的编码，当前节点以上的编码为str
    void getCoding(const Node & , const std::string &str );
    // 查找编码为str的字符。若存在，则返回true，并把字符保存在save中
    bool find(const std::string& str , int& save) const ;
};

#endif // HAFFUMAN_H
