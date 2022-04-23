#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fun.h"

#define ECS "#=====EDFILE_CHECK_STRING=====#"

void print_help()
{
	printf("\033[01;33m===$> [1] 加密文件\n");
	printf("===$> [2] 解密文件\n");
	printf("===$> [3] 退出程序\033[0m\n");
}

void get_file_name(char *dest_file_name, char *src_file_name)
{
	printf("==> 请输入源文件的名称: ");
	scanf("%s", src_file_name);
	printf("==> 请输入目的文件的名称: ");
	scanf("%s", dest_file_name);
	return;
}

char *read_src_file(unsigned long long *file_length, char *src_file_name)
{
	char *data = NULL;
	FILE *fp;
	fp = fopen(src_file_name, "r");
	if (fp == NULL)
	{
		perror("fopen");
		return NULL;
	}
	fseek(fp, 0, 2);
	*file_length = ftell(fp);
	rewind(fp);
	data = (char *) calloc(1, *file_length);
	if (NULL == data)
	{
		perror("calloc");
		return NULL;
	}
	fread(data, *file_length, 1, fp);
	fclose(fp);
	strcat(data, ECS);
	return data;
}

char *file_text_encrypt(char *src_file_text, unsigned long long int length, unsigned long long int password)
{
	char *data               = NULL;
	unsigned long long int i = 0;
	for (i = 0; i < length; i++)
	{
		src_file_text[i] += password;
	}
	return src_file_text;
}

void save_file(char *text, unsigned long long int length, char *file_name)
{	
	char *data = NULL;
	FILE *fp;
	fp = fopen(file_name, "w");
	if (NULL == fp)
	{
		perror("fp");
		return;
	}
	fwrite(text, length, 1, fp);
	fclose(fp);
	if (text != NULL)
	{
		free(text);
		text = NULL;
	}
	return;
}

char *file_text_decrypt(char *src_file_text, unsigned long long int length, unsigned long long int password)
{
	char *data               = NULL;
	unsigned long long int i = 0;
	for (i = 0; i < length; i++)
	{
		src_file_text[i] -= password;
	}
	return src_file_text;
}

void load_bar()
{
	int i         = 0;
	char bar[102] = { 0 };
	printf("\033[?25l加载中... 请稍后\n");
	while (i <= 50)
	{
		printf("[\033[01;31m%-50s\033[01;34m] [\033[01;32m%3d%%\033[01;34m]\r", bar, i * 2);
		usleep(70000);
		bar[i++] = '=';
		bar[i] = '\0';
	}
	printf("\033[?25h\n");
}
