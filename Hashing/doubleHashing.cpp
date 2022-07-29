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
    int capacity= 20007;
    vector<values>table= vector<values>(20007);
public:
    int collision=0;
    int hash1(string key);
    int hash2(string key);
    int auxHash(string key);
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
        index=  index+ index*13 + ch[i];
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

int HashTable::auxHash(string key)
{
    long long int index= 7;
    char ch[key.length()];
    for(int i=0; i<key.length(); i++)
    {
        ch[i]= key[i];
        index=  index+ index*7 + ch[i]*5;
    }
    return (capacity-13) - index%(capacity-13);
}

void HashTable::insertItem(string key, int data)
{
    values v;
    v.key= key;
    v.data= data;
    int hashValue1= hash1(key);
    if(table[hashValue1].data!= 0)
    {
        int hashValue2= auxHash(key);
        int i=1;
        while(1)
        {
            int newIn= (hashValue1+ i*hashValue2)%capacity;
            if(table[newIn].data== 0)
            {
                table[newIn]= v;
                break;
            }
            i++;
        }
        collision= collision+ i;
    }
    else
    {
        table[hashValue1]= v;
    }

}

void HashTable::removeItem(string key)
{
    int hashValue1= hash1(key);
    int hashValue2= auxHash(key);
    int i=0;
    while(table[(hashValue1+ i*hashValue2)%capacity].key.compare(key) !=0)
    {
        if(table[(hashValue1+ i*hashValue2)%capacity].data == 0)
        {
            cout<< "Not found\n";
            return;
        }
        i++;
    }
    table.erase(table.begin()+ (hashValue1+ i*hashValue2)%capacity);
    cout<< "FOund and Erased\n";
    return;

}

int HashTable::searchItem(string key)
{
    int probe= 1;
    int hashValue1= hash1(key);
    int hashValue2= auxHash(key);
    int i=0;
    while(table[(hashValue1+ i*hashValue2)%capacity].key.compare(key) !=0)
    {
        if(table[(hashValue1+ i*hashValue2)%capacity].data == 0)
        {
            probe= probe+ i;
            return probe;
        }
        i++;
    }
    return probe+i;


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

