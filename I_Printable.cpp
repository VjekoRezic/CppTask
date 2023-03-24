//
// Created by vjekor on 3/23/23.
//

#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os,const I_Printable &obj){
    obj.print(os);
    return os;
}