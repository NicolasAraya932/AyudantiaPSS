void (*) (int) sa_handler; /*  SIG_DFL o SIG_IGN */
sigset_t sa_mask;   /*  signals to block in sa_handler */
int sa_flags;     /*  signal action modifiers */