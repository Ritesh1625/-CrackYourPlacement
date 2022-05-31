//We use hashing in it. We slide a window and then match the hash value of pattern and text. If it matches, then we check the individual characters.

//Rabin-Karp Algorithm

#include<bits/stdc++.h>
using namespace std;

//d - number of characters in input
#define d 256

/* pat -> pattern
   txt -> text
   q -> A prime number
*/

void search( char pat[], char txt[], int q){
  int M = strlen(pat);
  int N = strlen(txt);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;
  
  //The value of h would be "pow(d, M-1)%q"
  for( i=0; i< M-1; i++)
    h = (h * d) % q;
  
  //Calculating hash value of pattern and text.
  for(i = 0; i < M; i++){
    p=(d*p +pat[i]) %q;
    t=(t*p +txt[i]) %q;
  }
  
  //Slide the pattern over text one by one.
  for ( i=0; i<=N-M; i++)
  {
    // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
    
    if(p == t)
    {
      bool flag = true;
      /* Check for characteristics one by one. */
      for(j=0; j<M ; j++)
      {
        bool flag = true;
        for(j=0; j<M; j++){
          if(txt[i+j] != pat[j])
          {
            flag = false;
            break;
          }
          if(flag)
            cout << i << " ";
       }
        
       //if p==t and pat[0..M-1] = txt[i, i+1, ...i+M-1]
        
       if(i == N-M)
         cout <<"Pattern found at index" << i << endl;
     }
     
     // Calculate hash value for next window of text: Remove
     // leading digit, add trailing digit
     if ( i < N-M )
     {
         t = (d*(t - txt[i]*h) + txt[i+M])%q;
        
         //to convert negative value of t, if t is negative.
       
       if(t<0)
         t=(t+q);
     }
   }  

   int main(){
     char txt[] = "This is the text";
     char pat[] = "is";
     
     int q  = 101; //q is prime number
     
     search(pat, txt, q);
     return 0;
   }
    
    
   
    
    
    
    
    
    
    
        
    
  
  

