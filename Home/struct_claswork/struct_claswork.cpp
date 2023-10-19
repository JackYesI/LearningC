#include <iostream>
using namespace std;

//Завдання 1. Реалізувати структуру «Пральна машинка»
//(фірма, колір, ширина, довжина, висота, потужність, швид -
//    кість віджиму, температура нагріву).Створіть екземпляр
//    структури і проілюструйте роботу з ним(і мейні створити
//        об * єкт, задати значення для всіх полів, вивести на екран.)

//Завдання 2. Реалізувати структуру «Праска»(фірма,
//    модель, колір, мінімальна температура, максимальна
//    температура, подача пари так / ні, потужність).Створіть
//    екземпляр структури і проілюструйте роботу з ним.

//Завдання 3. Реалізувати структуру «Бойлер»(фірма,
//    колір, потужність, обсяг, температура нагріву).Створіть
//    екземпляр структури і проілюструйте роботу з ним.

//Додаткове завдання на додаткові 12 балів
//Завдання 4
//Реалізувати структуру "Машина" (колір, модель, номер).Номер машини може бути
//або п'ятизначним номером, або словом до 8 символів.
//Рекомендації: номер реалізувати як об'єднання.
//Створити екземпляр структури "Машина" і реалізувати для нього такі функції :
//Заповнення машини;
//Друк машини.
//Створити масив із 10 екземплярів структури "Машина" і реалізувати для нього такі функції :
//Редагувати машину;
//Друк усіх машин;
//Пошук машини за номером.

struct Car_number
{
    char First_num[2];
    char Last_num[2];
    int number[4];
};

struct Car
{
    string color;
    string model;
    Car_number number;
};

void input_CarNumber(Car_number* number)
{
    cout << "Enter First num ";
    cin >> number->First_num[0];
    cin >> number->First_num[1];
    cout << "Enter number";
    for (int i = 0; i < 4; i++)
        cin >> number->number[i];
    cout << "Enter Last num ";
    cin >> number->Last_num[0];
    cin >> number->Last_num[1];
}

void input_Car(Car* car)
{
    cout << "Enter color of Car ";
    cin >> car->color;
    cout << "Enter model of Car ";
    cin >> car->model;
    Car_number* ptr;
    ptr = &car->number;
    input_CarNumber(ptr);
}

void print_number(Car_number num)
{
    cout << num.First_num[0] << num.First_num[1] << " " << num.number[0] << num.number[1] << num.number[2] << num.number[3] << " " << num.Last_num[0] << num.Last_num[1] << endl;
}

void print_Car(Car car)
{
    cout << "Color is " << car.color << endl;
    cout << "Model is " << car.model << endl;
    cout << "Number is ";
    print_number(car.number);
    cout << endl;
}

struct Washing_machine
{
    string firma;
    string color;
    int heigth;
    int wigth;
    double pover;
    double speed_pover;
    double temperature;
};

struct Iron
{
    string firma;
    string model;
    string color;
    double min_temperature;
    double max_temperature;
    bool bolid;
    double pover;
};

struct Boile_Mashine
{
    string firma;
    string color;
    double pover;
    double amount;
    double temperaturOfWarm;
};

void Show_WashingMachine(Washing_machine machine, string text = "struct washing mashine")
{
    cout << text << endl;
    cout << "Firma = " << machine.firma << endl;
    cout << "Color = " << machine.color << endl;
    cout << "Height = " << machine.heigth << endl;
    cout << "Wigth = " << machine.wigth << endl;
    cout << "Pover = " << machine.pover << endl;
    cout << "Speed Washing Mashine is = " << machine.speed_pover << endl;
    cout << "Temperature of warm is = " << machine.temperature << endl;
}

void Show_Iron(Iron iron, string text = "struct iron")
{
    cout << text << endl;
    cout << "Firma = " << iron.firma << endl;
    cout << "Model = " << iron.model << endl;
    cout << "Color = " << iron.color << endl;
    cout << "Min temperature = " << iron.min_temperature << endl;
    cout << "Max temperature = " << iron.max_temperature << endl;
    if (iron.bolid) cout << "install function of bolid" << endl;
    else
        cout << "do't install function of bolid" << endl;
    cout << "Pover = " << iron.pover << endl;
}

