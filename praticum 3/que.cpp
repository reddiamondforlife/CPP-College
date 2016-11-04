#include <iostream>

using namespace std;
class QueueEmptyException
{
public:
   QueueEmptyException()
   {
       cout << "Queue empty" << endl;
   }
};
class Note
{
public:
   char data;
   Note* next;
};

class CQueue
{  
private:
   Note* front;
   Note* rear;
   int count;

public:
   CQueue()
   {
       front = NULL;
       rear = NULL;
       count = 0;
   }      
 
   void Enqueue(char element)
   {
       // Create a new Note
       Note* tmp = new Note();
       tmp->data = element;
       tmp->next = NULL;

       if ( isEmpty() ) {
           // Add the first element
           front = rear = tmp;
       }
       else {
           // Append to the list
           rear->next = tmp;
           rear = tmp;
       }

       count++;
   }      

   char Dequeue()
   {          
       if ( isEmpty() )
           throw new QueueEmptyException();

       char ret = front->data;
       Note* tmp = front;

       // Move the front pointer to next Note
       front = front->next;

       count--;
       delete tmp;
       return ret;   
   }      

   char Front()
   {          
       if ( isEmpty() )
           throw new QueueEmptyException();

       return front->data;
   }
 
   int Size()
   {
       return count;
   }

   bool isEmpty()
   {
       return count == 0 ? true : false;
   }
};
