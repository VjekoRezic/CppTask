//
// Created by vjekor on 3/23/23.
//

#ifndef FIRSTTASK_LOAN_H
#define FIRSTTASK_LOAN_H

#include "I_Printable.h"

class Loan;

class Loan : public I_Printable{

private:
    std::string name;
    std::string loan_start;
    std::string loan_end;

public:
    Loan(std::string name="None", std::string loan_start="", std::string loan_end="");
    void print(std::ostream &os) const override;
    std::string get_name() const ;
    void set_start(std::string name,std::string start, std::string end);
    void reset();



};

#endif //FIRSTTASK_LOAN_H
