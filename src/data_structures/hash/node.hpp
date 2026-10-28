#pragma once

#include <string>

using namespace std;

class Node
{
public:
    Node();
    Node(string key, string value);

    string key = "";
    string value = "";
    Node *next = nullptr;
};