#pragma once

#include <string>
#include "node.hpp"

using namespace std;

class Hash
{
private:
    int hashSize{0};
    int nodeAmount{0};
    Node **nodeVec;
    Node *getNode(string key) const;
    Node* insertNode(string key, string value);

public:
    Hash();
    Hash(unsigned int size);
    unsigned int hornerStrHash(string string) const;
    string toString() const;
    string getValue(string key) const;
    void deleteNode(string key);
    void setNode(string key, string value);
    int getAmount() const;
    int getHashSize() const;
};