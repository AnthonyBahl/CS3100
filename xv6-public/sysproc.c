#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_incMagic(void)
{
  int magicinc;

  if(argint(0, &magicinc)<0) {
    return -1;  // failed to get the parameter, return failure
  }

    if(magicinc !=0){
      pushcli();  // disable interrupts so we only change one cpu
      mycpu()->magic = mycpu()->magic + magicinc;
      popcli(); // enable interrupts
    }
    return 0;
}

int sys_getMagic(void)
{
  int magicnum = 0;
  pushcli(); // disable interrupts
  magicnum = mycpu()->magic;
  popcli(); // enable interrupts
  return magicnum;
}

int sys_getProcName(void)
{
  cprintf(myproc()->name);
  return 0;
}

int sys_modProcName(void)
{
  char *newname;

  if( argstr(0, &newname)<0)  //didn't get a parameter from stack
    return -1;
  safestrcpy(myproc()->name, newname, 16);

  // use safestrcpy to copy the parameter into the process struct
  return 0;
}