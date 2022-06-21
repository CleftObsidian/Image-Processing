#ifndef HUFFMAN
#define HUFFMAN

#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iostream>

class Node {
public:
    Node() : left(nullptr), right(nullptr), cnt(0), num(0) {}
    Node(int num, int cnt) : left(nullptr), right(nullptr), cnt(cnt), num(num) {}
    Node(Node* left, Node* right) : left(left), right(right), cnt(left->cnt + right->cnt), num(0) {}

    bool operator()(const Node* lhs, const Node* rhs) const;

    Node* left;
    Node* right;
    uint32_t cnt;
    int num;
};

class Huffman {
private:
    Node* binTree;
    std::string code;

    void _getCode(const std::vector<int> input);

public:
    Huffman() : binTree(nullptr), code("") {}
    ~Huffman();

    void Encoding(const std::vector<int> input);
    std::string GetCode() const;
    std::vector<int> Decoding() const;
};

#endif