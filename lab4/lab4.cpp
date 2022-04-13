//Разработать список(любой наиболее удобный) объектов типа «почтовый адрес».
//Описать логическую функцию equal(l1, l2), проверяющую на равенство списки адресов l1 и l2.

#pragma once
#include "MyList.h"
#include <iostream>

int main()
{
    PostAdres* ad1 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "24");
    PostAdres* ad2 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "25");
    PostAdres* ad3 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "26");
    PostAdres* ad4 = new PostAdres(123, "russia", "mockow", "big Akademik", "2", "", "27");


    std::cout << ad1->equal(*ad2);
    std::cout << std::endl << ad1->ToString();
    std::cout << std::endl << ad1->compare(*ad2);
    MyList *list1 = new MyList(*ad1);
    list1->Add(*(new Node(*ad2)));
    list1->Add(*(new Node(*ad3)));
    MyList* list2 = new MyList(*ad1);
    list2->Add(*(new Node(*ad2)));
    list2->Add(*(new Node(*ad3)));
    std::cout << std::endl << list1->equal(*list2);
    list2->Add(*(new Node(*ad4)));
    std::cout << std::endl << list1->equal(*list2);
}

