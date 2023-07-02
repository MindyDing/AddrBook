#include<iostream>
#include"addr_book.h"
using std::cin;
using std::cout;
using std::endl;

enum OPTYPE{
    INVALID,
    ADD,
    DELETE,
    SEARCH,
    EDIT,
    PRINT
};

void usage()
{
    cout << "which option do you want?" << endl;
    cout << "ADD : "    << ADD      << endl;
    cout << "DELETE : " << DELETE   << endl;
    cout << "SEARCH : " << SEARCH   << endl;
    cout << "EDIT : "   << EDIT     << endl;
    cout << "PRINT : "  << PRINT    << endl;
    cout << "input 0 to exit"       << endl;
}

int main()
{
    ADDR_BOOK::Addr_Book book;
    usage();
    int opcode;
    cin>>opcode;
    string name, phone_nu;
    while(opcode != INVALID){
        switch(opcode){
            case ADD:{
                cout<<"Please input name and phone number, end with 0 0"<<endl;
                string end_sig("0");
                cin >> name >> phone_nu;
                while(name != end_sig && phone_nu != end_sig)
                {
                    if(!book.add(name, phone_nu)){
                        cout<<"Add fail"<<endl;
                        break;
                    }
                    else{
                        cin >> name >> phone_nu;
                    }

                }
                break;
            }
            case DELETE:{
                cin >> name;
                if(!book.delet(name)){
                    cout << "Delete fail" << endl;
                }
                break;
            }
            case SEARCH:{
                cin >> name;
                if(!book.search(name, phone_nu)){
                    cout << "Cannot found" << endl;
                }
                else{
                    cout << "name: " << name << " phone number: " << phone_nu << endl;
                }
                break;
            }
            case EDIT:{
                cin >> name >> phone_nu;
                if(!book.edit(name, phone_nu)){
                    cout << "Cannot found" << endl;
                }
                else{
                    cout << "name: " << name << " phone number: " << phone_nu << endl;
                }
                break;
            }
            case PRINT:{
                book.print();
                break;
            }`
            default:
                cout << "Unknown operation" << endl;
                break;
        }
        cout << "Input operation code" << endl;
        usage();
        cin>>opcode;
    }
 
    return 0;
}
