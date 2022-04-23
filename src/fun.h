#ifndef __EDFILE_FUN_H__
#define __EDFILE_FUN_H__

extern void print_help();
extern void get_file_name(char *dest_file_name, char *src_file_name);
extern char *read_src_file(unsigned long long int *file_length, char *src_file_name);
extern char *file_text_encrypt(char *src_file_text, unsigned long long int length, unsigned long long int password);
extern void save_file(char *text, unsigned long long int length, char *file_name);
extern char *file_text_decrypt(char *src_file_text, unsigned long long int length, unsigned long long int password);
extern void load_bar();

#endif
