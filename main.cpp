
#include "Book.h"

int main() {

    std::vector <Book>  vec;
    vec.push_back(Book::add_book());
    vec.push_back(Book::add_book());
    vec.push_back(Book::add_book());
    vec.at(1).loan_start();

    Book::print_books_by(vec, "Vjeko");


    return 0;
}
