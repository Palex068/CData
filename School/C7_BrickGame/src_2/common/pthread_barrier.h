#include <stddef.h>

/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union {
  char __size[__SIZEOF_PTHREAD_BARRIER_T];
  long int __align;
} pthread_barrier_t;

typedef union {
  char __size[__SIZEOF_PTHREAD_BARRIERATTR_T];
  int __align;
} pthread_barrierattr_t;

/* Functions to handle barriers.  */

/* Initialize BARRIER with the attributes in ATTR.  The barrier is
   opened when COUNT waiters arrived.  */
extern int pthread_barrier_init(pthread_barrier_t *__restrict __barrier,
                                const pthread_barrierattr_t *__restrict __attr,
                                unsigned int __count) __THROW __nonnull((1));

/* Destroy a previously dynamically initialized barrier BARRIER.  */
extern int pthread_barrier_destroy(pthread_barrier_t *__barrier) __THROW
    __nonnull((1));

/* Wait on barrier BARRIER.  */
extern int pthread_barrier_wait(pthread_barrier_t *__barrier) __THROWNL
    __nonnull((1));

/* Initialize barrier attribute ATTR.  */
extern int pthread_barrierattr_init(pthread_barrierattr_t *__attr) __THROW
    __nonnull((1));

/* Destroy previously dynamically initialized barrier attribute ATTR.  */
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr) __THROW
    __nonnull((1));

/* Get the process-shared flag of the barrier attribute ATTR.  */
extern int pthread_barrierattr_getpshared(
    const pthread_barrierattr_t *__restrict __attr,
    int *__restrict __pshared) __THROW __nonnull((1, 2));

/* Set the process-shared flag of the barrier attribute ATTR.  */
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr,
                                          int __pshared) __THROW __nonnull((1));
