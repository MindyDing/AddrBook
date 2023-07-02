#include"addr_book.h"
#include<iomanip>
namespace ADDR_BOOK{
    bool Addr_Book::add(string name, string phone_nu)
    {
        if(is_full()){
            return false;
        }
        Person temp(name, phone_nu);
        persons.push_back(temp);
        return true;
    }

    bool Addr_Book::search(string name, string &phone_nu)
    {
        for(auto iter = persons.begin(); iter < persons.end(); iter++){
            if(iter->name == name){
                phone_nu = iter->phone_nu;
                return true;
            }
        }
        return false;
    }

    bool Addr_Book::delet(string name)
    {
        for(auto iter = persons.begin(); iter < persons.end(); iter++){
            if(iter->name == name){
                persons.erase(iter);
                return true;
            }
        }
        return false;
    }

    bool Addr_Book::edit(string name, string phone_nu)
    {
        for(auto iter = persons.begin(); iter < persons.end(); iter++){
            if(iter->name == name){
                iter->phone_nu = phone_nu;
                return true;
            }
        }
        return false;
    }

    void Addr_Book::print()
    {
        using std::cout;
        using std::endl;
        cout<<"Addr Book:"<<endl;
        cout<<"total num:"<<persons.size()<<endl;
        for(int i = 0; i < persons.size(); i++){
            cout<< std::setw(3) << i <<" "<< std::setw(12) << persons[i].name << std::setw(18) << persons[i].phone_nu << endl;
        }
    }

}
