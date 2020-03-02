//
// Created by ahmad on 30/12/2018.
//

#ifndef PROJECT_FILL_HOLE_SHAREDPTR_H
#define PROJECT_FILL_HOLE_SHAREDPTR_H

#include <iostream>

template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(T *ptr);

    ~SharedPtr();

    T *operator->() const;

    T &operator*() const;

    operator bool() const;

    template<typename U>
    SharedPtr<T> &operator=(U *t);

    SharedPtr<T> &operator=(T *t);

    T *get() const;

    SharedPtr(SharedPtr const &);

    SharedPtr &operator=(SharedPtr const &);

private:
    T *m_ptr;
    size_t *m_counter;

};


template<typename T>
SharedPtr<T>::SharedPtr(T *ptr): m_ptr(ptr) {
    m_counter = new size_t;
    *m_counter = 1;
}
template<typename T>
template<typename U>
SharedPtr<T> &SharedPtr<T>::operator=(U *ptr) {
    if (m_ptr != ptr) {
        this->check_and_delete();
        m_counter = new size_t(1);
        m_ptr = ptr;
    }
    return *this;

}
template<typename T>
SharedPtr<T>::~SharedPtr() {
    --(*m_counter);

    if (!*m_counter) {
        delete m_ptr;
        delete m_counter;
    }

}

template<typename T>
T *SharedPtr<T>::operator->() const {
    return m_ptr;
}

template<typename T>
T &SharedPtr<T>::operator*() const {
    return *m_ptr;
}

template<typename T>
SharedPtr<T>::operator bool() const {
    return bool(m_ptr);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(T *ptr) {
    if (m_ptr != ptr) {
        --(*m_counter);
        if (!*m_counter) {
            delete m_ptr;
            delete m_counter;
        }
        m_counter = new size_t;
        *m_counter = 1;
        m_ptr = ptr;
    }
    return *this;

}

template<typename T>
T *SharedPtr<T>::get() const {
    return m_ptr;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr const &other) {
    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    ++(*m_counter);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr const &other) {
    --(*m_counter);

    if (!*m_counter) {
        delete m_ptr;
        delete m_counter;
    }

    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    ++(*m_counter);

    return *this;

}

#endif //PROJECT_FILL_HOLE_SHAREDPTR_H
