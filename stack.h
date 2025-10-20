#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;

    bool empty() const {return std::vector<T>::empty(); }
    size_t size() const {return std::vector<T>::size(); }
    
    void push(const T& item) {std::vector<T>::push_back(item); }

    // throws std::underflow_error if empty
    void pop(){if(std::vector<T>::empty()) throw std::underflow_error("stack empty"); std::vector<T>::pop_back(); }  

    // throws std::underflow_error if empty
    const T& top() const{
        if(std::vector<T>::empty()) throw std::underflow_error("stack empty");
        return std::vector<T>::back();
    }
    // Add other members only if necessary
};


#endif