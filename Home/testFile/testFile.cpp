#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// fstream today
// and file-struct

const string sizeBook = "size.txt";
const string sizeMagazine = "size_magazine.txt";
const string sizeNewspaper = "size_newspaper.txt";
const string fname_books = "data.txt";
const string fname_magazines = "data_magazines.txt";
const string fname_nespapers = "data_newspapers.txt";

struct Book
{
    size_t pages = 1;
    char name[50]{};
    char autor[50]{};
    char publisher[50]{};
    char genre[50]{};
};

struct Magazine
{
    char published[50]{};
    char name[50]{};
    char kind[50]{};
    char date[50]{};
};

struct Newspaper
{
    char name[50]{};
    char published[50]{};
    char date[50]{};
};

void WriteBooks(Book*& book, const int& size, string fname)
{
    fstream file(fname, ios_base::out);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            file.write((char*)&book[i], sizeof(Book));
        }
        file.close();
    }
}

void WriteMagazines(Magazine*& magazine, const int& size, string fname)
{
    fstream file(fname, ios_base::out);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            file.write((char*)&magazine[i], sizeof(Magazine));
        }
        file.close();
    }
}

void WriteNewspaper(Newspaper*& newspaper, const int& size, string fname)
{
    fstream file(fname, ios_base::out);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            file.write((char*)&newspaper[i], sizeof(Newspaper));
        }
        file.close();
    }
}

Book* ReadBook(const int& size, string fname)
{
    Book* res = new Book[size];
    fstream file(fname, ios_base::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            file.read((char*)&res[i], sizeof(Book));
        }
        file.close();
        return res;
    }
}

Magazine* ReadMagazine(const int& size, string fname)
{
    Magazine* res = new Magazine[size];
    fstream file(fname, ios_base::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            file.read((char*)&res[i], sizeof(Magazine));
        }
        file.close();
        return res;
    }
}

Newspaper* ReadNewspaper(const int& size, string fname)
{
    Newspaper* res = new Newspaper[size];
    fstream file(fname, ios_base::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            file.read((char*)&res[i], sizeof(Newspaper));
        }
        file.close();
        return res;
    }
}

void WriteSize(string fname,const int & size)
{
    ofstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        file << size;
    }
    file.close();
}

int ReadSize(string fname)
{
    int size;
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
        return -1;
    }
    else
    {
        file >> size;
    }
    file.close();
    return size;
}

void printBook(const Book& book)
{
    cout << "book pages     :: " << book.pages << endl;
    cout << "book name      :: " << book.name << endl;
    cout << "book autor     :: " << book.autor << endl;
    cout << "book published :: " << book.publisher << endl;
    cout << "book genre     :: " << book.genre << endl << endl;
}

void printMagazine(const Magazine& magazine)
{
    cout << "magazine name      :: " << magazine.name << endl;
    cout << "magazine published :: " << magazine.published << endl;
    cout << "magazine kind      :: " << magazine.kind << endl;
    cout << "magazine date      :: " << magazine.date << endl << endl;
}

void printNewspaper(const Newspaper& newspaper)
{
    cout << "newspaper name      :: " << newspaper.name << endl;
    cout << "newspaper published :: " << newspaper.published << endl;
    cout << "newspaper date      :: " << newspaper.date << endl << endl;
}

void printBooks(const Book* book, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        printBook(book[i]);
    }
}

void printMagazines(const Magazine* magazine, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        printMagazine(magazine[i]);
    }
}

void printNewspapers(const Newspaper* newspaper, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        printNewspaper(newspaper[i]);
    }
}

void addBook(Book*& book, int & size)
{
    Book* ptr = new Book[size + 1];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = book[i];
    }
    cout << "Enter book name      :: "; cin.ignore(); cin.getline(ptr[size].name, 50);
    cout << "Enter book autor     :: "; cin.getline(ptr[size].autor, 50);
    cout << "Enter book publisher :: "; cin.getline(ptr[size].publisher, 50);
    cout << "Enter book genre     :: "; cin.getline(ptr[size].genre, 50);
    cout << "Enter book pages     :: "; cin >> ptr[size].pages;
    size++;
    if (book != nullptr)
        delete[] book;
    book = ptr;
}

