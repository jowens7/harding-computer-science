// Jerred Shepherd
// 10-19-2016

#include <string>
typedef std::string Type;

struct Node {
    Type value;
    Node* nextNode;
    Node* lastNode;
};

class List {
public:
    List();
    ~List();
    bool Insert(Type);
    bool Delete(Type);
    bool Edit(Type, Type);
    void Print();
private:
    Node* Head;
};