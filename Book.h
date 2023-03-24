//
// Created by vjekor on 3/23/23.
//
//id has to be unique , genre must be in genre base , isbn must be valid ( 13 digits)

#ifndef FIRSTTASK_BOOK_H
#define FIRSTTASK_BOOK_H

#include <vector>
#include "I_Printable.h"
#include "Loan.h"

class Book;



class Book : public I_Printable{
    static bool check_id(int id);
    static bool check_genre(std::string genre);
    static bool check_isbn(long isbn);
    static std::vector<int> id_base;
    static const std::vector <std::string> genre_base;
private:
    int id;
    std::string title;
    std::vector<std::string> authors;
    long isbn ;
    std::string genre;
    Loan loanDetails;
    Book(int id , std::string title, std::vector<std::string> authors, long isbn , std::string genre);



public:

    static Book add_book();
    static void print_books_by(std::vector<Book> &vec, std::string author);
    Book(Book &obj)=delete;
    Book(Book &&obj) noexcept ;

    //print interface implementation
    void print(std::ostream &os) const override;

    void loan_start();
    void loan_end();

    bool operator==(const Book &obj);

};





#endif //FIRSTTASK_BOOK_H
