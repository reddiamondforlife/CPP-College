#include <iostream>
#include"cstack.cpp"
#include "que.cpp"
using namespace std;


int main(){
cout<<"example with LIFO"<<endl;	
 CStack s; 
    try {
        if ( s.isEmpty() ) 
            {
            cout << "Stack is empty" << endl;    
            }
        // Push elements    
        s.Push('l');    
        s.Push('u'); 
		s.Push('o'); 
		 cout<<"in stack now, luo"<<endl;   
        // Size of stack
        cout << "Size of stack = " << s.Size() << endl;
        
        
    	cout<<"Now the first item of the list: ";
       cout << s.Pop() << endl;
        cout<<"p  added, Now the first item of the list: ";
        s.Push('p');
        cout << s.Top() << endl;
        cout<<"one removed, Now the first item of the list: ";
       cout << s.Pop() << endl;
        cout<<"one removed, Now the first item of the list: ";
       cout << s.Pop() << endl;
       cout<<"one removed, Now the first item of the list: ";
        cout << s.Pop() << endl;
        
       
    }
    catch (...) {
        cout << "Some exception occured" << endl;
    }

 
cout<<"example with FIFO"<<endl;
   CQueue q;
   try {
       if ( q.isEmpty() )
       {
           cout << "Queue is empty" << endl;
       }

       // Enqueue elements
       q.Enqueue('l');
       q.Enqueue('u');
       q.Enqueue('o');
      
       cout<<"in que now, luo"<<endl;

       // Size of queue
       cout << "Size of queue = " << q.Size() << endl;

       // Front element
      //cout << q.Front() << endl;

       // Dequeue elements
       cout<<"Now the first item of the list: ";
       cout << q.Dequeue() << endl;
        cout<<"p  added, Now the first item of the list: ";
        q.Enqueue('p');
        cout << q.Front() << endl;
        cout<<"one removed, Now the first item of the list: ";
       cout << q.Dequeue() << endl;
        cout<<"one removed, Now the first item of the list: ";
       cout << q.Dequeue() << endl;
       cout<<"one removed, Now the first item of the list: ";
        cout << q.Dequeue() << endl;
   }
   catch (...) {
       cout << "Some exception occured" << endl;
   }

 return 0;
}



