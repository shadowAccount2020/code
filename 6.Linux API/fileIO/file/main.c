/*************************************************************************                                                               
    > File Name: file.c
    > Author: 孟超
    > Mail: 2205101365@qq.com 
    > Created Time: 2019年09月19日 星期四 21时11分58秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("./a.txt",O_RDONLY);
    if(fd<0)
        _exit(-1);
    printf("%d\n",fd);  
        
    char buf[100] = {0};
    read(fd,&buf,100);
    printf("%s\n",buf);


    close(fd);
    return 0;
}
