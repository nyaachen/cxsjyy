#include <iostream>

#include "base.h"

std::ostream &operator<<(std::ostream &os, const Base &b) {
    return b.print(os);
}
