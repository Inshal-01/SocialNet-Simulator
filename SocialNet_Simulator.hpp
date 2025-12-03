#include "User.hpp"
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


class Graph
{
    unordered_map<string,User*> hashmap;

    public: 
    string to_lower(string username)
    {
        string lc_username = "";
        for(char ch : username)
        {
            ch = tolower(ch);
            lc_username += ch;
        }

        return lc_username;
    }

    void add_user(string username)
    {
        username = to_lower(username);

        if(hashmap.find(username)!=hashmap.end())
        {
            cout<<"User Already Exists!\n";
            return;
        }
        User* user = new User(username);
    
        hashmap[username] = user;
        cout<<"User Added!\n";
        return;
    }

    void add_friend(string u1,string u2)
    {
        u1 = to_lower(u1);
        u2 = to_lower(u2);

        if(hashmap.find(u1) == hashmap.end() or hashmap.find(u2) == hashmap.end())
        {
            cout<<"Username NOT Found!"<<'\n';
            return;
        }
        User* n1 = hashmap[u1];
        User* n2 = hashmap[u2];
        if(n1->friends.find(n2)!=n1->friends.end())
        {
            cout<<n1->username<<" and "<<n2->username<<" are already friends!\n";
            return;
        }
        n1->friends.insert(n2);
        n2->friends.insert(n1);
        cout<<u1<<" and "<<u2<<" are now friends!\n";
        return;
    }

    void list_friends(string username)
    {
        username = to_lower(username);

        if(hashmap.find(username) == hashmap.end())
        {
            cout<<"Username NOT Found!"<<'\n';
            return;
        }
        User* user = hashmap[username];

        if(user->friends.empty())
        {
            cout<<"No Friends!"<<'\n';
            return;
        }

        vector<string> v;
        for(User* f : user->friends)
        {
            v.push_back(f->username);
        }

        sort(v.begin(),v.end());

        int n = v.size();
        for(int i = 0;i<n;i++) cout<<v[i]<<'\n';
        
        return;
    }


    void suggest_friends(string username,int n)
    {
        if(n<0)
        {
            cout<<"Please Enter a Valid Number!\n";
            return;
        }
        if(n==0) return ;
        username = to_lower(username);

        if(hashmap.find(username) == hashmap.end())
        {
            cout<<"Username NOT Found!"<<'\n';
            return;
        }
        User* user = hashmap[username];

        unordered_map<User*,int> count;
        for(User* f : user->friends)
        {
            for(User* fof : f->friends)
            {
                if(fof!=user and user->friends.find(fof)==user->friends.end())
                {
                    count[fof]++;
                }
            }
        }

        if(count.empty())
        {
            cout<<"No Available Suggestions!\n";
            return;
        }
        vector<pair<User*,int>> v;

        for(auto it : count)
        {
            v.push_back({it.first,it.second});
        }


        sort(v.begin(),v.end(), [](const pair<User*,int> &a , const pair<User*,int> &b)
        {
            if(a.second != b.second)
            {
                return a.second > b.second;
            }

            else
            {
                return a.first->username < b.first->username;
            }
        });



        int i = 0;
        for(auto it : v)
        {
            if(i==n) return;
            cout<<it.first->username<<endl;
            i++;
        }


        return;
    }


    //BFS
    void degree_of_separation(string u1,string u2)
    {
        u1 = to_lower(u1);
        u2 = to_lower(u2);

        if(hashmap.find(u1) == hashmap.end() or hashmap.find(u2) == hashmap.end())
        {
            cout<<"Username NOT Found!"<<'\n';
            return;
        }
        User* user1 = hashmap[u1];
        User* user2 = hashmap[u2];

        queue<pair<User*,int>> q;

        unordered_set<User*> vis;

        int dis = 0;
        q.push({user1,dis});
        vis.insert(user1);
        
        while(!q.empty())
        {
            User* t = q.front().first;
            dis = q.front().second+1;
            q.pop();
            
            if(t==user2)
            {
                cout<<dis-1<<'\n';
                return;
            }

            for(User* f : t->friends)
            {
                if(vis.find(f)==vis.end())
                {
                    q.push({f,dis});
                    vis.insert(f);
                }
            }

            
        }

        //if path not found
        cout<<"-1"<<'\n';
        return;

    }


    void add_post(string username,string post)
    {
        username = to_lower(username);

        if(hashmap.find(username) == hashmap.end())
        {
            cout<<"Username NOT Found!"<<'\n';
            return;
        }
        User* user = hashmap[username];
        
        if(user->root == NULL)
        {
            user->root = new Node(post,time(NULL));
            user->number_of_posts++;
            cout<<"Post Added!\n";
            return;
        }

        user->root = user->root->insert(user->root,post,time(NULL));
        user->number_of_posts++;
        cout<<"Post Added!\n";
        return;
    }


    void output_posts(string username,int n)
    {
        if(n!=-1 and n < 0)
        {
            cout<<"Please Enter a Valid Number!\n";
            return;
        }
        username = to_lower(username);

        if(hashmap.find(username) == hashmap.end())
        {
            cout<<"Username NOT Found!"<<'\n';
            return;
        }
        User* user = hashmap[username];

        if(user->number_of_posts==0)
        {
            cout<<"No posts!\n";
            return;
        }
        if(n==-1 or n>=user->number_of_posts)
        {
            user->root->reverse_inorder(user->root);
        }

        else
        {
            int cnt = 0;
            user->root->reverse_inorder_n(user->root,n,cnt);
        }
        return;
    }

};
