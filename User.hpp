#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <unordered_set>
#include "AVL_Trees.hpp"
using namespace std;


class User
{
    public:
    unordered_set<User*> friends;   //unordered set instead of vector for O(1) average search complexity
    string username;
    Node* root;
    int number_of_posts;


    User(string username)
    {
        this->username = username;
        this->root = NULL;
        this->number_of_posts = 0;

    }
};

