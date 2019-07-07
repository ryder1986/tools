#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>
#define BFSZ 200
static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;
static char timebuf[BFSZ];
void fill_time()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    memset(timebuf,0,BFSZ);
    snprintf(timebuf,200,"%ld:%ld",tv.tv_sec,tv.tv_usec);
    printf("gettimeofday tv_sec is %ld, usec is %ld\n",tv.tv_sec,tv.tv_usec);
}
void prtline(char *msg,char *time , char *file_name ,  int line_no, char *fun_name,char thread_id  )
{
    printf("%s[%s][%s:%d][%s][thread_id:%d]\n",msg,time,file_name,line_no,fun_name,thread_id);
    fflush(stdout);
}

int main()
{
    printf("Hello World!\n");
    pthread_mutex_lock(&lock);
    fill_time();
    printf("%s\n",timebuf);
    prtline("test msg",timebuf,__FILE__,__LINE__,__FUNCTION__,pthread_self());
    pthread_mutex_unlock(&lock);

    return 0;
}
