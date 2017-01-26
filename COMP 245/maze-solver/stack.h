struct Coordinate {
    int Row, Column;
};

typedef Coordinate Stacktype;

struct Node {
    Stacktype Element;
    Node *Next;
};

class Stack {
public:
    Stack();
    ~Stack();
    bool IsEmpty();
    bool Push(Stacktype);
    Stacktype Pop();

private:
    Node *Head;
};

