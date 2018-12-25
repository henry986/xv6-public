#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{ 
  char state;
  while(1){
    printf(1, "\nEnter '1' to change scheduling process:\n");
    printf(1, "Enter '2' to show all process state:\n");
    printf(1, "Enter '3' to change process priority:\n");
    printf(1, "Enter '4' to exit:\n");
    scanf(0, "%c", &state);
    
    if(state == '1'){
      char t;
      printf(1, "Please enter 'P' for priority scheduling, 'R' for round robin scheduling: ");
      scanf(0, "%c", &t);
      if(t == 'R'){
        CSP(1);
      }
      if(t == 'P'){
        CSP(2);
      }
    }
    
    if(state == '2'){
      APS();
    }
    
    if(state == '3'){
       int pid, newp;
       printf(1, "Please enter the pid of the process that you want to change priority: ");
       scanf(0, "%d", &pid);
       printf(1, "Please enter the new priority of the process: ");
       scanf(0, "%d", &newp);
       CPP( pid, newp );
    }
    
    if(state == '4'){
      exit();
    }
    
  }
  exit();
}
