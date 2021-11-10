#include <cassert> 
#include "List.h"

using namespace std;


  //EFFECTS:  returns true if the list is empty
  template <typename T>
  bool List<T>::empty() const{
      return first == nullptr;
  }
 

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.t
  template <typename T>
  int List<T>::size() const{
      return len;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  template <typename T>
  T & List<T>::front(){
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  template <typename T>
  T & List<T>::back(){
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  template <typename T>
  void List<T>::push_front(const T &datum){
    Node * add_me{first, nullptr, datum};
    first->prev = add_me;
    first = add_me;
    len++;
  }

  //EFFECTS:  inserts datum into the back of the list
  template <typename T>
  void List<T>::push_back(const T &datum){
    Node * add_me{nullptr, last, datum};
    last->next = add_me;
    last = add_me;
    len++;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  template <typename T>
  void List<T>::pop_front(){
      assert(!empty());
      Node * destroy_me = first;
      first = first->next;
      delete destroy_me;
      len--;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  template <typename T>
  void List<T>::pop_back(){
      assert(!empty());
      Node * destroy_me = last;
      last = last->prev;
      delete destroy_me;
      len--;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  template <typename T>
  void List<T>::clear(){
      while(!empty()){
          pop_front();
      }
}

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  template <typename T>
  void List<T>::copy_all(const List<T> &other){
    for(Node * n = other->first; n; n=n->next){
      push_back(n);
    }
  }

 
  ////////////////////////////////////////
  template <typename T>
  class List<T>::Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.



    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.


  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here

    // construct an Iterator at a specific position
    Iterator(Node *p);

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element

  // return an Iterator pointing to "past the end"
  template <typename T>
  List<T>::Iterator List<T>::end() const{

  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  template <typename T>
  void List<T>::erase(Iterator i){
    *(i.node_ptr->prev).next = i.node_ptr->next;
    *(i.node_ptr->next).prev = i.node_ptr->prev;
    delete i.node_ptr;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  template <typename T>
  void List<T>::insert(Iterator i, const T &datum){
   

  }