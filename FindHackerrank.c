#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
At HackerRank, we always want to find out how popular we are getting every day and have scraped conversations from popular sites. Each conversation fits in 1 line and there are N such conversations. Each conversation has at most 1 word that says hackerrank (all in lowercase). We would like you to help us figure out whether a conversation:

Starts with hackerrank
Ends with hackerrank
Start and ends with hackerrank
Input Format

First line of the input contains N, N lines follow. From the second line onwards, each line contains a set of words W separated by a single space

Constraints

1 <= N <= 10
1 <= W <= 100
All the characters in W are lowercase alphabet characters. If C is the count of the characters in W, then 1 <= C <= 20

Output Format

For every line,

Print 1 if the conversation starts with hackerrank
Print 2 if the conversation ends with hackerrank
Print 0 if the conversation starts and ends with hackerrank
Print -1 if none of the above.
*/
int main()
{
    char c = 0;
    int numOfLines=0;
    while(c = getchar())
    {
        if (c == '\0' || c == '\n')
            break;    
        numOfLines = 10 * numOfLines + atoi(&c);
    }
    int i=0;
    int ans=-1;
    char lineArray[numOfLines][2048];
    for(i=0;i<numOfLines;i++)
    {
        if(fgets(lineArray[i],2048,stdin) != NULL )
        {
            ans=-1;
            char* substr; 
            int end=0;
            if(strcmp(lineArray[i],"hackerrank\n") == 0)
            {
                ans=0;
            }
            else
            {    
                substr = strstr(lineArray[i],"hackerrank");
                if( substr != NULL && *substr == lineArray[i][0] )
                {
                    // start there.  
                    ans=1;
                    lineArray[i][0]='1';
                    char* newstr=NULL;
                    while( newstr = strstr(lineArray[i],"hackerrank") )
                    {
                        if( *(newstr+10) == '\0' || *(newstr+10) == '\n')
                        {
                            ans=0;
                            break;    
                        }
                        else
                        {
                            *newstr='1';    
                        }
                    }
                }
                else if( substr != NULL && ( *(substr+10) == '\0' || *(substr+10) == '\n') )
                {
                    ans=2;
                }
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
