#define MAX 1000

class Stack
{
    public:
        Stack();
        void push(char);
        int pop();
        char tip();
        bool isfull();
        bool isEmpty();
    private:
        char arr[MAX];
        int top;
};

