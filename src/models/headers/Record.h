#ifndef SPACE_INVADERS_RECORD_H
#define SPACE_INVADERS_RECORD_H


#include <iostream>

using namespace std;

template<typename T>
class Record {
private:
    string name;
    T value;
private:
    void setName(const string& name_);
    void setValue(T value_);
public:
    Record() = delete;
    Record(string name_, T value_);
};

template<typename T>
Record<T>::Record(string name_, T value_)
{
    this->setName(name_);
    this->setValue(value_);
}

template<typename T>
void Record<T>::setName(const string& name_)
{
    this->name = name_;
}

template<typename T>
void Record<T>::setValue(T value_)
{
    this->value = value_;
}


#endif
