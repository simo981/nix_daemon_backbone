#if !defined MAIN_H
#define MAIN_H

#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/syslog.h>
#include <linux/close_range.h>

void sigterm_handler(int);
void sighup_handler(int);

#define SYSEQ(name, sc, eq)                                                    \
  if (sc == eq) {                                                              \
    perror(#name);                                                             \
    exit(errno);                                                               \
  }

#define SYSNEQ(name, sc, neq)                                                  \
  if (sc != neq) {                                                             \
    perror(#name);                                                             \
    exit(errno);                                                               \
  }

#define SYSEQV(name, v, sc, eq)                                                \
  if ((v = sc) == eq) {                                                        \
    perror(#name);                                                             \
    exit(errno);                                                               \
  }

#define IFG(v, gv, act)                                                        \
  if (v > gv) {                                                                \
    act;                                                                       \
  }

#endif
