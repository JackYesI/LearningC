#include "library.h"

void printBook(Book book, string text)
{
	cout << "\n\n\t====================== " << text << "=============" << endl;
	cout << "\t\t Name      :: " << book.name << endl;
	cout << "\t\t Author    :: " << book.autor << endl;
	cout << "\t\t publisher :: " << book.publisher << endl;
	cout << "\t\t genre     :: " << book.genre << endl;
}

void printBooks(Book* library, int size)
{
	for (int i = 0; i < size; i++)
	{
		printBook(library[i], "book ");
	}
}

void editBook(Book& book)
{
	cout << "\n\n\t====================== " << book.name << "=============" << endl;
	cout << "\tEnter Name      :: "; cin.ignore(); cin.getline(book.name, SIZE);
	cout << "\tEnter Author    :: "; cin.getline(book.autor, SIZE);
	cout << "\tEnter publisher :: "; cin.getline(book.publisher, SIZE);
	cout << "\tEnter genre     :: "; cin.getline(book.genre, SIZE);
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

int findByName(Book* library, int size, char* name, int start)
{
	for (size_t i = start; i < size; i++)
	{
		if (strcmp(toLowerCase(library[i].name), toLowerCase(name)) == 0) {
			return i;
		}
	}
	return -1;
}

void sortByName(Book* library, int left, int right)
{
	Book pivot = library[left];
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

void sortByAutor(Book* library, int left, int right)
{
	Book pivot = library[left];
	int tmp_l = left;
	int tmp_r = right;



	while (left < right)
	{

		while (strcmp(toLowerCase(library[right].autor), toLowerCase(pivot.autor)) > 0 && left < right) right--;
		if (left != right) {
			library[left] = library[right];
			left++;
		}
		while (strcmp(toLowerCase(library[left].autor), toLowerCase(pivot.autor)) < 0 && left < right) left++;
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
		sortByAutor(library, left, index - 1);
	}
	if (right > index) {
		sortByAutor(library, index + 1, right);
	}
}

void sortByPublisher(Book* library, int left, int right)
{
	Book pivot = library[left];
	int tmp_l = left;
	int tmp_r = right;



	while (left < right)
	{

		while (strcmp(toLowerCase(library[right].publisher), toLowerCase(pivot.publisher)) > 0 && left < right) right--;
		if (left != right) {
			library[left] = library[right];
			left++;
		}
		while (strcmp(toLowerCase(library[left].publisher), toLowerCase(pivot.publisher)) < 0 && left < right) left++;
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
		sortByPublisher(library, left, index - 1);
	}
	if (right > index) {
		sortByPublisher(library, index + 1, right);
	}
}

void addNewBook(Book*& library, Book newBook, int& size)
{
	Book* ptr = new Book[size + 1];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = library[i];
	}
	ptr[size] = newBook;
	size = size + 1;
	if (library != nullptr)
		delete[] library;
	library = ptr;
}

void deleteBook(Book*& library, char* name, int& size)
{
	int index = findByName(library, size, name);
	Book* ptr = new Book[size - 1];
	for (size_t i = 0; i < size - 1; i++)
	{
		if (i < index) {
			ptr[i] = library[i];
		}
		else if (i >= index)
		{
			ptr[i] = library[i + 1];
		}
	}
	size = size - 1;
	if (library != nullptr)
		delete[] library;
	library = ptr;
}


