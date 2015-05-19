#ifndef FACTORIAL_RECURSION_H
#define FACTORIAL_RECURSION_H

#ifndef FACTORIAL_RECURSION_C
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN int fact(int n);
EXTERN int fact_tail(int n, int a)

#endif