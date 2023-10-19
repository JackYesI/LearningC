#include <iostream>
#include "library.h"

int main()
{
    int size = 10;
    Book* library = new Book[size]{
        {"Iron Flame","Rebecca Yarros","Entangled: Red Tower Books","Fantasy"},
        {"The Ever King","LJ Andrews","Victorious","Fantasy"},
        {"Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
        {"Harry Potter and the Chamber of Secrets","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
        {"Harry Potter and the Prisoner of Azkaban","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
        {"Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
        {"Harry Potter and the Half-Blood Prince","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
        {"Crown of Blood and Ruin","LJ Andrews","Victorious","Dark Fantasy Horror"},
        {"Battlefield Reclaimer","David North","High Peak Publishing","Fiction"},
        {"Swords of Empire","Robert Ryan","Trotting Fox Press","Fantasy"},
    };
    /*Book* library = new Book[size]{
        {"I","R","E","F"},
    };*/
    /*printBooks(library, size);*/
    /*editBook(library[0]);
    printBooks(library, size);*/
    
    /*index = findByAutor(library, size, autor);
    while (index != -1)
    {
        printBook(library[index], " hihihi ");
        index = findByAutor(library, size, autor, index + 1);
    }
    cout << "\n\n==================\n\n";
    sortByName(library, 0, size - 1);
    printBooks(library, size);
    cout << "\n\n==================\n\n";
    sortByAutor(library, 0, size - 1);
    printBooks(library, size);

    cout << "\n\n==================\n\n";
    sortByPublisher(library, 0, size - 1);
    printBooks(library, size);*/

    /*Book newB{ "1", "c", "e", "c" };*/
    //char* ptr = new char[11] {"Iron Flame"};
    //char* ptr_1 = new char[2] {"1"};
    ///*addNewBook(library, newB, size);*/
    //cout << "*******************************" << endl;
    //deleteBook(library, ptr, size);
    //printBooks(library, size);
    //cout << "*******************************" << endl;
    //deleteBook(library, ptr_1, size);
    //printBooks(library, size);

    int choose;
    cout << "1) SHow all books;\n2) Add book;\n3) delete by name;\n4) edit book" << endl;
    cout << "5) find by autor;\n6) find by name;\n7) sort by name;\n8) sort by autor;\n9) sort by published" << endl;
    cout << "10) show menu;\n11) exit;" << endl;
    bool switch_ = true;
    while (switch_)
    {
        cin >> choose;

        if (choose == 1)
        {
            printBooks(library, size);
        }
        else if (choose == 2)
        {
            Book newB;
            editBook(newB);
            addNewBook(library, newB, size);
        }
        else if (choose == 3)
        {
            char name[SIZE];
            cin.getline(name, SIZE);
            deleteBook(library, name, size);
        }
        else if (choose == 4)
        {
            int index_edit = size - 1;
            cout << "Enter book's index what you want to delete :: " << endl;
            cin >> index_edit;
            editBook(library[index_edit]);
        }
        else if (choose == 5)
        {
            char autor[SIZE];
            cout << "Enter autor :: "; cin.ignore();
            cin.getline(autor, SIZE);
            int index = -1;
            while (true)
            {
                index = findByAutor(library, size, autor, index + 1);
                if (index == -1)
                {
                    break;
                }
                printBook(library[index], " hihihi ");
            }
        }
        else if (choose == 6)
        {
            char name_[SIZE]; cin.ignore();
            cin.getline(name_, SIZE);
            int index_name = -1;
            while (true)
            {
                index_name = findByName(library, size, name_, index_name + 1);
                if (index_name == -1)
                {
                    break;
                }
                printBook(library[index_name], " hihihi ");
            }
        }
        else if (choose == 7)
        {
            sortByName(library, 0, size - 1);
            printBooks(library, size);
        }
        else if (choose == 8)
        {
            sortByAutor(library, 0, size - 1);
            printBooks(library, size);
        }
        else if (choose == 9)
        {
            sortByPublisher(library, 0, size - 1);
            printBooks(library, size);
        }
        else if (choose == 10)
        {
            cout << "1) SHow all books;\n2) Add book;\n3) delete by name;\n4) edit book" << endl;
            cout << "5) find by autor;\n6) find by name;\n7) sort by name;\n8) sort by autor;\n9) sort by published" << endl;
            cout << "10) show menu;\n11) exit;" << endl;
        }
        else if (choose == 11)
        {
            switch_ = false;
        }
    }
    
    


}


