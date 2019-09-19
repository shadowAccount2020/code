#include <time.h>
#include <stdio.h>

int main1()
{
    char *ch;
    time_t t;
    t = time(NULL);
    ch = ctime(&t);//使用ctime也要使用上边的time
    //printf("%d\n",t);
    printf("%s\n",ch);
    return 0;
}

int main()
{
    struct tm *tt;
    time_t t;
    t = time(NULL);
    tt = localtime(&t);                                                                                                                  
    printf("%d\n",tt->tm_year);
    return 0;
}
