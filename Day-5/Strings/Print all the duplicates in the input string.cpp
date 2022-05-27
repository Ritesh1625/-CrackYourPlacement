//Using Hashing or Maps.

//Maps - 
#include<bits/stdc++.h>
using namespace std;
void printDups(string str)
{
  map<char,int> count;
  for(int i = 0; i< str.length(); i++){
    count[str[i]]++;
  }
  
  for(auto it: count){
    if(it.second > 1){
      cout << it.first << ", count = " << it.second << "\n";
    } 
  }
}

 int main()
 {
   string str = "test string";
   printDups(str);
   return 0;
 }


// Hashing-
#include<iostream>
using namespace std;
#define NO_OF_CHARS 256

class solution{
  public:
  void fillCharCounts(char *str, int *count)
    {
        int i;
        for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    }
 
    /* Print duplicates present in the passed string */
    void printDups(char *str)
    {
         
        // Create an array of size 256 and fill
        // count of every character in it
        int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
        
        fillCharCounts(str, count);
        
        // Print characters having count more than 0
        int i;
        for (i = 0; i < NO_OF_CHARS; i++)
        if(count[i] > 1)
            printf("%c, count = %d \n", i, count[i]);
 
        free(count);
    }
};
 
int main()
{
    solution s ;
    char str[] = "test string";
    s.printDups(str);
    
    return 0;
}
