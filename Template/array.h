#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template <typename T> class Array {
private:
    T *ptr;
    size_t len;
    size_t max;
public:
    Array();
    // 指定数组的大小，实现保证至少可以存放指定数量的元素
    explicit Array(size_t size);
    // 制作一个现有数组的拷贝
    Array(const T *p, size_t cnt);
    // Array(const std::initializer_list<T> &li);
    ~Array();
    // 复制构造函数控制指针的复制行为
    Array(const Array<T> &arr);
    Array<T> &operator=(const Array<T> &arr);
    // 下标运算符返回对指定元素的引用
    T &operator[](size_t index);
    // size运算返回当前动态数组的大小
};

template <typename T> Array<T>::Array() : ptr(nullptr), len(0), max(0) {}

template <typename T> Array<T>::Array(size_t size) : Array() {
    len = size;
    size = (size / 5 + 1) * 5;
    ptr = new T [size];
    max = size;
}

template <typename T> Array<T>::Array(const T *p, size_t cnt) : Array() {
    size_t size = (cnt / 5 + 1) * 5;
    ptr = new T [size];
    max = size;
    for(size_t i=0; i < cnt; ++i) {
        ptr[i] = p[i];
    }
    len = cnt;
}

template <typename T> Array<T>::~Array() {
    delete [] ptr;
}

template <typename T> Array<T>::Array(const Array<T> &arr) : ptr(nullptr), len(arr.len), max(arr.max) {
    ptr = new T [max];
    for(size_t i=0; i < len; ++i) {
        ptr[i] = arr.ptr[i];
    }
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &arr) {
    if (this != &arr) {
        max = arr.max;
        len = arr.len;
        delete [] ptr;
        ptr = new T [max];
        for(size_t i=0; i < len; ++i) {
            ptr[i] = arr.ptr[i];
        }
    }
    return *this;
}

template <typename T> T &Array<T>::operator[](size_t index) {
    if (!(index < len)) {
        throw "[ERROR]Index out of range";
    }
    return ptr[index];
}

#endif
