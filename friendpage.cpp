/*Name of program: to add, display, search data and to add as a friend 
filename:Friendpage.cpp
Author:Naga lakshmi pujari
date:10-5-2020
*/

#include<iostream>
#include<string.h>
#include<map>
#include<iterator>
using namespace std;

class Friendpage           //creating class as Friendpage
{
//public:
    map<string,string> m1;
    map<string,string> m2;
    map<string,string> m3;
 	
 	string name;
    string email;
    string frnd;
    char a;
    int choice ;
        
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

        
        cout<<" Enter the choice:  "<<endl;
        cin>>choice ;
        switch( choice )
        {
            case 1 : add_data();
                     break;
            case 2: edit();
                    break;
           case 3: search();
                   break;
            case 4:Delete();
                    break;
            case 5:byFriend();
                    break;
            case 6:Display();
                    break;
            case 7:
            	exit(0) ;
            	break ;
            default:
                cout<<" Entered option is in valid "<<endl;
        }
    }
/*Function Name :add_data
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to add data */

    void add_data()              
	{
        cout<<" Enter the name "<<endl;
        cin>>name;
        cout<<" Enter the email "<<endl;
        cin>>email;
        cout<<" Enter the friend name "<<endl;
        cin>>frnd;
        m1.insert(make_pair(name,email));  //inserting the user details
        m2.insert(make_pair(name,frnd));
        cout<<" press y to add more or any key to go to options "<<endl;
        cin>>a;
        if(a=='y') 
		{ 
			add_data(); 
		}
        else 
		{ 
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
        for(it=m2.begin();it!=m2.end();it++)
        {
        	map<string, string>::iterator itr;
            for(itr=m1.begin();itr!=m1.end();itr++)
            {
                if(itr->first==str && it->first==str)
                {
                    m1.erase(it->first);
                    m2.erase(it->first);
                }
                if(itr->second==str)
                {
                    string s;
                    s=itr->first;
                    if(itr->first==s && it->first==s)
                    {
                        m1.erase(it->first);
                        m2.erase(it->first);
                    }
                }
            }
        }
        option();
    }
/*Function Name :search
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to search the data from the list*/
  
    void search()      
    {
        string str;
        cout<<" enter name or email to search: "<<endl;
        cin>>str;
        cout<<"Name"<<"\t \t"<<"FRIEND NAME"<<" \t\t "<<"E-MAIL"<<endl;
		map<string, string>::iterator it;
        for(it=m2.begin();it!=m2.end();it++)
        {
        	map<string, string>::iterator itr;
            for(itr=m1.begin();itr!=m1.end();itr++)
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
                        m1.erase(itr->first);       //delete data from list
                        m2.erase(it->first);
                    }
                }
            }


        }
    }
/*Function Name :edit
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to edit the data*/
  
    void edit()     
    {
         string Name;
         string Frnd;
         cout<<" name to edit details "<<endl;
         cin>>name;
         cout<<" enter name to change "<<endl;
         cin>>Name;
         cout<<" enter email to change "<<endl;
         cin>>email;
         cout<<" Enter new friend name to change "<<endl;
         cin>>Frnd;
         m1.erase(name);
         m2.erase(name);
         m1.insert(make_pair(Name,email));
         m2.insert(make_pair(Name,Frnd));
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
        for(itr=m2.begin();itr!=m2.end();itr++)
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
            cout<<" NAME"<<" \t \t "<<"E-MAIL"<<"\t \t "<<"FRIEND NAME"<<endl;
            map<string, string>::iterator it;
            for(it=m1.begin();it!=m1.end();it++) //using iterator
            {
            	map<string, string>::iterator itr;
                for(itr=m2.begin();itr!=m2.end();itr++)
                {
                      string p=it->first;
                      string q=itr->first;
                      if(p==q)
                      {
                          cout<<it->first<<" \t\t"<<it->second<<" \t\t "<<itr->second<<endl;
                       }
                }
            }

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
        
        cout<<"1-add user "<<endl;
        cout<<"2-edit users"<<endl;
        cout<<"3-search user data"<<endl;
        cout<<"4-delete user"<<endl;
        cout<<"5-search by friend "<<endl;
        cout<<"6-display data"<<endl;
	cout<<"enter any other key to exit"<<endl ;
		
		obj.option();
    }
}



