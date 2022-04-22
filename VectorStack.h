#ifndef STACK_VECTORSTACK_H
#define STACK_VECTORSTACK_H

#include "StackImplementation.h"

#include <vector>

using ValueType = double;
using namespace std;

class VectorStack : public IStackImplementation {
public:
    VectorStack() = default;
    VectorStack(VectorStack& copyStack);
    void push(const ValueType& value) override;
    // удаление с хвоста
    void pop() override;
    // посмотреть элемент в хвосте
    const ValueType& top() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер
    size_t size() const override;
private:
     vector <ValueType> _vector;
};


#endif //STACK_VECTORSTACK_H
