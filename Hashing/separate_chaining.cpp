#include<iostream>
#include<vector>
#include <ctime>
#include <random>
#include<cstring>
using namespace std;

struct values
{
    string key;
    int data;
};

std::string random_string(int length )
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz" ;
    static std::default_random_engine rng( std::time(nullptr) ) ;
    static std::uniform_int_distribution<int> distribution( 0, alphabet.size() - 1 ) ;

    std::string str ;
    while( str.size() < length )
        str += alphabet[ distribution(rng) ] ;
    return str ;
}


class HashTable
{
private:
    int capacity= 40007;
    vector<values>table[40007];
public:
    int collision=0;
    int hash1(string key);
    int hash2(string key);
    void insertItem(string key, int data);
    void removeItem(string key);
    int searchItem(string key);
    int getCapacity();
    void setCapacity(int value);
};

int HashTable::hash1(string key)
{
    long long int index= 7;
    char ch[key.length()];
    for(int i=0; i<key.length(); i++)
    {
        ch[i]= key[i];
        index=  index+ index*11 + ch[i];
    }
    return index%capacity;
}

int HashTable::hash2(string key)
{
    long long int sum=0;
    char ch[key.length()];
    for (int i = 0; i < key.length(); i++)
    {
        ch[i]= key[i];
        sum= sum+ ch[i]<< (3*i);
        sum= sum%capacity;
    }
    return sum% capacity;
}

void HashTable::insertItem(string key, int data)
{
    int hashValue= hash2(key);
    if(table[hashValue].size() != 0)
    {
        collision++;

    }
    values v;
    v.key= key;
    v.data= data;
    table[hashValue].push_back(v);


}

void HashTable::removeItem(string key)
{
    int hashValue= hash2(key);
    if(table[hashValue].size()==0)
    {
        cout<< "Not in hashTable\n";
        return;
    }
    else
    {
        for(int i=0; i<table[hashValue].size(); i++)
        {
            if(table[hashValue][i].key.compare(key)==0)
            {
                table[hashValue].erase(table[hashValue].begin()+ i);
                cout<< "Successfully Removed!\n";
                break;
            }
        }
    }
    return;

}

int HashTable::searchItem(string key)
{
    int probe= 1;
    int hashValue= hash2(key);
    if(table[hashValue].size()==0)
    {
        cout<< "Not in hashTable\n";
    }
    else
    {
        for(int i=0; i<table[hashValue].size(); i++)
        {
            if(table[hashValue][i].key.compare(key)==0)
            {
                probe= probe+ i;
                break;
            }
        }
    }
    return probe;


}


int main()
{
    string s[10001];
    HashTable h1;
    for(int i = 0 ; i < 10000 ; i++)
    {
        s[i]= random_string(7);
        h1.insertItem(s[i], i+1);
    }
    cout<< h1.collision<< endl;
    int probe;
    for(int i=0; i<1000; i++)
    {
        probe= probe+ h1.searchItem(s[rand()%10000]);
    }
    cout<< "Average Probes: "<< probe/1000.0<<endl;




}

