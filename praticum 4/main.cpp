#include <iostream>
using namespace std;
// de node, hierin zit data en verwijzigen naar de andere data.
template<class T>
class Node {
    T key;
    Node* left;
    Node* right;
public:
    Node() { key=-1; left=NULL; right=NULL; };
    void setKey(T aKey) { key = aKey; };
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    T Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
};
template<class T>
class prioQue{
	 
public:
	Node<T>* root;
	prioQue();
	~prioQue();
	Node<T>* Root() { return root; };
     void addNode(T key);
     void inOrder (Node<T>* n);
     void plus (Node<T>* n);
     void alsBeide (Node<T>* n, Node<T>* n2);
     void alsBeide2 (Node<T>* n, T key);
     prioQue<T> operator<<(prioQue param);
      prioQue<T> operator*(prioQue param);
     prioQue<T> operator+(prioQue param);
     void freeNode(Node<T>* leaf);
private:
	void addNode(T key, Node<T>* leaf);
	
};

template<class T>
prioQue<T>::prioQue(){
	root = NULL;
}
template<class T>
prioQue<T>::~prioQue(){
	freeNode(root);
}
// schoonmaak voor de destroyer.
template<class T>
void prioQue<T>::freeNode(Node<T>* leaf)
{
    if ( leaf != NULL )
    {
       freeNode(leaf->Left());
       freeNode(leaf->Right());
       delete leaf;
    }
}
// publieken toever, zorg ervoor dat de eerste element word aangemaakt en voorkomt overhead van de prive methode
template<class T>
void prioQue<T>::addNode(T key) {
     // No elements. Add the root
     if ( root == NULL ) {
        cout << "add root node ... " << key << endl;
        Node<T>* n = new Node<T>();
        n->setKey(key);
    root = n;
     }
     else {
    cout << "add other node ... " << key << endl;
    addNode(key, root);
     }
}
// node toevoegen, kijkt of hij hem links of recht moet toevoegen( licht eraan of die grooter of kleiner is)
// Add a node (private)
template<class T>
void prioQue<T>::addNode(T key, Node<T>* leaf) {
    if ( key <= leaf->Key() ) {
       if ( leaf->Left() != NULL )
      addNode(key, leaf->Left());
       else {
      Node<T>* n = new Node<T>();
      n->setKey(key);
      leaf->setLeft(n);
       }
    }
    else {
       if ( leaf->Right() != NULL )
      addNode(key, leaf->Right());
       else {
      Node<T>* n = new Node<T>();
      n->setKey(key);
      leaf->setRight(n);
       }
    }
}

// Hier gaat iets fout, ik weet niet wat maar zodra ik operators gebruikt flipt die de pan uit.
template<class T>
prioQue<T> prioQue<T>::operator<< (prioQue param) {
	Node<T>* n=param.Root();
    inOrder(n);
}
template<class T>
prioQue<T> prioQue<T>::operator+ (prioQue param) {
	Node<T>* n=param.Root();
    plus(n);
    
}
template<class T>
prioQue<T> prioQue<T>::operator* (prioQue param) {
	Node<T>* n=param.Root();
    alsBeide(n,this.Root());
    
}
//stuurt zichzelf de hele lijst telkens maar elke keer stuurt ie 1 key naar alsbeide2 die ook weer op zijn buurt door alles heen gaat tot die een match vind.
template<class T>
void  prioQue<T>::alsBeide (Node<T>* n,Node<T>* n2) {
if ( n ) {
      alsBeide(n->Left(),n2);
      alsBeide2(n2,n->Key());
      alsBeide(n->Right(),n2);
    }
}
template<class T>
void  prioQue<T>::alsBeide2 (Node<T>* n, T key) {
if ( n ) {
    alsBeide2(n->Left(), key);
      if(n->Key()==key)
      {
      	addNode(n->Key());
      }
      alsBeide2(n->Right(),key);
    }
}
//  plussen, simpel gezegt hij pakt zijn eigen lijst en voegt hem toe, meteen in een goede volgorde.
template<class T>
void  prioQue<T>::plus (Node<T>* n) {
    if ( n ) {
       plus(n->Left());
       addNode(n->Key());
       plus(n->Right());
    }
}
// alles word in volgorde toegevoegt, dus nu alleen nog de lijst printen
template<class T>
void  prioQue<T>::inOrder (Node<T>* n) {
    if ( n ) {
    inOrder(n->Left());
      cout << n->Key() << " | ";
      inOrder(n->Right());
    }
}


int main() {
prioQue<double>tree;
prioQue<double>tree2;
prioQue<double>tree3;

cout<<"eerste  prio bevat"<<endl;
   tree.addNode(100);
   tree.addNode(20);
	tree.addNode(40);
   tree.addNode(50);
   cout<<"tweede prio bevat"<<endl;
   tree2.addNode(50);
   tree2.addNode(20);
   cout<<"eerste en tweede prio met een steretje"<<endl;
   tree3.alsBeide(tree.Root(),tree2.root);
   tree3.inOrder(tree3.Root());
   cout<<"eerste en tweede prio met een plusje"<<endl;
   tree.plus(tree2.Root());
   tree.inOrder(tree.Root());
    
   return 0;
}
