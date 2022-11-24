#include <ctime>
#include <iostream>
#include  <cstdlib>
using namespace std;

int multiply(int a,int b){
    int sum=0;
    for(int i=0;i<a;i++){
        sum+=b;
    }
    return sum;
    
}
int sumLeftmost(string s){
    int sum=s[0]-'0';
    for(int i=0;i<s.size();i++){
        if(s[i]=='_'){
            sum+=s[i+1]-'0';
        }    
    }
    return sum;
}
void printMatrix1(int mat[][2], int r)
 {
     for (int i=0; i<r; i++)
         {
         for (int j=0; j<2; j++)
             cout << mat[i][j] << "\t";
         cout << endl;
     }
 }
void printMatrix2(int mat[][3], int r)
 {
     for (int i=0; i<r; i++)
         {
         for (int j=0; j<3; j++)
             cout << mat[i][j] << "\t";
         cout << endl;
     }
 }
int main()
{
    const int x=3;
    const int y=2;
    srand(time(0));
    
    int mat1[x][y];
    int mat2[y][x];
    for(int i=0; i<x; i++ ){
        for(int j=0; j<y; j++){
            mat1[i][j]=(rand()%20)+1;
            
        }
    }
    for(int i=0; i<y; i++ ){
        for(int j=0; j<x; j++){
            mat2[i][j]=(rand()%20)+1;
            
        }
    }
    printMatrix1(mat1,3);
    cout<<"-------------------------------"<<endl;
    printMatrix2(mat2,2);
    cout<<"-------------------------------"<<endl;
    int mat3[3][3];
    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            mat3[i][j]=multiply(mat1[i][0],mat2[0][j])+multiply(mat1[i][1],mat2[1][j]);
        }
        
    }
    printMatrix2(mat3,3);
    string str="";
    for(int i=0;i<3;i++){
       str+=to_string(mat3[i][i])+'_'; 
    }
    for(int j=2;j>=0;j--){
       str+=to_string(mat3[j][2])+'_'; 
    }
    for(int i=0, j=2;i<3;i++, j--){
       str+=to_string(mat3[i][j])+'_'; 
    }
    for(int i=2; i>=0;i--){
        if(i!=0)
            str+=to_string(mat3[i][0])+'_';
        else
        str+=to_string(mat3[i][0]);
    }
    
    cout<<str<<endl;
    cout<<sumLeftmost(str)<<endl;
    return 0;
}
