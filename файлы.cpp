

/*Задача 1 (Реализовать чтение ID3v1 MP3-файла. Будьте внимательны, не все MP3-файлы
содержат заполненный ID3-тег.
a. Название)*/
/*
#include <iostream>
#include <fstream>

int main() {
    // Открываем файл в двоичном режиме
    std::ifstream file("1.mp3", std::ios::binary);
    if(file.is_open())
    {
        // Перемещаем указатель на нужное место
        file.seekg(-125, std::ios::end);

        // Считываем название в массив байтов
        char tag[30];
        file.read(tag, 30);

        // Выводим название на экран
        std::cout << "Title: " << tag << std::endl;
    }
    else
        std::cout << "No found teg" << std::endl;

    // Закрываем файл
    file.close();

    return 0;
}
*/

/*Задача 2 (Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
считывать из файла in.txt. Результат записывать в текстовый файл out.txt*/

/*
#include <iostream>
#include <fstream>

float func_tab(int i_par_ch,float x_min, float y)
{
    int i_znam=7;
    int i_chisl=1;

    y = -1*(i_chisl/(i_znam*x_min));

    while(i_znam<i_par_ch)
    {
        if(i_znam<i_par_ch)
        {
            i_chisl++;
            i_znam++;
            y+=i_chisl/(i_znam*x_min);
        }

        if(i_znam<i_par_ch)
        {
            i_chisl++;
            i_znam++;
            y-=i_chisl/(i_znam*x_min);
        }
    }
//    i_znam=7;
//    i_chisl=1;

    return y;
}

int main()
{
    int x_min;
    int x_max;
    int i_par_ch;
    int tab;
    float x;
    float y=0;

    std::fstream file_in("in.txt", std::ios::in);

    if(file_in.is_open())
        file_in >> x_min >> x_max >> i_par_ch >> tab;
    file_in.close();

    std::fstream file_out("out.txt", std::ios::out);

    if(file_out.is_open())
    {
        for(;x_min<x_max;x_min+=tab)
        {
            file_out << x_min << "," << func_tab(i_par_ch,x_min,y) << '\n';
        }
    }
    file_in.close();

    return 0;
}
*/

/*Разработать программу для считывания данных о студентах из файла в следующем
формате: 1 строка Фамилия, 2 строка Средняя оценка, 3 строка Курс. Остальные
строки повторяют тройками эти данные для других студентов. Организовать
считывание данных из файла в массив структур. Организовать переменные для
хранения информации.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>

const int N = 4;

struct Bedniy_Student
{
    std::string surname;
    float sred_ocenka;
    int kurs;
};

int main()
{
    std::array<Bedniy_Student, N> students;

    std::fstream file_in("in_student.txt", std::ios::in);

    if (file_in.is_open())
    {
        for (int i = 0; i < N; i++)
        {
            file_in >> students[i].surname >> students[i].sred_ocenka >> students[i].kurs;
        }
    }
    file_in.close();

    for (int i = 0; i < N; i++)
    {
        std::cout << "Student " << i + 1 << ":" << std::endl <<
            students[i].surname << std::endl
            << students[i].sred_ocenka << std::endl
            << students[i].kurs << std::endl;
    }
    return 0;
}