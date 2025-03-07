/*
** EPITECH PROJECT, 2025
** my_group
** File description:
** my_sudo
*/

#ifndef MY_GROUP
    #define MY_GROUP

    #define GROUP_FILE "/etc/group"

typedef struct {
    char *name;
    char *pwdp;
    int gid;
    char *users;
} group_t;

group_t *create_group(void);
void clear_group(group_t *group);
void free_group(group_t *group);

#endif
