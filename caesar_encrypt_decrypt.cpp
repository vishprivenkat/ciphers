#include<iostream>
#include<algorithm> 

using namespace std;



int main()
{   char c = 'a'; 
    int k;
    string plainText;
    
    //Create a hashmap for key 
    
    cout<<"Enter a key value: ";
    cin>>k;    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Give a string to encrypt: "; 
    getline(cin, plainText); 


    cout<<"Encrypting..... "<<endl;

    //encrypting 
    for(auto it = plainText.begin(); it!=plainText.end(); it++)
    {     *it = char((((*it+k)%97)%26) + 97);
    }


    cout<<"Encrypted Text : "<< plainText<<endl; 
    
    //decrypting 
    for(auto it = plainText.begin(); it!=plainText.end(); it++)
    {     *it = char((((*it-k)%97)%26) + 97);
    }
    
    cout<<"Decrypted Text : "<< plainText; 
    
    cout<<endl; 




    return 1;
}