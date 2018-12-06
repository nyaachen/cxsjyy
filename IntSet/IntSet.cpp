#include "IntSet.h"

#include <initializer_list>
#include <iostream>
#include <cstdio>


void IntSet::alloc(size_t count) {
    if (count < 2*max) {
        if (max == 0) count = 5;
        else count = 2*max;
    }
    int *p = new int[count];
    for (size_t i=0; i < cnt; ++i) {
        p[i] = ptr[i];
    }
    delete [] ptr;
    ptr = p;
    max = count;
}
bool IntSet::partial_sort() {
    if (cnt < 2) return true;
    for(size_t i=cnt-1; i != 0; --i) {
        int pos = i-1;
        if (ptr[i] < ptr[pos]) {
            int temp=ptr[pos];
            ptr[pos] = ptr[i];
            ptr[i] = temp;
        }
        else
            break;
    }
    return true;
}

IntSet::IntSet() : ptr(nullptr), cnt(0), max(0) {}
IntSet::IntSet(const std::initializer_list<int> &li) : IntSet() {
    alloc(li.size());
    for (auto iter = li.begin(); iter != li.end(); ++iter) {
        insert(*iter);
    }
}
IntSet::IntSet(const IntSet &s) : IntSet() {
    alloc(s.size());
    for (size_t i=0; i < s.size(); ++i) {
        insert(s.ptr[i]);
    }
}
IntSet::~IntSet() {
    clear();
}
IntSet &IntSet::operator=(const IntSet &s) {
    if (this != &s) {
        clear();
        alloc(s.size());
        for (size_t i=0; i < s.size(); ++i) {
            insert(s.ptr[i]);
            ++cnt;
        }
    }
    return *this;
}
IntSet &IntSet::operator=(const std::initializer_list<int> &li) {
    clear();
    alloc(li.size());
    for (auto iter = li.begin(); iter != li.end(); ++iter) {
        insert(*iter);
    }
    return *this;
}
void IntSet::clear() {
    delete [] ptr;
    ptr = nullptr;
    cnt=max=0;
}
bool IntSet::is_empty() const {
    return cnt==0;
}
size_t IntSet::size() const {
    return cnt;
}
bool IntSet::is_element(int e) const {
    for (size_t i=0; i < cnt; ++i) {
        if (ptr[i] == e) return true;
    }
    return false;
}
bool IntSet::is_subset(const IntSet &s) const {
    for (size_t i=0; i < cnt; ++i) {
        if (s.is_element(ptr[i]) != true) return false;
    }
    return true;
}
bool IntSet::is_equal(const IntSet &s) const {
    return this->is_subset(s) && s.is_subset(*this);
}
bool IntSet::insert(int e) {
    if (is_element(e)) return false;
    if (cnt == max) alloc();
    ptr[cnt++] = e;
    partial_sort();
    return true;
}
bool IntSet::remove(int e) {
    bool found = false;
    for (size_t i=0; i < cnt;) {
        if (found) {
            ptr[i] = ptr[i+1];
            ++i;
        }
        else {
            if (ptr[i] == e) {
                found = true;
                if (i != --cnt) {
                    ptr[i] = ptr[i+1];
                    ++i;
                }
            }
            else {
                ++i;
            }
        }
    }
    return found;
}
void IntSet::display() const {
    for (size_t i=0; i < cnt; ++i) {
        printf("%i ", ptr[i]);
    }
}
IntSet IntSet::union2(const IntSet& s) const {
    IntSet temp(*this);
    for (size_t i=0; i < s.size(); ++i) {
        temp.insert(s.ptr[i]);
    }
    return temp;
}
IntSet IntSet::intersection2(const IntSet &s) const {
    IntSet temp;
    for (size_t i=0; i < cnt; ++i) {
        if (s.is_element(ptr[i])) {
            temp.insert(ptr[i]);
        }
    }
    return temp;
}
IntSet IntSet::difference2(const IntSet &s) const {
    IntSet temp(*this);
    for (size_t i=0; i < s.size(); ++i) {
        temp.remove(s.ptr[i]);
    }
    return temp;
}
IntSet &IntSet::operator+=(int i) {
    insert(i);
    return *this;
}
IntSet &IntSet::operator+=(const IntSet &s) {
    for (size_t i=0; i < s.size(); ++i) {
        insert(s.ptr[i]);
    }
    return *this;
}
IntSet &IntSet::operator-=(int i) {
    remove(i);
    return *this;
}
IntSet &IntSet::operator-=(const IntSet &s) {
    for (size_t i=0; i < s.size(); ++i) {
        remove(s.ptr[i]);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const IntSet &s) {
    if (s.size() > 0) os << s.ptr[0];
    for (size_t i=1; i < s.size(); ++i) {
        os << " " << s.ptr[i];
    }
    return os;
}
bool operator<=(const IntSet &l, const IntSet &r) {
    return l.is_subset(r);
}
bool operator==(const IntSet &l, const IntSet &r) {
    return l.is_equal(r);
}
bool operator!=(const IntSet &l, const IntSet &r) {
    return !l.is_equal(r);
}
IntSet operator|(const IntSet &l, const IntSet &r) {
    return l.union2(r);
}
IntSet operator&(const IntSet &l, const IntSet &r) {
    return l.intersection2(r);
}
IntSet operator+(const IntSet &l, int i) {
    IntSet temp(l);
    temp.insert(i);
    return l;
}
IntSet operator+(const IntSet &l, const IntSet &r) {
    return l.union2(r);
}
IntSet operator-(const IntSet &l, int i) {
    IntSet temp(l);
    temp.remove(i);
    return l;
}
IntSet operator-(const IntSet &l, const IntSet &r) {
    return l.difference2(r);
}
