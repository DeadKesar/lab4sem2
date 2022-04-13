//Разработать список(любой наиболее удобный) объектов типа «почтовый адрес».
//Описать логическую функцию equal(l1, l2), проверяющую на равенство списки адресов l1 и l2.

#pragma once
#include "MyList.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Лабораторная работа №4. \nПо теме: \"Организация и обработка базовых динамических структур данных.\"\n" <<
        "Вариант №7 \nВыполнил: Порядин В.С." << std::endl;
    PostAdres* ad1 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "24");
    PostAdres* ad2 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "25");
    PostAdres* ad3 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "26");
    PostAdres* ad4 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "27");
    MyList *list1 = new MyList(*ad1);
    list1->Add(*(new Node(*ad2)));
    list1->Add(*(new Node(*ad3)));
    MyList* list2 = new MyList(*ad1);
    list2->Add(*(new Node(*ad2)));
    list2->Add(*(new Node(*ad3)));
    if (list1->equal(*list2))
        std::cout << std::endl << "списки совпадают";
    else
        std::cout << std::endl << "не совпадают";

    list2->Add(*(new Node(*ad4)));
    if (list1->equal(*list2))
        std::cout << std::endl << "списки совпадают";
    else
        std::cout << std::endl << "не совпадают";
    delete ad1;
    delete list1;
    delete list2;
}

