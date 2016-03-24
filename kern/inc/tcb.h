/** @file tcb.h
 *
 */

#ifndef _TCB_H_
#define _TCB_H_

/* page directory include */
#include <page_directory.h>
/* frame manager include */
#include <frame_manager.h>

#include <pcb.h>

/* possible tcb statuses */
#define UNINIT 0
#define RUNNABLE 1
#define WAITING 2
#define ZOMBIE 3
#define RUNNING 4


typedef struct tcb{

    int tid;

    int status;

    pcb_t *pcb;

    uint32_t *k_stack_bot;
    uint32_t *orig_k_stack;
    uint32_t *tmp_k_stack;

} tcb_t;

int tcb_init(tcb_t *tcb, int tid, pcb_t *pcb, uint32_t *regs);
int tcb_destroy(tcb_t *tcb);
int tcb_gettid(tcb_t *tcb, int *tid);

#endif /* _TCB_H_ */
