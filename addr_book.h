#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H
#include<vector>
#include<string>
#include<cstdint>
#include<iostream>
#define MAX_NUM 1000

using std::string;
using std::vector;

namespace ADDR_BOOK{
    struct Person{
        string name;
        string phone_nu;
        Person(string n, string p)
        {
            name        = n;
            phone_nu    = p;
        }
    };

    class Addr_Book{
        vector<Person> persons;

        public:
        Addr_Book() {};
        //Addr_Book(istream infile);
        ~Addr_Book() {};
        inline bool is_empty() { return (persons.size() == 0); }
        inline bool is_full() { return (persons.size() > MAX_NUM); }
        bool add(string name, string phone_nu);
        bool delet(string name);
        bool search(string name, string &phone_nu);
        bool edit(string name, string phone_nu);
        void print();
        
    };
}

#endif
