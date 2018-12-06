#ifndef INTSET_H
#define INTSET_H

#include <initializer_list>
#include <iostream>

class IntSet;
class IntSet {
private:
    int *ptr;
    size_t cnt;
    size_t max;
    void alloc(size_t count = 0);
    bool partial_sort();
public:
    IntSet();
    IntSet(const std::initializer_list<int> &li);
    IntSet(const IntSet &s);
    ~IntSet();
    IntSet &operator=(const IntSet &s);
    IntSet &operator=(const std::initializer_list<int> &li);
    void clear();
    bool is_empty() const;
    size_t size() const;
    bool is_element(int e) const;
    bool is_subset(const IntSet &s) const;
    bool is_equal(const IntSet &s) const;
    bool insert(int e);
    bool remove(int e);
    void display() const;
    IntSet union2(const IntSet& s) const;
    IntSet intersection2(const IntSet &s) const;
    IntSet difference2(const IntSet &s) const;

    friend std::ostream &operator<<(std::ostream &os, const IntSet &s);
    friend bool operator<=(const IntSet &l, const IntSet &r);
    friend bool operator==(const IntSet &l, const IntSet &r);
    friend bool operator!=(const IntSet &l, const IntSet &r);
    friend IntSet operator|(const IntSet &l, const IntSet &r);
    friend IntSet operator&(const IntSet &l, const IntSet &r);
    friend IntSet operator+(const IntSet &l, int i);
    friend IntSet operator+(const IntSet &l, const IntSet &r);
    friend IntSet operator-(const IntSet &l, int i);
    friend IntSet operator-(const IntSet &l, const IntSet &r);

    IntSet &operator+=(int i);
    IntSet &operator+=(const IntSet &s);
    IntSet &operator-=(int i);
    IntSet &operator-=(const IntSet &s);

};

std::ostream &operator<<(std::ostream &os, const IntSet &s);
bool operator<=(const IntSet &l, const IntSet &r);
bool operator==(const IntSet &l, const IntSet &r);
bool operator!=(const IntSet &l, const IntSet &r);
IntSet operator|(const IntSet &l, const IntSet &r);
IntSet operator&(const IntSet &l, const IntSet &r);
IntSet operator+(const IntSet &l, int i);
IntSet operator+(const IntSet &l, const IntSet &r);
IntSet operator-(const IntSet &l, int i);
IntSet operator-(const IntSet &l, const IntSet &r);


#endif
