//
// Created by vjekor on 3/23/23.
//
#include "Book.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <ctime>
std::string curr_date();
const std::vector<std::string> Book::genre_base({"Album", "Biography", "Comic Book", "Lexicon", "Novel"});
std::vector<int> Book::id_base{};

Book::Book(int id, std::string title, std::vector<std::string> authors, long isbn, std::string genre)
:id{id}, title{title}, authors{authors}, isbn{isbn}, genre{genre}, loanDetails(){
    Book::id_base.push_back(id);

}

void Book::print(std::ostream &os) const {
    os<<"Book title : "<<this->title<<"\nAuthors :";
    for(auto author:authors){
        os<<author<<" ";
    }
    os<<"\nISBN : "<< this->isbn<<"\nGenre : "<<this->genre<<"\n";
    if(this->loanDetails.get_name()!="None")
        os<<this->loanDetails;
}

bool Book::check_genre(std::string genre) {
    if(std::find(Book::genre_base.begin(), Book::genre_base.end(), genre)!=Book::genre_base.end()){
        return true;
    }
    return false;
}

bool Book::check_id(int id) {
    if(std::find(Book::id_base.begin(), Book::id_base.end(), id)==Book::id_base.end()){
        return true;
    }
    return false;
}

bool Book::check_isbn(long isbn) {
    int num_digits = int (log10(isbn) + 1);
    if(num_digits==13){
        return true;
    }
    return false;
}

Book Book::add_book() {
    int id{};
    std::string title;
    std::string author;
    std::vector<std::string> authors;
    long isbn;
    std::string genre;

    do{
        std::cout<<"Enter the book id:";
        std::cin>>id;
        if(!check_id(id)){
            std::cout<<"\nBook with this id already exists"<<std::endl;
        }
    }while(!check_id(id));

    do{
        std::cin.ignore();
        std::cout<<"Enter the book title:";
        getline(std::cin, title);
        std::cout<<std::endl;
        if(title==""){
            std::cout<<"Book title can't be empty!"<<std::endl;
        }

    }while(title=="");


    do{
        std::cout<<"Enter book authors , if you are done just hit enter one more time"<<std::endl;
        getline(std::cin, author);
        std::cout<<std::endl;
        if(!author.empty())
            authors.push_back(author);
        if(authors.empty())
            std::cout<<"You need to provide at least one author!"<<std::endl;
    }while(!author.empty() || authors.empty());

    do{
        std::cout<<"Enter isbn number: ";
        std::cin>>isbn;
        if(!check_isbn(isbn)){
            std::cout<<"\nInvalid isbn number! (isbn number needs to have 13 digits)"<<std::endl;
        }
    }while(!check_isbn(isbn));
    std::cin.ignore();
    do{
        std::cout<<"Enter the book genre (Album, Biography, Comic Book, Lexicon or Novel)";

        getline(std::cin, genre);
        if(!check_genre(genre)){
            std::cout<<"\nGenre you entered doesn't exist! Enter one of the offered options (They are case sensitive)!"<<std::endl;
        }
    }while(!check_genre(genre));

    return Book(id, title, authors, isbn, genre);

}



void Book::loan_start() {
    if(this->loanDetails.get_name()!="None")
        std::cout<<"Book alredy loaned!"<<std::endl;
    else {
        std::cout << "Enter the name of the person who is loaning the book: ";
        int days{};
        std::string name;
        std::string loan_start(curr_date());
        std::string loan_end;
        getline(std::cin, name);

        std::cout<<"Enter expected retrieval date:";
        getline(std::cin, loan_end);

        this->loanDetails.set_start(name, loan_start, loan_end);



    }

}

void Book::loan_end() {
    this->loanDetails.reset();
}

std::string curr_date(){
    time_t raw_time;
    struct tm * time_info;
    char buffer[80];

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(buffer, sizeof(buffer), "%d.%m.%Y", time_info);
    std::string str(buffer);
    return str;
}

bool Book::operator==(const Book &obj) {
    if(this->title==obj.title && this->authors==obj.authors)
        return true;
    return false;
}

Book::Book(Book &&obj) noexcept
: id(std::move(obj.id)), title(std::move(obj.title)), authors(std::move(obj.authors)), isbn(std::move(obj.isbn)), genre(std::move(obj.genre)),
  loanDetails(std::move(obj.loanDetails)) {

}

void Book::print_books_by(std::vector<Book> &vec, std::string author) {
    std::cout<<"Author : "<<author<<std::endl;
    for(auto &book:vec){
        if(std::find(book.authors.begin(), book.authors.end(),author) != book.authors.end()){
            std::cout<<"**********************************"<<std::endl;
            std::cout<<book<<std::endl;
        }
    }
}





