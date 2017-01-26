#include <string>

typedef std::string TreeType;

struct Node {
    TreeType value;
    int count;
    Node* left;
    Node* right;
    Node* parent;
};

class Tree {
public:
    Tree();

    ~Tree();

    bool insertNode(TreeType);

    void deleteNode(Node*);

    Node* findNode(TreeType);

    Node* findSmallestNode(Node*);

    int getHeight();

    int getNodeCount();

    void printTree(std::ofstream&, Node*);

    void printTreeInOrder(std::ofstream&, Node*, int);

    void deleteTree(Node*);

private:
    Node *root;
    int nodeCount;
    int treeHeight;

};