/** @file page_directory.h
 *  @brief Specifies interface for page directory
 *
 *  @author Aatish Nayak (aatishn)
 *  @author Christopher Wei (cjwei)
 *  @bug No known bugs.
 */

#ifndef _PAGE_DIRECTORY_H_
#define _PAGE_DIRECTORY_H_

/* PAGE SIZE */
#include <x86/page.h>
/* Constants */
#include <constants.h>
#include <stdint.h>
#include <mem_section.h>

#define PRESENT_FLAG_BIT 0
#define RW_FLAG_BIT 1
#define MODE_FLAG_BIT 2
#define WRITE_THROUGH_FLAG_BIT 3
#define GLOBAL_FLAG_BIT 8

/* p - SET implies page is present, UNSET implies page is unpresent
 * rw - SET implies page is read writable, UNSET implies read only
 * md - SET implies user, UNSET implies supervisor
 * glb - SET implies global, UNSET implies local
 */
#define NEW_FLAGS(p,rw,md,glb) ((p << PRESENT_FLAG_BIT) | (rw << RW_FLAG_BIT)\
    | (md << MODE_FLAG_BIT) | (glb << GLOBAL_FLAG_BIT))

/* User RO */
#define PDE_FLAG_DEFAULT (NEW_FLAGS(SET, UNSET, SET, DONT_CARE))
/* User RO */
#define PTE_FLAG_DEFAULT (NEW_FLAGS(SET, UNSET, SET, UNSET))


#define PD_SIZE PAGE_SIZE
#define PD_NUM_ENTRIES (PD_SIZE / sizeof(uint32_t))

#define PT_SIZE PAGE_SIZE
#define PT_NUM_ENTRIES (PT_SIZE / sizeof(uint32_t))


#define IS_PAGE_ALIGNED(a) (a % PAGE_SIZE == 0)

#define DIV_ROUND_UP(num, den) ((num + den -1) / den)
#define PAGE_ALIGN_UP(addr) (PAGE_SIZE * DIV_ROUND_UP(addr, PAGE_SIZE))
#define PAGE_ALIGN_DOWN(addr) (PAGE_SIZE * (addr / PAGE_SIZE))



typedef struct page_directory {
    uint32_t *directory;
} page_directory_t;

int pd_init(page_directory_t *pd);
int pd_create_mapping(page_directory_t *pd, int32_t v_addr, uint32_t p_addr, uint32_t pte_flags, uint32_t pde_flags);
int pd_entry_present(uint32_t v);
int pd_copy(page_directory_t *pd_dest, page_directory_t *pd_src);
int pd_map_sections(page_directory_t *pd, mem_section_t *secs,
        uint32_t num_secs);
void *pd_get_base_addr(page_directory_t *pd);
#endif /* _PAGE_DIRECTORY_H_ */


