#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
        : _containerType(container)
{
    setPimpl();
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize,
             StackContainer container): _containerType(container)
{
    setPimpl();
    for (size_t i = 0; i < arraySize; ++i) {
        _pimpl->push(valueArray[i]);
    }
}

Stack::Stack(const Stack& copyStack): _containerType(copyStack._containerType)
{
    setPimpl(copyStack);
}

Stack& Stack::operator=(const Stack& copyStack) {
    if (this != &copyStack) {
        Stack newStack(copyStack);
        *this = move(newStack);
    }
    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept {
    swap(_pimpl, moveStack._pimpl);
    swap(_containerType, moveStack._containerType);
    moveStack._pimpl = nullptr;
}

Stack& Stack::operator=(Stack&& moveStack) noexcept {
    if (this != &moveStack) {
        swap(_pimpl, moveStack._pimpl);
        swap(_containerType, moveStack._containerType);
        delete moveStack._pimpl;
        moveStack._pimpl = nullptr;
    }
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

void Stack::push(const ValueType& value)
{
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack::top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Stack::size() const
{
    return _pimpl->size();
}

void Stack::setPimpl() {
    switch (_containerType)
    {
        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new ListStack());
            break;
        }
        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new VectorStack());
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}
void Stack::setPimpl(const Stack& copyStack) {
    switch (_containerType) {
        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation *>(new ListStack(
                    *dynamic_cast<ListStack *>(copyStack._pimpl)));
            break;
        }
        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation *>(new VectorStack(
                    *dynamic_cast<VectorStack *>(copyStack._pimpl)));
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}