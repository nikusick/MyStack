#include "ListStack.h"

void ListStack::push(const ValueType& value) {
    _list.push_back(value);
}

void ListStack::pop() {
    _list.pop_back();
}

const ValueType& ListStack::top() const {
    return _list.back();
}

bool ListStack::isEmpty() const {
    return _list.empty();
}

size_t ListStack::size() const {
    return _list.size();
}

ListStack::ListStack(ListStack& copyStack) {
    _list = copyStack._list;
}
