#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
