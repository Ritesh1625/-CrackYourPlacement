// Source- https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/ 

/*
Boyer Moore is a combination of the following two approaches. 
1) Bad Character Heuristic 
2) Good Suffix Heuristic

The Boyer Moore algorithm starts matching from the last character of the pattern.

-> Bad Character Heuristic
The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until – 
1) The mismatch becomes a match
2) Pattern P moves past the mismatched character.

*/

Code:
/* C++ Program for Bad Character Heuristic of Boyer
Moore String Matching Algorithm */
#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic( string str, int size,
						int badchar[NO_OF_CHARS])
{
	int i;

	// Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence
	// of a character
	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search(string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];

	/* Fill the bad character array by calling
	the preprocessing function badCharHeuristic()
	for given pattern */
	badCharHeuristic(pat, m, badchar);

	int s = 0; // s is shift of the pattern with
				// respect to text
	while(s <= (n - m))
	{
		int j = m - 1;

		/* Keep reducing index j of pattern while
		characters of pattern and text are
		matching at this shift s */
		while(j >= 0 && pat[j] == txt[s + j])
			j--;

		/* If the pattern is present at current
		shift, then index j will become -1 after
		the above loop */
		if (j < 0)
		{
			cout << "pattern occurs at shift = " << s << endl;

			/* Shift the pattern so that the next
			character in text aligns with the last
			occurrence of it in pattern.
			The condition s+m < n is necessary for
			the case when pattern occurs at the end
			of text */
			s += (s + m < n)? m-badchar[txt[s + m]] : 1;

		}

		else
			/* Shift the pattern so that the bad character
			in text aligns with the last occurrence of
			it in pattern. The max function is used to
			make sure that we get a positive shift.
			We may get a negative shift if the last
			occurrence of bad character in pattern
			is on the right side of the current
			character. */
			s += max(1, j - badchar[txt[s + j]]);
	}
}

/* Driver code */
int main()
{
	string txt= "ABAAABCD";
	string pat = "ABC";
	search(txt, pat);
	return 0;
}

/* 
2. Good Suffix Heuristic-

Let t be substring of text T which is matched with substring of pattern P. Now we shift pattern until :
1) Another occurrence of t in P matched with t in T.
2) A prefix of P, which matches with suffix of t
3) P moves past t

*/

/* C program for Boyer Moore Algorithm with
Good Suffix heuristic to find pattern in
given text string */

#include <stdio.h>
#include <string.h>

// preprocessing for strong good suffix rule
void preprocess_strong_suffix(int *shift, int *bpos,
								char *pat, int m)
{
	// m is the length of pattern
	int i=m, j=m+1;
	bpos[i]=j;

	while(i>0)
	{
		/*if character at position i-1 is not equivalent to
		character at j-1, then continue searching to right
		of the pattern for border */
		while(j<=m && pat[i-1] != pat[j-1])
		{
			/* the character preceding the occurrence of t in
			pattern P is different than the mismatching character in P,
			we stop skipping the occurrences and shift the pattern
			from i to j */
			if (shift[j]==0)
				shift[j] = j-i;

			//Update the position of next border
			j = bpos[j];
		}
		/* p[i-1] matched with p[j-1], border is found.
		store the beginning position of border */
		i--;j--;
		bpos[i] = j;
	}
}

//Preprocessing for case 2
void preprocess_case2(int *shift, int *bpos,
					char *pat, int m)
{
	int i, j;
	j = bpos[0];
	for(i=0; i<=m; i++)
	{
		/* set the border position of the first character of the pattern
		to all indices in array shift having shift[i] = 0 */
		if(shift[i]==0)
			shift[i] = j;

		/* suffix becomes shorter than bpos[0], use the position of
		next widest border as value of j */
		if (i==j)
			j = bpos[j];
	}
}

/*Search for a pattern in given text using
Boyer Moore algorithm with Good suffix rule */
void search(char *text, char *pat)
{
	// s is shift of the pattern with respect to text
	int s=0, j;
	int m = strlen(pat);
	int n = strlen(text);

	int bpos[m+1], shift[m+1];

	//initialize all occurrence of shift to 0
	for(int i=0;i<m+1;i++) shift[i]=0;

	//do preprocessing
	preprocess_strong_suffix(shift, bpos, pat, m);
	preprocess_case2(shift, bpos, pat, m);

	while(s <= n-m)
	{

		j = m-1;

		/* Keep reducing index j of pattern while characters of
			pattern and text are matching at this shift s*/
		while(j >= 0 && pat[j] == text[s+j])
			j--;

		/* If the pattern is present at the current shift, then index j
			will become -1 after the above loop */
		if (j<0)
		{
			printf("pattern occurs at shift = %d\n", s);
			s += shift[0];
		}
		else
			/*pat[i] != pat[s+j] so shift the pattern
			shift[j+1] times */
			s += shift[j+1];
	}

}

//Driver
int main()
{
	char text[] = "ABAAAABAACD";
	char pat[] = "ABA";
	search(text, pat);
	return 0;
}

