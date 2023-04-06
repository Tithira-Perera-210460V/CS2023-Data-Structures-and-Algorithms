#include <iostream>
#include <chrono>
#define max 100
using namespace std;
using namespace std::chrono;

class StackByArray{
    private:
        int top;
        int stack_arr[max];

    public:
        StackByArray();
        void push(int data);
        void pop();
        void display();
        bool isEmpty();
        bool isFull();
        int stackTop();
};

StackByArray::StackByArray(){
    top = -1;
}

void StackByArray::push(int data){
    if(isFull()){
        cout << "Stack overflow" << endl;
        return;
    }
        
    top += 1;
    stack_arr[top] = data;
}

void StackByArray::pop()
{
    bool empty = isEmpty();

    if(isEmpty()){
        cout << "Stack underflow" << endl;
        return;
    }
            
    top -= 1;
    cout << stack_arr[top + 1] << endl;
}

void StackByArray::display()
{
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }

    for(int i = top; i >= 0; --i)
        cout << stack_arr[i] << " ";

    cout << endl;
}

bool StackByArray::isEmpty()
{
    return (top == -1);
}

bool StackByArray::isFull()
{
    return (top == (max - 1));
}

int StackByArray::stackTop()
{
    if (isEmpty())
        return -1;
            
    return stack_arr[top];
}


int main(){
    StackByArray stackByArr;

    auto startArr = high_resolution_clock::now();

    stackByArr.push(8);
    stackByArr.push(10);
    stackByArr.push(5);
    stackByArr.push(11);
    stackByArr.push(15);
    stackByArr.push(23);
    stackByArr.push(6);
    stackByArr.push(18);
    stackByArr.push(7);
    stackByArr.push(20);

    stackByArr.display();

    for(int i = 1; i <= 5; ++i){
        stackByArr.pop();
    }

    stackByArr.display();

    stackByArr.push(4);
    stackByArr.push(30);
    stackByArr.push(3);
    stackByArr.push(1);

    stackByArr.display();

    auto stopArr = high_resolution_clock::now();

    auto durationArr = duration_cast<microseconds>(stopArr - startArr);
    cout << "Time taken : " << durationArr.count() << " microseconds." << endl;

    return 0;
}
