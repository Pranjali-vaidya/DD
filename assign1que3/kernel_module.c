#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/sched/task.h>


static int __init desd_init(void) {
    struct list_head list;
    pr_info("%s: desd_init() called.\n", THIS_MODULE->name);
    // problem: traverse kernel process list to display info of all processes
    list_for_each_entry(trav, &THIS_MODULE.list, list) {
        pr_info("%s: pid=%d, cmd=%s\n", THIS_MODULE->list, trav->pid, trav->comm);
    }
    return 0;
}

static void __exit desd_exit(void) {
    pr_info("%s: desd_exit() called.\n", THIS_MODULE->name);
    // problem: display info about current process
    pr_info("%s: current process pid=%d, cmd=%s\n", THIS_MODULE->list, current->pid, current->comm);
    // current macro internally calls get_current(), which returns "task_struct" ptr to current task/process
}

module_init(desd_init);
module_exit(desd_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel module demo of Display Process list (Job Queue)");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");