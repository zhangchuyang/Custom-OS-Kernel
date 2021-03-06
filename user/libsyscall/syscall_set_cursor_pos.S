/** @file syscall_set_cursor_pos.S
 *
 *  @brief
 *  @author Christopher Wei (cjwei), Aatish Nayak (aatishn)
 *  @bug
 */

#include <syscall_int.h>

.globl set_cursor_pos


set_cursor_pos:
    push %esi      /* save esi */
    mov %esp, %esi  /* copy stack pointer into esi */
    add $8, %esi     /* increment esi by 8 so it points at 1st argument */
    int $SET_CURSOR_POS_INT  /* call trap */
    pop %esi       /* restore esi */
    ret
