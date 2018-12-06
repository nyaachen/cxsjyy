#include "nodep.h"

Nodep::Nodep() : pbase(nullptr), pnext(nullptr) {}

Nodep::Nodep(Base *b) : pbase(b), pnext(nullptr) {}

Nodep::~Nodep() {}

Nodep &Nodep::operator=(Base *b) {
    pbase = b;
    return *this;
}

bool Nodep::insert(Nodep *r) {
    if (r->pnext != nullptr) {
        // 节点已经在一个链表中，插入失败
        return false;
    }
    r->pnext = pnext;
    pnext = r;
    return true;
}

Nodep *Nodep::remove_after() {
    if (pnext == nullptr) {
        return nullptr;// 当前节点没有后继
    }
    else {
        Nodep *ret = pnext;
        pnext = pnext->pnext;
        return ret;
    }
}

Base *Nodep::pointer() {
    return pbase;
}

const Base *Nodep::pointer() const {
    return pbase;
}

Base &Nodep::operator*() {
    return *pbase;
}

const Base &Nodep::operator*() const {
    return *pbase;
}

Nodep *Nodep::next() {
    return pnext;
}
