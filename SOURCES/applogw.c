#include <stdio.h>
#include <syslog.h>

int checkIfFileExists(const char *filename)
{
    FILE *file;
    if(file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){

  int loop;
  loop = atoi(argv[1]);
  
  syslog(LOG_INFO,"$loop: %d\n", loop);

  while(loop--){
    if(!checkIfFileExists("/tmp/enbApplog")) return;
    syslog(LOG_INFO, "Hello, I am Cong, send to SysLog %d", loop);
    sleep(1);
  }
  // remove("/tmp/enbApplog");
  return 0;
}
