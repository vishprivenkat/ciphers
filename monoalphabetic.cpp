#include<iostream>
#include<algorithm> 
#include<map>
using namespace std;



int main()
{   char c, key; 
    string plainText;
    cout<<"Enter an alphabet you want to cipher: "; 
    cin>>c;

    cout<<"Enter the replacement alphabet: ";
    cin>>key;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Give a string to encrypt: "; 
    getline(cin, plainText); 
    cout<<"Encrypting..... "<<endl;

    //encrypting 

    replace_if( plainText.begin(), plainText.end(), [&,c](char a){ return (a==c); } , key);
    cout<<"Encrypted Text : "<< plainText; 
    cout<<endl; 


    return 1;
}