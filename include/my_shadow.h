/*
** EPITECH PROJECT, 2025
** my_shadow
** File description:
** my_sudo
*/

#ifndef MY_SHADOW
    #define MY_SHADOW

    #define SHADOW_FILE "/etc/shadow"

/*
* Shadow Authentication Mode
*/
typedef enum {
    /*
    * Shadow -> Unknown Authentication Mode
    * Matches: ???
    */
    SHADOW_AUTHUNKN = -1,

    /*
    * Shadow -> Password Authentication Mode
    * Matches: "<hash>"
    */
    SHADOW_PASSAUTH,

    /*
    * Shadow -> No Password Authentication Mode
    * Matches: "!"
    */
    SHADOW_NOPASSAUTH,

    /*
    * Shadow -> Password Authentication Mode
    * Matches: "!!"
    */
    SHADOW_NOPASSREQ,

    /*
    * Shadow -> Password Authentication Mode
    * Matches: "*"
    */
    SHADOW_NOAUTH,
} shadow_authm_t;

typedef struct {
    char *namp;
    char *pwdp;
    long int lstchg;
    long int min;
    long int max;
    long int warn;
    long int inact;
    long int expire;
    unsigned long int flag;
} shadow_t;

shadow_t *create_shadow(void);
void clear_shadow(shadow_t *shadow);
void free_shadow(shadow_t *shadow);

shadow_authm_t shadow_auth_mode(char *conf_buff);

#endif
