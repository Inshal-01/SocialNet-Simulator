SocialNet Simulator - README

This project is implemented in C++ using source (main.cpp) and header (AVL_Trees.hpp, User.hpp, Graph.hpp) files.
This assignment simulates a simple social network using a graph of users and AVL trees
to store user posts. The program reads commands from standard input and prints
output directly to standard output.

------------------------------------------------
HOW TO COMPILE AND RUN:
------------------------------------------------
1. Compile the code:
   g++ main.cpp -o main

2. Run the executable:
   ./main

------------------------------------------------
DATA STRUCTURES USED:
------------------------------------------------
- Graph using an unordered_map<string, User*>
  to store users and unordered_set<User*> to store friends of user.
- Each user's posts are stored in an AVL Tree sorted by timestamp.

------------------------------------------------
SUPPORTED COMMANDS:
------------------------------------------------

ADD USER <username>
    -> Adds a new user to the network.
    -> (Usernames are converted to lowercase internally.)

ADD FRIEND <username1> <username2>
    -> Creates a bidirectional friendship between the two users.
    -> Prints "Username NOT Found!" if either user does not exist.

LIST FRIENDS <username>
    -> Prints the list of the user's friends in alphabetical order.
    -> Prints "Username NOT Found!" if the user does not exist.
    -> Prints "No Friends!" if the user has no friends.

SUGGEST FRIENDS <username> <N>
    -> Suggests up to N people who are friends-of-friends but not already friends.
    -> Suggestions are sorted by:
        1. Highest number of mutual friends (descending),
        2. Alphabetical order on ties.
    -> If N = 0, nothing is printed.
    Prints "Username NOT Found!" if the user does not exist.

DEGREES OF SEPARATION <username1> <username2>
    -> Prints the shortest number of friendship links between the two users.
    -> Used BFS(Breadth First Search) to find the shortest distance.
    -> If no connection exists, prints -1.
    -> Prints "Username NOT Found!" if either username is invalid.

ADD POST <username> "<post content>"
    -> Adds a new post with the current timestamp to the user's AVL tree.
    -> Prints "Username NOT Found!" if the user does not exist.

OUTPUT POSTS <username> <N>
    -> If N = -1 -> prints all posts (newest first).
    -> If N > 0 -> prints the most recent N posts (newest first).
    -> Prints "Username NOT Found!" if the user does not exist.

------------------------------------------------
IMPORTANT NOTES:
------------------------------------------------
-> All usernames are treated case-insensitively (converted to lowercase).
-> Posts are printed in reverse chronological order (newest first).
-> Friends are printed in alphabetical order.


------------------------------------------------
END OF README
