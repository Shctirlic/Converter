#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct Сurrency
{
    char* name;
    double rate;
};

void filling_arr_from_file(const char* path, Сurrency* arr_currency, int n)
{
    ifstream fin(path);

    char buf[100];
    int  k = 0;

    while (true)
    {
        if (!fin.getline(buf, 100)) return;
        arr_currency[k].name = strdup(buf);

        fin.getline(buf, 100);
        arr_currency[k++].rate = atof(buf);
    }

    fin.close();
}

void print_currencies(Сurrency* arr_currency, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%i. %s\n", i + 1, arr_currency[i].name, arr_currency[i].rate);
    }
}

void arr_free(Сurrency* arr_currency, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(arr_currency[i].name);
    }
}


int main()
{
    Сurrency arr_currency[10];
    int  n = 10;

    filling_arr_from_file("G:\\1\\currencies2.txt", arr_currency, n);



    print_currencies(arr_currency, n);
    printf("Select first currency: ");
    int N1; cin >> N1;

    system("cls");

    print_currencies(arr_currency, n);
    printf("Select second currency: ");
    int N2; cin >> N2;

    system("cls");

    cout << "Enter amount: ";
    float sum; cin >> sum;

    system("cls");

    cout << arr_currency[N1 - 1].name << " --->" << arr_currency[N2 - 1].name << endl;
    cout << sum << " --->" << sum * arr_currency[N1 - 1].rate / arr_currency[N2 - 1].rate << endl;


    arr_free(arr_currency, n);
}