void addMagazine(Magazine*& magazine, int& size)
{
    Magazine* ptr = new Magazine[size + 1];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = magazine[i];
    }
    cout << "Enter magazine name      :: "; cin.ignore(); cin.getline(ptr[size].name, 50);
    cout << "Enter magazine publisher :: "; cin.getline(ptr[size].published, 50);
    cout << "Enter magazine kind      :: "; cin.getline(ptr[size].kind, 50);
    cout << "Enter magazine date      :: "; cin.getline(ptr[size].date, 50);
    size++;
    if (magazine != nullptr)
        delete[] magazine;
    magazine = ptr;
}

void addNewspaper(Newspaper*& newspaper, int& size)
{
    int value;
    Newspaper* ptr = new Newspaper[size + 1];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = newspaper[i];
    }
    cout << "Enter newspaper name      :: "; cin.ignore(); cin.getline(ptr[size].name, 50);
    cout << "Enter newspaper publisher :: "; cin.getline(ptr[size].published, 50);
    cout << "Enter newspaper date      :: "; cin.getline(ptr[size].date, 50);
    size++;
    if (newspaper != nullptr)
        delete[] newspaper;
    newspaper = ptr;
}

Book* addAllBook(int& size)
{
    size = 0;
    Book* newbook = nullptr;
    while (true)
    {
        int choose;
        cout << "1) add;\t2)Exit;";
        cin >> choose;
        if (choose == 1)
            addBook(newbook, size);
        else
            break;
    }
    return newbook;
}

Magazine* addAllMagazine(int& size)
{
    size = 0;
    Magazine* newMagazine = nullptr;
    while (true)
    {
        int choose;
        cout << "1) add;\t2)Exit;";
        cin >> choose;
        if (choose == 1)
            addMagazine(newMagazine, size);
        else
            break;
    }
    return newMagazine;
}

Newspaper* addAllNewspaper(int& size)
{
    size = 0;
    Newspaper* newNewspaper = nullptr;
    while (true)
    {
        int choose;
        cout << "1) add;\t2)Exit;";
        cin >> choose;
        if (choose == 1)
            addNewspaper(newNewspaper, size);
        else
            break;
    }
    return newNewspaper;
}

void deleteBook(Book*& book, int& size, string name)
{
    for (int i = 0; i < size; i++)
    {
        if (book[i].name == name)
        {
            Book* ptr = new Book[size - 1];
            for (int j = 0; j < size - 1; j++)
            {
                if (j < i) {
                    ptr[j] = book[j];
                }
                else if (j >= i)
                {
                    ptr[j] = book[j + 1];
                }
            }
            if (book != nullptr)
                delete[] book;
            book = ptr;
            size--;
            break;
        }
    }
}

void deleteMagazine(Magazine*& magazine, int& size, string name)
{
    for (int i = 0; i < size; i++)
    {
        if (magazine[i].name == name)
        {
            Magazine* ptr = new Magazine[size - 1];
            for (int j = 0; j < size - 1; j++)
            {
                if (j < i) {
                    ptr[j] = magazine[j];
                }
                else if (j >= i)
                {
                    ptr[j] = magazine[j + 1];
                }
            }
            if (magazine != nullptr)
                delete[] magazine;
            magazine = ptr;
            size--;
            break;
        }
    }
}

void deleteNewspaper(Newspaper*& newspaper, int& size, string name)
{
    for (int i = 0; i < size; i++)
    {
        if (newspaper[i].name == name)
        {
            Newspaper* ptr = new Newspaper[size - 1];
            for (int j = 0; j < size - 1; j++)
            {
                if (j < i) {
                    ptr[j] = newspaper[j];
                }
                else if (j >= i)
                {
                    ptr[j] = newspaper[j + 1];
                }
            }
            if (newspaper != nullptr)
                delete[] newspaper;
            newspaper = ptr;
            size--;
            break;
        }
    }
}

char* toLowerCase(char* line)
{
    char* new_line = new char[strlen(line) + 1];
    for (size_t i = 0; i < strlen(line); i++)
    {
        new_line[i] = tolower(line[i]);
    }
    new_line[strlen(line)] = '\0';
    return new_line;
}

template <typename T>
void sortByName(T* library, int left, int right)
{
    T pivot = library[left];
    int tmp_l = left;
    int tmp_r = right;



    while (left < right)
    {

        while (strcmp(toLowerCase(library[right].name), toLowerCase(pivot.name)) > 0 && left < right) right--;
        if (left != right) {
            library[left] = library[right];
            left++;
        }
        while (strcmp(toLowerCase(library[left].name), toLowerCase(pivot.name)) < 0 && left < right) left++;
        if (left != right) {
            library[right] = library[left];
            right--;
        }
    }
    int index = left;
    library[index] = pivot;
    left = tmp_l;
    right = tmp_r;
    if (left < index) {
        sortByName(library, left, index - 1);
    }
    if (right > index) {
        sortByName(library, index + 1, right);
    }
}

