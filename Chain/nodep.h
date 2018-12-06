#ifndef NODEP_H
#define NODEP_H

#include "base.h"


// 请注意该节点类无法保存const对象

class Nodep {
private:
    Base *pbase; //
    Nodep *pnext;
public:
    Nodep();
    Nodep(Base *b);
    ~Nodep();

    Nodep(const Nodep &p) = delete;
    Nodep &operator=(const Nodep &p) = delete;
    Nodep &operator=(Base *b);

    bool insert(Nodep *r);
    Nodep *remove_after();

    Base *pointer();
    const Base *pointer() const;
    Base &operator*();
    const Base &operator*() const;
    Nodep *next();
};

#endif
