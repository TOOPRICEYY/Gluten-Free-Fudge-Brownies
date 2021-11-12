#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */


#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL
#include <sstream>
#include <string>
#include <utility>


using std::endl; 
using std::cout;

template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  List() : first(nullptr), last(nullptr), siz(0){} // ctor
  List(const List &other) : first(nullptr), last(nullptr),siz(0)  { // copy ctor
    copy_all(other);
  }
  ~List() {  // dtor
    clear();
  }
List & operator=(const List &rhs) {
  if (this == &rhs) {return *this; }
  empty();
  copy_all(rhs);
  return *this;
}

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    if(first != nullptr) {
      return false;
    }
    return true;
  }
  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const {
    return siz;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    assert(!empty());
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back() {
    assert(!empty());
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    Node *p = new Node;
    p->datum = datum;
    p->next = first;
    p->prev = nullptr;
    if(!empty())first->prev = p;
    first = p;
    if(++siz==1){
      last = first;
    }
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node *p = new Node;
    p->datum = datum;
    p->prev = last;
    p->next =  nullptr;
    if(!empty()) last->next = p;
    last = p;
    if(++siz==1){
      first = last;
    }
  }
  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front() {
    assert(!empty());
    Node *rip = first;
    if(--siz!=0){
    first = first->next;
    first->prev = nullptr;
    }else{
      first = last = nullptr;
    }
    delete rip;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    assert(!empty());
    Node *rip = last;
    if(--siz!=0){
    last = last->prev;
    last->next = nullptr;
    }else{
      last = first = nullptr;
    }
    delete rip;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while(!empty()){
      pop_back();
    }
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    assert(empty());
    if(!other.empty()){
      for(Node * n = other.first; n; n=n->next){
        push_back(n->datum);
      }
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  int siz = 0;

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.


  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator() : node_ptr(nullptr) {}
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
    Iterator& operator++() {
      node_ptr = node_ptr->next;
      return *this;
    }
    T & operator*() const {
      return node_ptr->datum;
    }
    bool operator==(Iterator rhs) const {
      if(node_ptr == rhs.node_ptr) {return true;}
      return false;
    }

    bool operator!=(Iterator rhs) const {
      if(node_ptr != rhs.node_ptr) {return true;}
      return false;
    }


  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List;
    // construct an Iterator at a specific position
    Iterator(Node *p){
      node_ptr = p;
    }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return Iterator(last->next);
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i) {
    assert(end() != i);
    assert(!empty());
    Node * behind = i.node_ptr->prev;
    Node * front = i.node_ptr->next;
    if(front == nullptr && behind!=nullptr){
      behind->next = nullptr;
      last = behind;
    }else if(behind == nullptr && front!=nullptr) {
      front->prev = nullptr;
      first = front;
    }else if(behind != nullptr && front != nullptr) {
      behind->next = front;
      front->prev = behind;
    }else{
      first = last = nullptr;
    }
    --siz;
    delete i.node_ptr;
    
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum) {
  Node * n = new Node; // create node
  n->datum = datum; // insert datum
  if(i.node_ptr == first) {
    push_front(datum);
    delete n;
    return;
    }
  if(empty()) {
    first = n;
    n->prev = nullptr;
    n->next = nullptr;
  }
  n->next = i.node_ptr;
  n->prev = i.node_ptr->prev;
  i.node_ptr->prev = n;
  ++siz; // increment size
  }

/*  
  void print(){
    if(empty())return;
    for(Node * n = first; n; n=n->next){
      cout << n->datum << " ";

    }
    cout << endl;
  }
*/
  
};//List




////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
