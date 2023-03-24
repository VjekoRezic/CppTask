//
// Created by vjekor on 3/23/23.
//

#ifndef FIRSTTASK_I_PRINTABLE_H
#define FIRSTTASK_I_PRINTABLE_H

#include <ostream>

class I_Printable{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;

};

#endif //FIRSTTASK_I_PRINTABLE_H
