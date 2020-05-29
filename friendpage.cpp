/*Name of program: to add, display, search data and to add as a friend
filename:Friendpage.cpp
Author:Nagalakshmi pujari
date:10-5-2020
*/
/*its works in online compiler*/
#include<iostream>
#include<string.h>
#include<map>
#include<iterator>
using namespace std;
class Friendpage{
//creating class as Friendpage
//public:
    map<string,string> frnd_name;
    map<string,string> frnd_email;

    string name;
    string email;
    string frnd;
    char a;
    int choice;
public:
    //constructor
    Friendpage()
    {
        cout<<"constructor is invoked "<<endl;
        int choice = 0;
    }
/*Function Name :option
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the choice to perform*/
     void option()
    {
        cout<<" Enter the choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:Add_Data();break;
            case 2:Edit_Data();break;
            case 3:Search();break;
            case 4:Delete();break;
            case 5:byFriend();break;
            case 6:Display();break;
            case 7:Suggestion();break;
            case 8:exit(0);break ;
            default:
                cout<<" Entered option is in valid "<<endl;
        }
    }
/*Function Name :Add_Data
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to add ata */

    void Add_Data()
        {
        cout<<" Enter the name "<<endl;
        cin>>name;
        cout<<" Enter the email "<<endl;
        cin>>email;
        cout<<" Enter the friend name "<<endl;
        cin>>frnd;
        frnd_name.insert(make_pair(name,email));  //inserting the user details
        frnd_email.insert(make_pair(name,frnd));
        cout<<" press y to add more or any key to go to options "<<endl;
        cin>>a;
        if(a=='y'){
            Add_Data();
                }
        else{
            option();
                }
        }
/*Function Name :Delete
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to delete the data*/

   void Delete()             //delete function
    {
        string str;
        cout<<" Enter the name to Delete :- "<<endl;
        cin>>str;
        map<string, string>::iterator it;
        for(it=frnd_email.begin();it!=frnd_email.end();it++)
        {
                map<string, string>::iterator itr;
            for(itr=frnd_name.begin();itr!=frnd_name.end();itr++)
            {
                if(itr->first==str && it->first==str)
                {
                    frnd_name.erase(it->first);
                    frnd_email.erase(it->first);
                }
                if(itr->second==str)
                {
                    string s;
                    s=itr->first;
                    if(itr->first==s && it->first==s)
                    {
                        frnd_name.erase(it->first);
                        frnd_email.erase(it->first);
                    }
                }
            }
        }
        option();
    }
/*Function Name :Search
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to search the data from the list*/
    void Search()
    {
        string str;
        cout<<" enter name or email to search: "<<endl;
        cin>>str;
        cout<<"Name"<<"\t \t"<<"FRIEND NAME"<<" \t\t "<<"E-MAIL"<<endl;
                map<string, string>::iterator it;
        for(it=frnd_email.begin();it!=frnd_email.end();it++)
        {
                map<string, string>::iterator itr;
            for(itr=frnd_name.begin();itr!=frnd_name.end();itr++)
            {
                if(it->first==str && itr->first==str)
                {
                    cout<<it->first<<" "<<it->second<<"  "<<itr->second<<endl;
                    option();
                }
                if(it->second==str)
                {
                    string s;
                    s=itr->first;
                    if(itr->first==s && it->first==s)
                    {
                        frnd_name.erase(itr->first);       //delete data from list
                        frnd_email.erase(it->first);
                    }
                }
            }
        }
    }
/*Function Name :Edit_Data
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to edit the data*/
    void Edit_Data()
    {
         string Name;
         string Frnd;
         cout<<" enter the name to edit details "<<endl;
         cin>>name;
         cout<<" enter new name to change "<<endl;
         cin>>Name;
         cout<<" enter new email to change "<<endl;
         cin>>email;
         cout<<" Enter new friend name to change "<<endl;
         cin>>Frnd;
         frnd_name.erase(name);
         frnd_email.erase(name);
         frnd_name.insert(make_pair(Name,email));
         frnd_email.insert(make_pair(Name,Frnd));
        option();
    }

/*Function Name :byFriend
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to search the data by friend*/
    void byFriend()
    {
        string frd;
        cout<<" Enter the friend name:- "<<endl;
        cin>>frd;
        map<string, string>::iterator itr;
        for(itr=frnd_email.begin();itr!=frnd_email.end();itr++)
        {
            string ele;
            ele=itr->second;
            if(frd==ele)
            {
                cout<<itr->second<<" is the friend of "<<itr->first<<endl;
            }
        }
        option();
    }
/*Function Name :Display
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the data*/
     void Display()
    {
            cout<<" NAME"<<" \t \t "<<"  E-MAIL"<<"\t \t "<<"  FRIEND NAME  "<<endl;
            cout<<"----------------------------------------------------"<<endl;
            map<string, string>::iterator it;
            for(it=frnd_name.begin();it!=frnd_name.end();it++) //using iterator
            {
                map<string, string>::iterator itr;
                for(itr=frnd_email.begin();itr!=frnd_email.end();itr++)
                {
                      string p=it->first;
                      string q=itr->first;
                      if(p==q)
                      {
                          cout<<it->first<<" \t\t"<<it->second<<" \t\t "<<itr->second<<endl;
                       }
                }
            }
        option();
    }
    /*Function Name : suggestion
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to suggest the friend*/
    void Suggestion()
    {
        string suggest;
        cout<<" Enter the name to find Suggestion :- "<<endl;
        cin>>suggest;
        map<string, string>::iterator itr;
        for(itr=frnd_email.begin();itr!=frnd_email.end();itr++)
        {
            string a=itr->first;
            if(suggest==a)
            {
                string b=itr->second;
                map<string, string>::iterator it;
                                for(it=frnd_email.begin();it!=frnd_email.end();it++)
                {
                    if(b==it->first)
                    {
                        cout<<suggest<<" suggesion is : "<<it->second<<endl;
                    }
                }
            }
        }
        option();
    }
    ~Friendpage()
        {
         //destructor
        }

};
int main(int argc,char* argv[])
{
 if(argc>=2)
    {
        //help command
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<" creating a Friendpage "<<endl;
        }
    }
    else
    {
        //creating object for class
        Friendpage obj;
        cout<<"========================"<<endl;
        cout<<"Welcome to Friendpage"<<endl;
        cout<<"========================"<<endl;
        cout<<"1-Add user"<<endl;
        cout<<"2-Edit user"<<endl;
        cout<<"3-Search user data"<<endl;
        cout<<"4-Delete user"<<endl;
        cout<<"5-Search by friend "<<endl;
        cout<<"6-Display user details"<<endl;
        cout<<"7-Get Suggestion"<<endl;
        cout<<"8- exit"<<endl ;
        obj.option();
    }
}

