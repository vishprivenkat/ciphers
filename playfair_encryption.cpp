#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>
using namespace std;

char toChar(int i)
{   return char(i);
}

int toInt(char c)
{   return c+0;

}

int rowsearch(int mat[][5], int a,int b)
{   int f1=0, f2=0, p1=0; 
    for(int i=0; i<5; i++)
        for( int j=0; j<5; j++)
        {   if(mat[i][j]==a)
            {   f1=1;
                p1=i;
                break;
            }
            if(f1)
                break;
        }
    for(int i=0; i<5; i++)
        if(mat[p1][i]==b)
        {   f2=1;
            break;

        }

    if(f1 && f2)
        return p1;
    return 0; 
}

int colsearch(int mat[][5], int a,int b)
{   int f1=0, f2=0, p1=0; 
    for(int i=0; i<5; i++)
        for( int j=0; j<5; j++)
        {   if(mat[i][j]==a)
            {   f1=1;
                p1=j;
                break;
            }
            if(f1)
                break;
        }
    for(int i=0; i<5; i++)
        if(mat[i][p1]==b)
        {   f2=1;
            break;

        }

    if(f1 && f2)
        return p1;
    return 0; 
}

void printMat(int mat[][5])
{   for(int i=0; i<5; i++) 
    {   for(int j=0; j<5; j++)
            cout<<char(mat[i][j])<<" ";
        cout<<endl;


    }

}

int rowwise(int mat[][5], int a, int r)
{   for(int j=0; j<5; j++)
        if(mat[r][j] == a ) 
          return mat[r][(j+1)%5] ; 

    return 0; 

}

int colwise(int mat[][5], int a, int c)
{   for(int j=0; j<5; j++)
        if(mat[j][c] == a ) 
         return mat[(j+1)%5][c] ; 

    return 0;

}

void third(int mat[][5], int a, int b)
{   int r1,c1,r2,c2; 
    for(int i=0; i<5; i++)
        for( int j=0; j<5; j++)
        {   if(mat[i][j]==a)
            {   r1=i;
                c1=j;
                break;
            }
        }
    
    for(int i=0; i<5; i++)
        for( int j=0; j<5; j++)
        {   if(mat[i][j]==b)
            {   r2=i;
                c2=j;
                break;
            }
        }

    cout<< toChar(mat[r1][c2])<<toChar(mat[r2][c1]); 

}



int main()
{   int keyMatrix[5][5];
    string key, plainText; 

    vector<int> v;
    for(int i=0; i<26; i++)
        v.push_back(97+i); 
    //remove j     
    remove(v.begin(), v.end(), 106); 

    cout<<"Enter Key text: ";
    getline(cin, key); 

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter Plain Text: "; 
    getline(cin, plainText); 

    int row=0, col=0;


    // generate key table
    for(auto it = key.begin(); it!=key.end(); it++)
    {   if(row<5 && col<5)
        {   keyMatrix[row][col] = toInt(*it);
            col++;
        }
        if(col>=5)
        {   col = 0;
            row+=1;
            keyMatrix[row][col] = toInt(*it);

        }
        remove(v.begin(), v.end(), toInt(*it)); 
    }
   
   for(auto it=v.begin(); it!=v.end(); it++)
    {   if(row<5 && col < 5)
        {  keyMatrix[row][col] = *it;
           col++;
        }
        if(col>=5)
        {   col = 0;
            row+=1;
            keyMatrix[row][col] = *it;

        }
    }

    printMat(keyMatrix);


   //odd or even string length
   if(plainText.length()%2)
        plainText.push_back('z'); 

    cout<<"Encrypted String: "<<endl;

   for(int i=1; i<plainText.length(); i+=2)
   {    char a = plainText.at(i-1);
        char b = plainText.at(i); 
        int f1=0, f2=0;
        //same row
        int v = rowsearch(keyMatrix, toInt(a),toInt(b)) ; 
        if(v)
        {   cout<<toChar(rowwise(keyMatrix, toInt(a), v))<<toChar(rowwise(keyMatrix, toInt(b), v)) ; 
            f1=1;
            continue; 
        }

        //same col
        v = colsearch(keyMatrix, toInt(a),toInt(b)) ; 
        if(v)
        {   cout<<toChar(colwise(keyMatrix, toInt(a), v))<<toChar(colwise(keyMatrix, toInt(b), v)) ; 
            f2=1;
            continue; 
        }

        //none of the above
        if(!f1 && !f2)
        third(keyMatrix, a,b); 

   }
    
   
    cout<<endl;
    return 1;



    


}