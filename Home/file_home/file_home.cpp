#include <iostream>
#include <string>
#include <fstream> // read, write in file
using namespace std;

const int SIZE = 50;

struct Row
{
    char row[SIZE];
};

string readFile(string fname)
{
    string tmp = "", result = "";
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
        return "";
    }
    while (getline(file, tmp))
    {
        result += tmp;
        result += "\n";
    }
    return result;
}

void writeFile(string fname, string value)
{
    ofstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
        return;
    }
    file << value;
    file.close();
}

void exersise_3(Row* row, string fname, int size)
{
    ofstream file(fname, ios_base::app);
    if (!file.is_open())
    {
        cout << "Error" << endl;
        return;
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            file << row[i].row;
            file << '\n';
        }
    }
    file.close();
}

string exersise_1(string fname)
{
    string  slovo = "", text = "";
    int previosly = 0, now = 0, i = 0;
    char s;
    ifstream read_file(fname);
    while (read_file.get(s))
    {
        if (!(s == ' ' or s == '\n' or !((s >= 65 and s <= 90) or (s >= 97 and s <= 122))))
            slovo = slovo + s;
        if (s == ' ' or s == '\n' or !((s >= 65 and s <= 90) or (s >= 97 and s <= 122)))
        {
            now = i - previosly;
            if (now >= 8)
            {
                text += slovo + "\n";
                slovo = "";
            }
            previosly = i;
            slovo = "";

        }
       
        i++;
    }
    now = i - previosly;
    if (now >= 8)
    {
        text += slovo + "\n";
    }
    read_file.close();
    return text;
}

string exersise_2(string text_1)
{
    string text_2 = "";
    for (int i = 0; i < text_1.length() - 1; i++)
    {
        text_2 = text_2 + text_1[i];
    }
    return text_2;
}

int count_(string fname)
{
    int k = 0;
    string tmp = "";
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
        return -1;
    }
    while (getline(file, tmp))
    {
        k++;
    }
    file.close();
    return k;
}

Row* add_Row(int& size,string fname)
{
    string tmp = "";
    size = count_(fname);
    Row* ptr = new Row[size];
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            file.getline(ptr[i].row, 100);
        }
        
    }
    

    return ptr;
}

int main()
{
    
    // exersise 1
     /*string fname = "file_1.txt", fname_2 = "file_2.txt";
     writeFile(fname_2, exersise_1(fname));*/

    // exersise 2
    /*string fname = "file_2_1.txt", fname_2 = "file_2_2.txt";
    string result_ = readFile(fname), text_in_file_2 = exersise_2(result_);
    writeFile(fname_2, text_in_file_2);*/

    // exersise 3
    /*string fname = "file_3_1.txt", fname_2 = "file_3_2.txt";
    int size = 0;
    string tmp = "", result = "";
    Row* rows = add_Row(size, fname);
    exersise_3(rows, fname_2, size);*/

    /*Завдання 4. Дан текстовий файл.Додати в нього рядок
        із дванадцяти рисок(------------), помістивши його після
        останнього з рядків, у яких немає пробілу.Якщо таких
        рядків немає, то новий рядок має бути доданий після всіх
        рядків наявного файлу.Результат записати в інший файл.*/

    /*string fname = "file_4_1.txt", fname_2 = "file_4_2.txt";
    bool flag = 1, FLAG = 1;
    string text_flag_ = "";
    int index_elem = 0;
    int count_elem = 0;
    string tmp = "", result = "";
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    while (getline(file, tmp))
    {
        index_elem++;
        for (int i = 0; i < tmp.length(); i++)
        {
            if (tmp[i] == ' ')
            {
                flag = 0;
                break;
            }
        }
        if (flag != 0 and FLAG == 1)
        {
            count_elem = index_elem;
            FLAG = 0;
        }
        result += tmp;
        result += "\n";
        flag = 1;
    }
    if (FLAG == 1)
    {
        text_flag_ = exersise_2(result);
        text_flag_ += "\n------------";
    }
    else
    {
        int count_sleshEn = 0;
        for (int i = 0; i < result.length(); i++)
        {
            if (result[i] == '\n') count_sleshEn++;
            text_flag_ += result[i];
            if (count_sleshEn == count_elem and FLAG == 0) {
                text_flag_ += "------------\n";
                FLAG = 1;
            }
        }
    }
    writeFile(fname_2, text_flag_);*/
}

