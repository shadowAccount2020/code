#include <stdio.h>

int main()
{
    FILE *fp = fopen("E:/code/1.C/01FileIO/a.txt","r");
    if(fp == NULL)
    {
        printf("�ļ���ʧ��\n");
        return (-1);
    }

    int ch = fgetc(fp);
    printf("%c\n",ch);

    fclose(fp);
    return 0;
}
