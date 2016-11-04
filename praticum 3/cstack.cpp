#include <iostream>
using namespace std;

class StackUnderFlowException 
{
    public:
        StackUnderFlowException() 
        {
            cout << "Stack underflow" << endl;
        }
};

struct Node 
{
    char data;
    Node* link;
};

class CStack 
{
    private:                 
        Node* top;
        int count;
            
  public:        
      CStack() 
      {            
          top = NULL;
          count = 0;        
    }        
    
    void Push(char element)
    { 
        Node* temp = new Node();
        temp->data = element;
        temp->link = top;
        top = temp;     
        count++;          
    }        
            
    char Pop()
    {            
        if ( top == NULL ) 
            {            
                throw new StackUnderFlowException();            
            }        
            char ret = top->data;    
            Node* temp = top->link;
            delete top;
            top = temp;
            count--;
            return ret;        
    }        
    
    char Top() 
    {            
        return top->data;        
    }
    
    int Size() 
    {
        return count;
    }
    
    bool isEmpty() 
    {
        return ( top == NULL ) ? true : false;
    }
};


