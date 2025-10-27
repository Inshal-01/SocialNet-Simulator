#include <iostream>
#include <sstream>
#include "SocialNet_Simulator.hpp"
using namespace std;


int main()
{
    Graph g;
    
    string s, cmd, username1, username2;  

    while (getline(cin, s)) 
    {   
        // read full line
        cmd = username1 = username2 = ""; // reset

        // Use stringstream for easier parsing
        stringstream ss(s);
        ss >> cmd >> username1;
        getline(ss, username2); // get remaining part as username2
        if (!username2.empty() && username2[0] == ' ') username2.erase(0, 1); // trim space

        if(cmd == "EXIT") return 0;
        
        if(cmd=="ADD_USER")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else 
            {
                g.add_user(username1);
                cout<<"User Added!";
            }
        }

        else if(cmd=="ADD_FRIEND")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else if(username2=="") cout<<"Please Enter Friend's Username!"<<'\n';
            else 
            {
                g.add_friend(username1,username2);
                cout<<username1<<" and "<<username2<<" are now friends!";
            }
        }

        else if(cmd == "LIST_FRIENDS")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else g.list_friends(username1);
        }

        else if(cmd == "SUGGEST_FRIENDS")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else if(username2=="") cout<<"Please Enter Number of Friends to be Suggested!"<<'\n';
            else g.suggest_friends(username1,stoi(username2));
        }
 
        else if(cmd == "DEGREE_OF_SEPARATION")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else if(username2=="") cout<<"Please Enter Friend's Username!"<<'\n';   
            else g.degree_of_separation(username1,username2);
        }

        else if(cmd == "ADD_POST")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else if(username2=="") cout<<"Please Enter Post Content!"<<'\n';
            else 
            {
                g.add_post(username1,username2);
                cout<<"Post Added!";
            }
        }
        else if(cmd == "OUTPUT_POSTS")
        {
            if(username1=="") cout<<"Please Enter Username!"<<'\n';
            else if(username2=="") cout<<"Please Enter Number of Posts!"<<'\n';
            else g.output_posts(username1,stoi(username2));
        }
        else 
        {
            cout<<"PLEASE ENTER A VALID COMMAND!"<<'\n';
        }
    }
    return 0;
}