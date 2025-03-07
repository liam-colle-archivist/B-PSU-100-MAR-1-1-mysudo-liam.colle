/*
** EPITECH PROJECT, 2025
** my_passwd
** File description:
** my_sudo
*/

#ifndef MY_PASSWD
    #define MY_PASSWD

    #define PASSWD_FILE "/etc/passwd"
    #define DEFAULT_GUID -1

typedef struct {
    char *user;
    char *password;
    int uid;
    int gid;
    char *description;
    char *home;
    char *default_shell;
} passwd_t;

passwd_t *create_passwd(void);
void clear_passwd(passwd_t *passwd);
void free_passwd(passwd_t *passwd);

#endif
