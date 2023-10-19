#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

const int SIZE = 50;
struct Book
{
	char name[SIZE];
	char autor[SIZE];
	char publisher[SIZE];
	char genre[SIZE];
};

void printBook(Book book, string text);
void printBooks(Book* library, int size);
void editBook(Book& book);
char* toLowerCase(char* line);
int findByAutor(Book* library, int size, char* autor, int start = 0);
int findByName(Book* library, int size, char* name, int start = 0);
void sortByName(Book* library, int left, int right);
void sortByAutor(Book* library, int left, int right);
void sortByPublisher(Book* library, int left, int right);
void addNewBook(Book*& library, Book newBook, int& size);
void deleteBook(Book*& library, char* name, int& size);

