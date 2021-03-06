/** @file test_yield.c
 *  @author Christopher Wei
 *  @brief tests yielding to specific thread
 *  @public yes
 *  @for p2 p3
 *  @covers
 *  @status done
 */

#include <simics.h>
#include <stdio.h>
#include <syscall.h>

int main()
{
    int parenttid = gettid();
    int id = fork();
    while(1){
        if (id == 0) {
            yield(parenttid);
            printf("Hello from child!");
        } else {
            int ret = yield(id);
            printf("Parent yield ret: %d", ret);
        }
    }
}
