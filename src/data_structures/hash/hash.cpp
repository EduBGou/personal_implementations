#include <string>
#include <format>
#include <iostream>
#include "hash.hpp"

#define HASH_SIZE 7
#define POWER 31

using namespace std;

Hash::Hash()
{
    this->hashSize = HASH_SIZE;
    this->nodeVec = new Node *[this->hashSize] {};
}

Hash::Hash(unsigned int size)
{
    this->hashSize = size;
    this->nodeVec = new Node *[this->hashSize] {};
}

unsigned int Hash::hornerStrHash(string str) const
{
    unsigned int hash = 0;

    for (int p = 0; p < str.size(); p++)
        hash = (hash * POWER + (unsigned char)str[p]) % this->hashSize;

    return hash;
}

Node *Hash::insertNode(string key, string value)
{
    unsigned int hashCode = hornerStrHash(key);

    Node *newNode = new Node(key, value);
    Node *currentNode = this->nodeVec[hashCode];

    this->nodeAmount++;
    if (currentNode == nullptr)
        return this->nodeVec[hashCode] = newNode;

    while (currentNode->next != nullptr)
        currentNode = currentNode->next;

    return currentNode->next = newNode;
}

string Hash::toString() const
{
    if (this->getAmount() == 0)
        return "{ }";

    string str = "{ | ";

    for (unsigned int idx = 0; idx < this->hashSize; ++idx)
    {
        Node *currentNode = this->nodeVec[idx];
        if (currentNode == nullptr) continue;
        while (currentNode != nullptr)
        {
            str.append(format("\"{}\": \"{}\", ", currentNode->key, currentNode->value));
            currentNode = currentNode->next;
        }
        str.pop_back();
        str.pop_back();
        str.append(" | ");
    }

    str.append("}");

    return str;
}

string Hash::getValue(string key) const
{
    auto node = getNode(key);
    if (node == nullptr)
        return "";

    return node->value;
}

void Hash::deleteNode(string key)
{
    unsigned int hashCode = hornerStrHash(key);
    Node *currentNode = this->nodeVec[hashCode];

    if (currentNode == nullptr)
        return;

    if (currentNode->key == key)
    {
        this->nodeVec[hashCode] = currentNode->next;
        delete currentNode;
        this->nodeAmount--;
        return;
    }

    while (currentNode->next != nullptr && currentNode->next->key != key)
        currentNode = currentNode->next;

    if (currentNode->next == nullptr)
        return;

    Node *toDelete = currentNode->next;
    currentNode->next = toDelete->next;
    delete toDelete;

    this->nodeAmount--;
}

Node *Hash::getNode(string key) const
{
    unsigned int hashCode = hornerStrHash(key);
    Node *currentNode = this->nodeVec[hashCode];

    while (currentNode != nullptr && currentNode->key != key)
        currentNode = currentNode->next;

    if (currentNode == nullptr)
        return nullptr;

    return currentNode;
}

void Hash::setNode(string key, string value)
{
    auto node = getNode(key);

    if (node == nullptr)
        node = insertNode(key, value);

    node->value = value;
}

int Hash::getAmount() const
{
    return this->nodeAmount;
}

int Hash::getHashSize() const
{
    return this->hashSize;
}
