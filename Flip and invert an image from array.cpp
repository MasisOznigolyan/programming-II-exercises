
#include <iostream>
#define ROW 3
#define COLL 3
using namespace std;
int** arrayToMatrix(int* arr,int rows,int colls){
    int** array= new (nothrow) int* [rows];
    for(int i=0; i<rows; i++){
        array[i]= new (nothrow) int [colls];
    }
    int index_of_arr=0;
    for(int i=0;i<rows;i++){
        for(int j=0; j<colls; j++){
            array[i][j]=arr[index_of_arr];
            index_of_arr++;
        }
    }
    return array;    
}
void printMat(int** mat, int rows, int colls){
    for(int i=0;i<rows;i++){
        for(int j=0; j<colls; j++){
            cout<<mat[i][j]<<"\t";
        }
    
        cout<<endl;
    }
}
void _swap(int &x, int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;

}
void flipAndInvertImage(int** mat,int rows,int colls){
    for(int i=0; i<rows; i++){
        int t=0;
        int j=colls-1;
        while(t<j){
            swap(mat[i][t],mat[i][j]);
            t++;
            j--;
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0;j<colls;j++){
            if(mat[i][j]==0){
                mat[i][j]=1;
            }
            else{
                mat[i][j]=0;
            }
        }
    }
}
void deleteMatrix(int** mat, int rows)
{
    for (int i=0; i<rows; i++)
        delete[] mat[i];
    delete[] mat;
    mat = nullptr;
}
int main()
{
    int asd[ROW*COLL]={1, 1, 0, 0, 0, 1, 0, 1, 1};
    int** mat = arrayToMatrix(asd,ROW,COLL);
    printMat(mat,ROW,COLL);
    cout<<"-------------"<<endl;
    flipAndInvertImage(mat,ROW,COLL);
    printMat(mat,ROW,COLL);
    deleteMatrix(mat,ROW);
    
    return 0;
}
