#include <stdio.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>

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

void app_start(int loop){
  syslog(LOG_INFO, "AppLog: start");
  FILE *file;
  if(file = fopen("/tmp/enbApplog", "w"))
  {
    fclose(file);
    syslog(LOG_INFO, "AppLog: start successful");
    pid_t pid;
    pid=fork();
    if(pid==0){
      char snum[16];
      sprintf(snum, "%d", loop);
      execl("/usr/local/bin/applogw", "applogw", snum, NULL);
    }
  }else{
    syslog(LOG_INFO, "AppLog: start Failed");
  }
}

void app_stop(){
  syslog(LOG_INFO, "AppLog: stop");
  remove("/tmp/enbApplog");
}

void app_restart(int loop){
  app_stop();
  app_start(loop);
}

void app_status(){
  if(checkIfFileExists("/tmp/enbApplog")){
    syslog(LOG_INFO, "AppLog: Enabled");
  }else{
    syslog(LOG_INFO, "AppLog: Disabled");
  }
}

void printSysLog(){
  syslog(LOG_INFO, "Hello, I am Cong, send to SysLog");
}

int main(int argc, char *argv[]){

  int loop;
  // loop=argc;
  loop = atoi(argv[2]);
  // #define BUFSIZE 80
  // char evar[BUFSIZE];
  // char *envvar = "EVAR";

  // // Make sure envar actually exists
  // if(!getenv(envvar)){
  //     syslog(LOG_INFO, "The environment variable %s was not found.\n", envvar);
  //     return 0;
  // }
  // // Make sure the buffer is large enough to
  // // hold the environment variable value. 
  // if(snprintf(evar, BUFSIZE, "%s", getenv(envvar)) >= BUFSIZE){
  //     syslog(LOG_INFO, "BUFSIZE of %d was too small. Aborting\n", BUFSIZE);
  //     return 0;
  // }

  // loop = atoi(evar);
  
  // syslog(LOG_INFO, "Starting Applog service $EVAR = %d", loop);
  // if(loop<1){
  //   syslog(LOG_INFO, "$EVAR < 1, Starting Applog service is unable %d", loop);
  //   return 0;
  // }

  printf("acts: %s\n", argv[1]);

  if(!strcmp(argv[1], "start")){
    app_start(loop);
  }else if(!strcmp(argv[1], "stop")){
    app_stop();
  }else if(!strcmp(argv[1], "restart")){
    app_restart(loop);
  }else if(!strcmp(argv[1], "status")){
    app_status();
  }
  
  return 0;
}
