#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main(int argc, char *argv[])
{
	for (; ; )
	{
		int cmd = 0;
		print_help();
		printf("\033[01;34m");
		printf("==> 请输入选项: ");
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			char dest_file[200]             = "";
			char src_file[200]              = "";
			unsigned long long file_length  = 0;
			char *read                      = NULL;
			unsigned long long int password = 0;
			get_file_name(dest_file, src_file);
			read = read_src_file(&file_length, src_file);
			printf("==> 请输入秘钥 (纯数字): ");
			scanf("%llu", &password);
			read = file_text_encrypt(read, file_length, password);
			load_bar();
			save_file(read, file_length, dest_file);
		}
		else if (cmd == 2)
		{
			char dest_file[200]             = "";
			char src_file[200]              = "";
			unsigned long long file_length  = 0;
			char *read                      = NULL;
			unsigned long long int password = 0;
			get_file_name(dest_file, src_file);
			read = read_src_file(&file_length, src_file);
			printf("==> 请输入秘钥 (纯数字): ");
			scanf("%llu", &password);
			read = file_text_decrypt(read, file_length, password);
			load_bar();
			save_file(read, file_length, dest_file);
		}
		else if (cmd == 3)
		{
			printf("=^> 再见  欢迎下次使用\033[00m\n");
			break;
		}
		else
		{
			printf("=!> 没有此选项! \n");
		}
	}
	return 0;
}