template <typename T>
int findByName(T* library, const int& size, char* name, int start)
{
    for (size_t i = start; i < size; i++)
    {
        if (strcmp(toLowerCase(library[i].name), toLowerCase(name)) == 0) {
            return i;
        }
    }
    return -1;
}

int findByAutor(Book* library, int size, char* autor, int start)
{
    for (size_t i = start; i < size; i++)
    {
        if (strcmp(toLowerCase(library[i].autor), toLowerCase(autor)) == 0) {
            return i;
        }
    }
    return -1;
}

int searchByGenre(Book* library, int size, char* genre, int start)
{
    for (size_t i = start; i < size; i++)
    {
        if (strcmp(toLowerCase(library[i].genre), toLowerCase(genre)) == 0) {
            return i;
        }
    }
    return -1;
}

int searchByNameYear(Magazine* magazine, int size, char* date, int start)
{
    for (size_t i = start; i < size; i++)
    {
        if (strcmp(toLowerCase(magazine[i].date), toLowerCase(date)) == 0) {
            return i;
        }
    }
    return -1;
}

int countGenre(Book* book, int& size, string name)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (book[i].genre == name) count++;
    }
    return count;
}

void deleteNewspaperByYear(Newspaper*& newspaper, int& size, char* year)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(toLowerCase(newspaper[i].date), toLowerCase(year)) == 0)
        {
            Newspaper* ptr = new Newspaper[size - 1];
            for (int j = 0; j < size - 1; j++)
            {
                if (j < i) {
                    ptr[j] = newspaper[j];
                }
                else if (j >= i)
                {
                    ptr[j] = newspaper[j + 1];
                }
            }
            if (newspaper != nullptr)
                delete[] newspaper;
            newspaper = ptr;
            size--;
            i--;
        }
    }
}

