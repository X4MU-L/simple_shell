#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/wait.h>

extern char **environ;
char *copy_WO_space(char *str, char *args);
char *_strcopy(char *dest, const char *src);
size_t count_words(const char *str);
char **create_array(int words, const char *cmd_path, const char *args);
char **getcmd_array(const char *cmd_path, const char *cmd_args, const char *cmd);
char *locate_cmd(const char *filename);
char *join_paths(char sep, const char *path, const char *filename);
int file_exits(const char *path);
char *_strdup(const char *str);
char *_getenv(const char *name);
char *get_cmd(const char *cmd);
void free_array(char **array);
int is_exit(char *cmd);
size_t _strlen(const char *str);

#endif
