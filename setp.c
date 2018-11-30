#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{

  int pid = atoi ( argv[1] );
  int priority = atoi ( argv[2] );
  
  CPP( pid, priority );
  
  exit();
}
