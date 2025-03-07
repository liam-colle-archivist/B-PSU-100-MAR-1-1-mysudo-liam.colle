/*
** EPITECH PROJECT, 2025
** parser
** File description:
** my_sudo
*/

#include "my_passwd.h"
#include "my_shadow.h"
#include "my_group.h"
#include "utils.h"

#ifndef PARSER_PASSWD_H
    #define PARSER_PASSWD_H

passwd_t *get_passwd(void *ref, bool_t (*cmp_f)(passwd_t *, void *));
bool_t passwd_user(passwd_t *pwds, void *user);
bool_t passwd_uid(passwd_t *pwds, void *uid_p);

#endif

#ifndef PARSER_SHADOW_H
    #define PARSER_SHADOW_H

shadow_t *get_shadow(void *ref, bool_t (*cmp_f)(shadow_t *, void *));
bool_t shadow_user(shadow_t *shdw, void *user);

#endif

#ifndef PARSER_GROUP_H
    #define PARSER_GROUP_H

group_t *get_group(void *ref, bool_t (*cmp_f)(group_t *, void *));
bool_t group_user(group_t *pwds, void *user);
bool_t group_gid(group_t *pwds, void *gid_p);

#endif
