#pragma once
// Уровень абстракции
// клиентский код подключает именно этот хедер
#include <iostream>
// тип значений в стеке
using ValueType = double;

// на основе какого контейнера работает стек
enum class StackContainer {
    Vector = 0,
    List,
    // можно дополнять другими контейнерами
};

// декларация интерфейса реализации
class IStackImplementation;

class Stack
{
public:
    Stack(StackContainer container = StackContainer::Vector);
    Stack(const ValueType* valueArray, const size_t arraySize,
          StackContainer container = StackContainer::Vector);
    explicit Stack(const Stack& copyStack);
    Stack& operator=(const Stack& copyStack);
    Stack(Stack&& moveStack) noexcept;
    Stack& operator=(Stack&& moveStack) noexcept;

    ~Stack();

    void push(const ValueType& value);
    void pop();
    const ValueType& top() const;
    bool isEmpty() const;
    size_t size() const;

    void set_pimpl();
    void set_pimpl(const Stack& copyStack);

    void destruct_copy(Stack& stack, Stack& copyStack);
private:
    IStackImplementation* _pimpl = nullptr;
    StackContainer _containerType;
};

