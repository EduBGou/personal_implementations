#include <iostream>
#include <string>
#include "hash.hpp"

using namespace std;

int main()
{
    Hash *hash = new Hash();

    hash->setNode("nome", "eduardo");
    cout << "hash nome: " << hash->hornerStrHash("nome") << endl;
    cout << "nome: " << hash->getValue("nome") << endl;
    
    cout << "peso: " << hash->getValue("peso") << endl;
    hash->setNode("peso", "72Kg");
    cout << "hash peso: " << hash->hornerStrHash("peso") << endl;
    cout << "peso: " << hash->getValue("peso") << endl;
    
    hash->setNode("idade", "19 anos");
    cout << "hash idade: " << hash->hornerStrHash("idade") << endl;
    cout << "idade: " << hash->getValue("idade") << endl;
    
    hash->setNode("idade", "17 anos");
    cout << "idade: " << hash->getValue("idade") << endl;
    
    hash->setNode("sexo", "M");
    cout << "hash sexo: " << hash->hornerStrHash("sexo") << endl;
    cout << "sexo: " << hash->getValue("sexo") << endl;

    cout << "hash: " << hash->toString() << endl;
    
    hash->deleteNode("idade");
    
    cout << "hash: " << hash->toString() << endl;
}