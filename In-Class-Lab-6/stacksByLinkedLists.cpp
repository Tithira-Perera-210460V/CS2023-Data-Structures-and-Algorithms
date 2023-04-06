#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


struct Node {
    int data;
    struct Node* next;
};

class StackByLinkedList {
    private:
        struct Node* top;

    public:
        StackByLinkedList();
        void push(int data);
        void pop();
        bool isEmpty();
        bool isFull();
        int stackTop();
        void display();
};

StackByLinkedList::StackByLinkedList(){
    top = nullptr;
}

void StackByLinkedList::push(int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void StackByLinkedList::pop()
{
    if (top == nullptr) {
        cout << "Stack Underflow" << endl;
        return;
    }

    int data = top->data;
    Node* tempNode = top;
    top = top->next;
    delete tempNode;
    cout << data << endl;
}

bool StackByLinkedList::isEmpty()
{
    return (top == nullptr);
}

bool StackByLinkedList::isFull() 
{
    // Since this is implemented using linked lists, it cannot be full unless memory is exhausted
    return false;
}

int StackByLinkedList::stackTop()
{
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return top->data;
}

void StackByLinkedList::display() 
{
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* topNode = top;

    while (topNode != nullptr) {
        cout << topNode->data << " ";
        topNode = topNode->next;
    }
    cout << endl;
}


int main(){
    StackByLinkedList stackByList;

    auto startList = high_resolution_clock::now();
    stackByList.push(8);
    stackByList.push(10);
    stackByList.push(5);
    stackByList.push(11);
    stackByList.push(15);
    stackByList.push(23);
    stackByList.push(6);
    stackByList.push(18);
    stackByList.push(7);
    stackByList.push(20);

    stackByList.display();

    for(int i = 1; i <= 5; ++i){
        stackByList.pop();
    }

    stackByList.display();

    stackByList.push(4);
    stackByList.push(30);
    stackByList.push(3);
    stackByList.push(1);

    stackByList.display();

    auto stopList = high_resolution_clock::now();

    auto durationList = duration_cast<microseconds>(stopList - startList);

    cout << "Time taken : " << durationList.count() << " microseconds." << endl;

    return 0;
}