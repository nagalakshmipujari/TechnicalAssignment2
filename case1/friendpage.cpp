/*program to create a friendpage
File name:friendpage.cpp
Author:Nagalakshmi pujari
Date:10-05-2020*/
#include<iostream>
#include<list>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

//creating class
class friendpage{
    char name[100];
    char email_id[100];
public:

/*Function Name :setname
  Parameters    :no parameter
  Return Type   :no return type
  */

    void setname()
    {
        cout<<"Enter Name:";
        getchar();
        cin.get(name,100,'\n');
    }

/*Function Name :setemail_id
  Parameters    :no parameter
  Return Type   :no return type
  */

    void setemail_id()
    {
        cout<<"Enter Email-id:";
        getchar();
        cin.get(email_id,100,'\n');
    }

/*Function Name :putname
  Parameters    :no parameter
  Return Type   :char return type
  */

    char* putname()
    {
        return name;
    }

/*Function Name :putemail_id
  Parameters    :no parameter
  Return Type   :string return type
  */

    char* putemail_id()
    {
        return email_id;
    }
};

/*Function Name :editfriendpage
  Parameters    :list object
  Return Type   :void return type
  */

void editfriendpage(list<friendpage> &std)
{
    friendpage c;
   char cname[1000];
    list<friendpage>:: iterator Itr;
    cout<<"Enter the name to edit:";
    getchar();
    cin.get(cname,1000,'\n');
    for(Itr=std.begin();Itr!=std.end();++Itr)
    {
        c=*Itr;
        if(strcmp(c.putname(),cname)==0)
        {
            //the value is been deleted
            std.erase(Itr);
            cout<<"Enter email_id to update"<<endl;
            c.setemail_id();
            cout<<"updated"<<endl;
            //the new value is pushed into file
            std.push_front(c);
        }
    }
    for(Itr=std.begin();Itr!=std.end();Itr++)
    {
        c=*Itr;
            cout<<c.putname()<<"="<<c.putemail_id()<<"\n";
        //the file again written with updated values
    }

}
/*Function Name :addfriendpage
  Parameters    :one list object parameter
  Return Type   :no return type*/

void addfriendpage(list<friendpage> &std)
{
    friendpage c;
    list<friendpage>:: iterator Itr;
    char option='y';
    while(option=='y' || option=='Y')
    {
        c.setname();
            c.setemail_id();
            std.push_back(c);
            for(Itr=std.begin();Itr!=std.end();Itr++)
            {
                c=*Itr;
                cout<<c.putname()<<"="<<c.putemail_id()<<endl;
            }
        cout<<"Data added succesfully"<<endl;
        cout<<"Do you want to append configaration data(y/n)?";
        cin>>option;
    }
}

/*Function Name :deletefriendpage
  Parameters    :one list object parameter
  Return Type   :no return type
  */

void deletefriendpage(list<friendpage> &std)
{
    char cname[100];
    friendpage cn;
    list<friendpage>:: iterator it;
    cout<<"Enter the name to delete:";
    getchar();
    cin.get(cname,100,'\n');

    for(it=std.begin();it!=std.end();it++)
    {
                cn=*it;
        if((strcmp(cn.putname(),cname)==0))
        {
            std.erase(it);
            cout<<"deleted"<<endl;
                break;
        }
        else
                cout<<"name not found"<<endl;
    }

}
/*Function Name :displayfriendpage
  Parameters    :no parameter
  Return Type   :no return type
  */

void displayfriendpage(list<friendpage> &std)
{
    friendpage cg;
    char info[100];
    list<friendpage>:: iterator itr;
   for(itr=std.begin();itr!=std.end();++itr)
    {
        cg=*itr;
     cout<<cg.putname()<<endl<<cg.putemail_id()<<endl;
    }
}
/*Function Name :searchfriendpage
  Parameters    :one list object parameter
  Return Type   :no return type
  */

void searchfriendpage(list<friendpage> &std)
{
    friendpage ch;
    char option;
    char Searchname[500];
    char Searchemail_id[100];
    list<friendpage>:: iterator iTR;
    cout<<"do u want search name or email_id(n/e):";
    cin>>option;
    if(option=='n'||option=='N')
    {
        cout<<"Enter name u want to search:";
        getchar();
        cin.get(Searchname,500,'\n');
        for(iTR=std.begin();iTR!=std.end();iTR++)
        {
            ch=*iTR;
            if(strcmp(Searchname,ch.putname())==0)
            {
                cout<<ch.putname()<<"="<<ch.putemail_id()<<endl;
            }
            else
            {
                cout<<"name not found"<<endl;
            }
        }
    }
    else if(option=='e'||option =='E')
    {
        cout<<"Enter email_id u want to search:";
        getchar();
        cin.get(Searchemail_id,100,'\n');
        for(iTR=std.begin();iTR!=std.end();iTR++)
        {
            ch=*iTR;
            if(strcmp(Searchemail_id,ch.putemail_id())==0)
             {
                   cout<<ch.putname()<<"="<<ch.putemail_id()<<endl;
                }
                else
                        cout<<"email_id notfound"<<endl;
        }

}

}
int main(int argc,char* argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"usage:  friendpage application"<<endl;
            cout<<"select required option"<<endl;
        }
    }
    else
    {
        list<friendpage> std;
        list<friendpage>:: iterator Itr;
        char Opt;
        while(1)
        {
           cout<<"------------------------------------------------"<<endl;
           cout<<"\t    WELCOME TO FRIENDPAGE     "<<endl;
           cout<<"------------------------------------------------"<<endl;
            cout<<"Select your option:"<<endl<<" 1.add"<<endl<<" 2.delete"<<endl<<" 3.display"<<endl<<" 4.edit"<<endl<<" 5.search"<<endl<<" 6.exit"<<endl;
            cin>>Opt;
            switch(Opt)
            {
                case '1':
                        addfriendpage(std);
                        break;
                case '2':
                        deletefriendpage(std);
                        break;
                case '3':
                        displayfriendpage(std);
                        break;
                case '4':
                        editfriendpage(std);
                        break;
                case '5':
                        searchfriendpage(std);
                        break;
                case '6':
                        exit(0);
                        break;
                default:
                        return 0;
            }
        }
    }
return 0;
}

