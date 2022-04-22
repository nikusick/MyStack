#ifndef STACK_LISTSTACK_H
#define STACK_LISTSTACK_H

#include "StackImplementation.h"

#include <list>

using ValueType = double;
using namespace std;

class ListStack : public IStackImplementation {
public:
    ListStack() = default;
    ListStack(ListStack& copyStack);
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
    list <ValueType> _list;
};


#endif //STACK_LISTSTACK_H
