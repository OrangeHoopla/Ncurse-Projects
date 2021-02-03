#include <iostream> 
#include <ncurses.h>
using namespace std; 
  
int main(int argc, char** argv) 
{ 
    cout << "You have entered " << argc 
         << " arguments:" << "\n"; 
  
    cout << argv[1] << endl;
  
    return 0; 
} 