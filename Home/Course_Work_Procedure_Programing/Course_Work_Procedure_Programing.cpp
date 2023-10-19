#include <iostream>
#include <fstream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::fstream;

struct Book
{
    size_t pages = 1;
    char* name = nullptr;
    char* autor = nullptr;
    char* publisher= nullptr;
    char* genre = nullptr;
};

struct Magazine
{
    char* published = nullptr;
    char* name = nullptr;
    char* kind = nullptr;
};

struct Newspaper
{
    char* name = nullptr;
    char* published = nullptr;
};

void strCopy(char*& dest, const char* other)
{
    char* ptr = new char[strlen(other) + 1];
    strcpy_s(ptr, strlen(other) + 1, other);
    if (dest != nullptr)
        delete[] dest;
    dest = ptr;
}

void fillBook(Book& book, const size_t& page, const char* name, const char* autor, const char* published, const char* genre)
{
    strCopy(book.name, name);
    strCopy(book.autor, autor);
    strCopy(book.publisher, published);
    strCopy(book.genre, genre);
    book.pages = page;
}

void fillMagazine(Magazine& magazine, const char* name, const char* published, const char* kind)
{
    strCopy(magazine.name, name);
    strCopy(magazine.published, published);
    strCopy(magazine.kind, kind);
}

void fillNewspaper(Newspaper& newspaper, const char* name, const char* published)
{
    strCopy(newspaper.name, name);
    strCopy(newspaper.published, published);
}

void printBook(const Book& book)
{
    cout << "book name      :: " << book.name << endl;
    cout << "book autor     :: " << book.autor << endl;
    cout << "book publisher :: " << book.publisher << endl;
    cout << "book page      :: " << book.pages << endl;
    cout << "book genre     :: " << book.genre << endl << endl;
}

void printMagazine(const Magazine& magazine)
{
    cout << "magazine name      :: " << magazine.name << endl;
    cout << "magazine kind      :: " << magazine.kind << endl;
    cout << "magazine publisher :: " << magazine.published << endl;
}

void printNewspaper(const Newspaper& newspaper)
{
    cout << "newspaper name      :: " << newspaper.name << endl;
    cout << "newspaper publisher :: " << newspaper.published << endl;
}

void printBooks(const Book* book, const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        printBook(book[i]);
    }
}

void printMagazines(const Magazine* magazine, const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        printMagazine(magazine[i]);
    }
}

void printNewspapers(const Newspaper* newspaper, const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        printNewspaper(newspaper[i]);
    }
}

int main()
{
    /*Book book;
    fillBook(book, 121, "denus", "petro", "max");
    printBook(book);
    cout << endl;
    strCopy(book.name, "hello word!!!");
    printBook(book);*/
    int size = 2;
    Book* books = new Book[size];
    fillBook(books[0], 121, "denus", "petro", "max", "horror");
    fillBook(books[1], 127, "denus_2", "petro_2", "max_2", "horror_2");
    printBooks(books, size);

     /*Запис структури у файл*/
    /*fstream file("data.txt", std::ios_base::out);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (size_t i = 0; i < 2; i++)
        {
            file.write((char*)&books[i], sizeof(Book));
        }
    }*/
    Book* res = new Book[2];
    fstream file("data.txt", std::ios_base::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            file.read((char*)&res[i], sizeof(Book));

        }
    }
}

