#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm> 
#include <vector>

template <typename T, typename PComparator = std::less<T> > //template min-heap [min] = less<T>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_; //store the data 
  size_t n_; //size
  PComparator compare_; //pick priority

  void siftDown(size_t item); //shift down
  void siftUp(size_t item); //shift up

  size_t parent(size_t i) const {return (i - 1) / n_;} //parent 
  size_t child(size_t i, size_t k) const {return n_ * i + k;} //track index location of child

};

// Add implementation of member functions here


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : data_(), n_(m), compare_(c) {} //ctor 

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() = default;

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {return data_.empty();}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {return data_.size();}


template <typename T, typename PComparator>
 void Heap<T, PComparator>::push(const T& item){
  data_.push_back(item);
  siftUp(data_.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap empty");
  }

  std::swap(data_.front(), data_.back());
  data_.pop_back();
  if(!empty()) siftDown(0);
}

//leaf -> root
template <typename T, typename PComparator>
void Heap<T, PComparator>::siftUp(size_t item){
  while(item > 0){
    size_t p = parent(item);
    if(compare_(data_[item], data_[p])){
      std::swap(data_[item], data_[p]);
      item = p;
    }else{
      break;
    }
  }
}




//root -> parent -> leaf
template <typename T, typename PComparator> //follow this template 
void Heap<T, PComparator>::siftDown(size_t i){
  while(true){
    size_t highest = i;
    for(size_t k = 1; k <= n_; ++k){
      size_t c = child(i,k);
      if(c < data_.size() && compare_(data_[c], data_[highest])){ //check bounds (dont pass leaf) && compare child with value
        highest = c; 
      }
    }
    if(highest == i) break; //dup
    std::swap(data_[i], data_[highest]); //swap value i with the number higher to move it down the tree
    i = highest; //assign 
  }
}


#endif

