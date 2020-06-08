/*To write a program m*n matrix by replace the repeated place with '*'
filename:matrix.cpp
Author:Nagalakshmi P
Date:16/05/2020*/
#include<iostream>
#include<string.h>
using namespace std;
void getarray(char a[20][20],int i_rows,int i_columns);
int replacefunc(char a[20][20],int i_rows,int i_columns,int i_check);
void transpose(char a[20][20],char trans[20][20],int i_rows,int i_columns);
int leftdiagonal(char a[20][20],int i_rows,int i_columns,int i_check);
int rightdiagonal(char a[20][20],int i_rows,int i_columns,int i_check);
void display(char a[20][20],int i_rows,int i_columns);
int main(int argc,char* argv[])
{
        if(argc==2)
        {
                if(strcmp(argv[1], "-h")==0)
                {
                        cout<<"usage:matrix.exe"<<endl;
                        cout<<"select required option"<<endl;
                }
        }
        else
        {
                char a[20][20];
                char trans[20][20],temp[20][20];
                int i_rows,i_columns,row,column,option;
                int i_check=0;
                cout<<"Enter the number of rows and columns : ";
                cin>>i_rows>>i_columns;
                getarray(a,i_rows,i_columns);
                cout<<endl;
                cout<<"======Matrix Options======"<<endl;
                cout<<"1.row matrix"<<endl;
                cout<<"2.column matrix"<<endl;
                cout<<"3.diagonal matrix"<<endl;
                cout<<"Choose your option : ";
                cin>>option;
                cout<<"Entered Matrix :"<<"\n";
                display(a,i_rows,i_columns);
                if(option == 1)
                {
                        cout<<"row wise matrix"<<"\n";
                        i_check = replacefunc(a,i_rows,i_columns,i_check);
                        if(i_check==0)
                        {
                                cout<<"There is No Row wise sequence in Matrix...."<<endl;
                        }
                        display(a,i_rows,i_columns);
                }
                else if(option == 2)
                {
                        cout<<endl<<"column wise matrix"<<"\n";
                        transpose(a,trans,i_rows,i_columns);
                        i_check=replacefunc(trans,i_rows,i_columns,i_check);
                        transpose(trans,temp,i_rows,i_columns);
                        if(i_check==0)
                        {
                                cout<<"There is No Column wise sequence in Matrix...."<<endl;
                        }
                        display(temp,i_rows,i_columns);
                }
                else if(option==3)
                {
                        cout<<"diagonal wise matrix"<<endl;
                        i_check=leftdiagonal(a,i_rows,i_columns,i_check);
                        if(i_check==0)
                        {
                                cout<<"There is no diagonal wise sequence in matrix:"<<endl;
                        }
                        display(a,i_rows,i_columns);
                }
                else if(option==4)
                {
                        cout<<"right diagonal matrix"<<"\n";
                        i_check=rightdiagonal(a,i_rows,i_columns,i_check);
                        if(i_check==0)
                        {
                                cout<<"there is no right diagonal wise sequence in matrix"<<endl;
                        }
                        display(a,i_rows,i_columns);
                }
                else
                {
                        cout<<"Invalid option"<<endl;
                }
        }
}
void display(char a[20][20],int i_rows,int i_columns)
{
        int row,column;
        for(row=0;row<i_rows;row++)
        {
                for(column=0;column<i_columns;column++)
                {
                        cout<<a[row][column]<<"\t";
                }
                cout<<endl;
        }
}
void transpose(char a[20][20],char trans[20][20],int i_rows,int i_columns)
{
        int row,column;
        for(row=0;row<i_rows;row++)
        {
                for(column=0;column<i_columns;column++)
                {
                        trans[column][row]=a[row][column];
                }
        }
}
int replacefunc(char a[20][20],int i_rows,int i_columns,int i_check)
{
        for(int row=0;row<i_rows;row++)
        {
                int column=1;
                int count=0;
                int i_column1=i_columns;
                int temp=a[row][0];
                while(column<i_columns1)
                {
                        if(a[row][column]==temp)
                        {
                                count++;
                                i_check++;
                                int k=column;
                                for(int countcolumn=k;countcolumn<i_columns1-1;countcolumn++)
                                {
                                        a[row][countcolumn]=a[row][countcolumn+1];
                                }
                                i_columns1--;
                                if(a[row][column]!=temp)
                                {
                                        temp=a[row][column];
                                        column++;
                                }
                        }
                        else
                        {
                                temp=a[row][column];
                                column++;
                        }
        }
        while(count>0)
        {
                        a[row][i_columns-count]='*';
                        count--;
                }
        }
        return i_check;
}
int leftdiagonal(char a[20][20],int i_rows,int i_columns,int i_check)
{
        int temp=a[0][0];
        int row,column,i_count;
        row=1;
        column=1;
        i_count=0;
        int i_rows1=i_rows,i_columns1=i_columns;
        while(row<i_rows1)
        {
                if(a[row][column]==temp)
                {
                        i_count++;
                        i_check++;
                        int newrow=row,newcolumn=column;
                        while(newrow<i_rows1-1)
                        {
                                a[newrow][newcolumn]=a[newrow+1][newcolumn+1];
                                newrow++;
                                newcolumn++;
                        }
                        i_rows1--;
                        if(a[row][column]!=temp)
                        {
                                temp=a[row][column];
                                row++;
                        }
                }
                else
                {
                        temp=a[row][column];
                        row++;
                }
        }
        while(i_count>0)
        {
                a[i_rows-i_count][i_columns-i_count]='*';
                count--;
        }
        return i_check;
}
int rightdiagonal(char a[20][20],int i_rows,int i_columns,int i_check)
{
        int temp=a[0][i_columns-1];
        int row,column,count;
        row=1;
        column=i_columns-2;
        count=0;
        int i_rows1=i_rows,i_columns1=i_columns;
        while(i_row<i_rows1)
        {
                if(a[i_row][i_column]==temp)

        {
                count++;
                i_check++;
                int newrow=i_row,newcolumn=i_column;
                while(newrow<i_rows1-1)
                {
                        a[newrow][newcolumn]=a[newrow+1][newcolumn-1];
                        newrow++;
                        newcolumn--;
                }
                i_rows1--;
                if(a[row][column]!=temp)
                {
                        temp=a[row][column];
                        row++;
                        column--;
                }
        }
        else
        {
                temp=a[row][column];
                row++;
                column--;
                }
        }
        int row=i_rows-1;
        int column=0;
        while(count>0)
        {
                a[row][column]='*';
                count--;
                row--;
                count++;
        }
        return i_check;
}
void getarray(char a[20][20],int i_rows,int i_columns)
{
        int row,column;
        for(row=0;row<i_rows;row++)
        {
                for(column=0;column<i_columns;column++)
                {
                        bool check=true;
                        cout<<"enter value of row and column:";
                        cin>>a[row][column];
                        while(i_check)
                        {
                                if(a[row][column]=='1' || a[row][column]=='0')
                                {
                                        i_check=false;
                                }
                                else
                                {
                                        cout<<"please enter 0 or 1 only"<<endl;
                                        cout<<"enter the value of row and column:";
                                        cin>>a[row][column];
                                }
                        }
                }
        }
}
