/** @file dispatcher.h
 *  @brief defines the interface for the dispatcher
 *  @author Christopher Wei (cjwei)
 *  @author Aatish Nayak (aatishn)
 *  @bug No known bugs
 */


#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <tcb.h>

void initial_mode_switch(tcb_t *tcb);
void initial_mode_switch_asm(tcb_t tcb);
void save_context(tcb_t *tcb);

void restore_context(uint32_t new_esp);

uint32_t context_switch_safe(uint32_t old_esp, int target_tid);
uint32_t context_switch(uint32_t old_esp, int target_tid);


#endif /* _DISPATCHER_H_ */

