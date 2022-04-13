#pragma once
#include <string>
#include "PostAdres.h"

struct Node
{
    Node(PostAdres& adres);
    ~Node();
    PostAdres adres;
    Node* next;
    bool isTail;
};
class MyList
{
    Node *head;
    Node *tail;
    int size;
public:
    MyList();
    MyList(Node& node);
    MyList(PostAdres& Adres);
    ~MyList();
    void Add(Node& node);
    int Delete(Node& node);
    Node& Front();
    Node& Back();
    int Size();
    bool Empty();



    bool equal(MyList &list);
};