void input_client(Washing_machine* machine)
{
    cout << "Enter Firma = ";
    cin >> machine->firma;
    cout << "Enter Color = ";
    cin >> machine->color;
    cout << "Enter Height = ";
    cin >> machine->heigth;
    cout << "Enter Wigth = ";
    cin >> machine->wigth;
    cout << "Enter Pover = ";
    cin >> machine->pover;
    cout << "Enter Speed Washing Mashine = ";
    cin >> machine->speed_pover;
    cout << "Enter Temperature of warm = ";
    cin >> machine->temperature;
}

void corectionCar(Car car[10], int index)
{
    Car* ptr;
    ptr = &car[index];
    input_Car(ptr);
}

bool isNum(Car_number num_1, Car_number num_2)
{
    for (int i = 0; i < 4; i++)
        if (num_1.number[i] != num_2.number[i]) return false;
    if (num_1.First_num[0] != num_1.First_num[0] or num_1.First_num[1] != num_2.First_num[1]) return false;
    if (num_1.Last_num[0] != num_1.Last_num[0] or num_1.Last_num[1] != num_2.Last_num[1]) return false;
    return true;
}

int searchCar(Car car[10], Car_number num)
{
    for (int i = 0; i < 10; i++)
    {
        if (isNum(car[i].number, num)) return i;
    }
    return -1;
}

void printCar(Car car[10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Model " << car[i].model << endl;
        cout << "Color " << car[i].color << endl;
        cout << "Number ";
        print_number(car[i].number);
        cout << endl;
    }
}

int main()
{
    /*Washing_machine lenove;
    Washing_machine* len;
    lenove = {"lenovo", "red", 300, 150, 358.5, 600.32, 20.2};
    len = &lenove;
    Show_WashingMachine(lenove, "########## First Washing Mashine ##############");
    input_client(len);
    Show_WashingMachine(lenove, "########## Second Washing Mashine ##############");

    Iron iron_1;
    iron_1 = { "iron_228", "Ka332_8H", "Gray", 0, 100, true, 800.2 };
    Show_Iron(iron_1, "############## iron ##############");

    Boile_Mashine boiler;
    boiler = {"boiler", "blue", 123, 900, 43.8};
    cout << "################### Print boiler #######################";
    cout << "Firma boiler :: " << boiler.firma << endl;
    cout << "Color of boiler :: " << boiler.color << endl;
    cout << "Power of boiler is :: " << boiler.pover << endl;
    cout << "Amount of boiler is :: " << boiler.amount << endl;
    cout << "Temperature of boiler is :: " << boiler.temperaturOfWarm << endl;
    cout << "Enter Firm: ";
    cin >> boiler.firma;
    cout << "Enter color: ";
    cin >> boiler.color;
    cout << "Enter Power: ";
    cin >> boiler.pover;
    cout << "Enter Amount: ";
    cin >> boiler.amount;
    cout << "Enter temperature: ";
    cin >> boiler.temperaturOfWarm;
    cout << "################# Print boiler of input with console ####################";
    cout << "Firma boiler :: " << boiler.firma << endl;
    cout << "Color of boiler :: " << boiler.color << endl;
    cout << "Power of boiler is :: " << boiler.pover << endl;
    cout << "Amount of boiler is :: " << boiler.amount << endl;
    cout << "Temperature of boiler is :: " << boiler.temperaturOfWarm << endl;*/

    Car car_1;
    Car* ptr;
    ptr = &car_1;
    input_Car(ptr);
    print_Car(car_1);
    


    Car cars[10];
    for (int i = 0; i < 10; i++)
        cars[i] = car_1;
    corectionCar(cars, 3);
    Car_number number;
    Car_number* ptr_num;
    ptr_num = &number;
    input_CarNumber(ptr_num);
    cout << endl;
    cout << "INdex search = " << searchCar(cars, number) << endl;
    cout << endl;
    printCar(cars);

}

//Додаткове завдання на додаткові 12 балів
//Завдання 4
//Реалізувати структуру "Машина" (колір, модель, номер).Номер машини може бути
//або п'ятизначним номером, або словом до 8 символів.
//Рекомендації: номер реалізувати як об'єднання.
//Створити екземпляр структури "Машина" і реалізувати для нього такі функції :
//Заповнення машини;
//Друк машини.
//Створити масив із 10 екземплярів структури "Машина" і реалізувати для нього такі функції :
//Редагувати машину;
//Друк усіх машин;
//Пошук машини за номером.
