//
// Created by vjekor on 3/23/23.
//

#include "Loan.h"

Loan::Loan(std::string name, std::string loan_start, std::string loan_end)
:name{name}, loan_start{loan_start}, loan_end{loan_end}{

}
void Loan::print(std::ostream &os) const {
    os<<"Loan details:\n    Name : "<<this->name<<"\n    Loan start : "<< this->loan_start<<"\n    Expected loan end : "<<this->loan_end;
}

std::string Loan::get_name() const {
    return this->name;
}

//setters



void Loan::set_start(std::string name,std::string start, std::string end) {
    this->name = name;
    this->loan_start=start;
    this->loan_end=end;
}

void Loan::reset() {
    this->name="None";
    this->loan_start="";
    this->loan_end="";
}