int main()
{
    int size = ReadSize(sizeBook);
    Book* books = nullptr; 
    books = ReadBook(size, fname_books);
    /*printBooks(books, size);*/

    int size_mag = ReadSize(sizeMagazine);
    Magazine* magazines = nullptr;
    magazines = ReadMagazine(size_mag, fname_magazines);
   /* printMagazines(magazines, size_mag);*/

    int size_new = ReadSize(sizeNewspaper);
    Newspaper* newspapers = nullptr;
    newspapers = ReadNewspaper(size_new, fname_nespapers);
    /*printNewspapers(newspapers, size_new);*/

    cout << "1) Fillin library;\n2) Show library;\n3) add;\n4) delete;\n5) sort;\n6) search;\n7) sample;\n8) correction;\n9) count;\n10) save changes;\n11) show\n12) Exit\n";
    int choose;
    while (true)
    {
        cin >> choose;
        if (choose == 1)
        {
            cout << "1) Fillin books\n2) Fillin Magazine;\n3) Fillin Newspaper;\n4) Exit\n";
            while (true)
            {
                cin >> choose;
                if (choose == 1)
                {
                    books = addAllBook(size);
                }
                else if (choose == 2)
                {
                    magazines = addAllMagazine(size_mag);
                }
                else if (choose == 3)
                {
                    newspapers = addAllNewspaper(size_new);
                }
                else 
                {
                    break;
                }
            }
        }
        else if (choose == 2)
        {
            printBooks(books, size);
            printMagazines(magazines, size_mag);
            printNewspapers(newspapers, size_new);
        }
        else if (choose == 3)
        {
            cout << "1) add book;\n2) add magazine;\n3) add nespaper;\n4) Exit;\n";
            while (true)
            {
                cin >> choose;
                if (choose == 1)
                {
                    addBook(books, size);
                }
                else if (choose == 2)
                {
                    addMagazine(magazines, size_mag);
                }
                else if (choose == 3)
                {
                    addNewspaper(newspapers, size_new);
                }
                else
                    break;
            }
        }
        else if (choose == 4)
        {
            cout << "1) delete book;\n2) delete magazine;\n3) delete nespaper;\n4) Exit;\n";
            while (true)
            {
                cin >> choose;
                if (choose == 1)
                {
                    string name;
                    cout << "Enter books name :: "; cin >> name;
                    deleteBook(books, size, name);
                }
                else if (choose == 2)
                {
                    string name;
                    cout << "Enter magazines name :: "; cin >> name;
                    deleteMagazine(magazines, size_mag, name);
                }
                else if (choose == 3)
                {
                    string name;
                    cout << "Enter newspapers name :: "; cin >> name;
                    deleteNewspaper(newspapers, size_new, name);
                }
                else
                    break;
            }
        }
        else if (choose == 5)
        {
            cout << "1) sort books;\n2) sort magazines;\n3) sort newspapers;\n4) Exit;\n";
            while (true)
            {
                cin >> choose;
                if (choose == 1)
                {
                    sortByName(books, 0, size - 1);
                }
                else if (choose == 2)
                {
                    sortByName(magazines, 0, size_mag - 1);
                }
                else if (choose == 3)
                {
                    sortByName(newspapers, 0, size_new - 1);
                }
                else
                    break;
            }
        }
        else if (choose == 6)
        {
            cout << "1) search by name book;\n2) search by autor book;\n3) search magazines;\n4) Exit;\n";
            while (true)
            {
                cin >> choose;
                if (choose == 1)
                {
                    char name[50];
                    cout << "Enter search name book :: "; cin.ignore();
                    cin.getline(name, 50);
                    printBook(books[findByName(books, size, name, 0)]);
                }
                else if (choose == 2)
                {
                    char name[50];
                    cout << "Enter search name book :: "; cin.ignore();
                    cin.getline(name, 50);
                    printBook(books[findByAutor(books, size, name, 0)]);
                }
                else if (choose == 3)
                {
                    char name[50];
                    cout << "Enter search name magazine :: "; cin.ignore();
                    cin.getline(name, 50);
                    printMagazine(magazines[findByName(magazines, size_mag, name,0)]);
                }
                else
                    break;
            }
        }
        else if (choose == 7)
        {
            cout << "1) search all books of autor;\n2) all books by genre;\n3) magazine from the year;\n4) Exit;\n";
            while (true)
            {
                cin >> choose;
                if (choose == 1)
                {
                    int index = -1;
                    char name[50];
                    cout << "Enter name of autor :: "; cin.ignore();
                    cin.getline(name, 50);
                    while (true)
                    {
                        index = findByAutor(books, size, name, index + 1);
                        if (index == -1) {
                            break;
                        }
                        else
                        {
                            printBook(books[index]);
                        }
                    }
                }
                else if (choose == 2)
                {
                    int index = -1;
                    char genre[50];
                    cout << "Enter genre of search :: "; cin.ignore();
                    cin.getline(genre, 50);
                    while (true)
                    {
                        index = searchByGenre(books, size, genre, index + 1);
                        if (index == -1) {
                            break;
                        }
                        else
                        {
                            printBook(books[index]);
                        }
                    }
                }
                else if (choose == 3)
                {
                    int index = -1;
                    char date[50];
                    cout << "Enter date of search :: "; cin.ignore();
                    cin.getline(date, 50);
                    while (true)
                    {
                        index = searchByNameYear(magazines, size_mag, date, index + 1);
                        if (index == -1) {
                            break;
                        }
                        else
                        {
                            printMagazine(magazines[index]);
                        }
                    }
                }
                else
                    break;
            }
        }
        else if (choose == 8)
        {
            char year[50];
            cout << "Enter year of delete newspapers :: "; cin.ignore();
            cin.getline(year, 50);
            deleteNewspaperByYear(newspapers, size_new, year);
        }
        else if (choose == 9)
        {
            char genre[50];
            cout << "Enter search genre :: "; cin.ignore();
            cin.getline(genre, 50);
            cout << "count of genre is " << countGenre(books, size, genre) << endl;
        }
        else if (choose == 10)
        {
            WriteBooks(books, size, fname_books);
            WriteSize(sizeBook, size);

            WriteMagazines(magazines, size_mag, fname_magazines);
            WriteSize(sizeMagazine, size_mag);

            WriteNewspaper(newspapers, size_new, fname_nespapers);
            WriteSize(sizeNewspaper, size_new);
        }
        else if (choose == 11)
        {
            cout << "1) Fillin library;\n2) Show library;\n3) add;\n4) delete;\n5) sort;\n6) search;\n7) sample;\n8) correction;\n9) count;\n10) save changes;\n11) show\n12) Exit\n";
        }
        else
            break;
    }
}


