/**
 Author      : tejas
 Description : multi threaded file copy; 
               input file into output file

               Basic Testing done
**/
 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
 
#define BUF_SIZE  8*1024
#define NUM_THREADS 8

void* copy_file( void* op_file);

const char * ip_file = "test_file";
const char * op_file = "./test_file_copy";


int main(int argc, char* argv[]) {   
    
    // char * ip_file = "test_file";
    // char * op_file = "test_folder/test_file";

    pthread_t threads[NUM_THREADS];
    const char* messg = "Thread1 ";
    int ret[NUM_THREADS];
    int list_fd[NUM_THREADS];    /* Input and output file descriptors */
    int thData[NUM_THREADS];
        
    for (int i = 0; i < NUM_THREADS; i++) {
        thData[i] = i;
        ret[i] = pthread_create(&threads[i], NULL, copy_file, (void*)&thData[i]);
        if(ret[i]){
            fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[i]);
            exit(EXIT_FAILURE);
        }
    } 


    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);        
    }
    
    return (EXIT_SUCCESS);
}

void* copy_file(void* thData)
{
    int th_num = *(int *)thData;
    printf("%d th number\n", th_num);

    char buffer[BUF_SIZE];      /* Character buffer */
    size_t read_in, wr_out;   

    /* Create output file descriptor */
    int output_fd = open(op_file, O_WRONLY | O_CREAT, 0644);
    if(output_fd == -1){
        perror("Failed to open output file \n");
        goto thread_done;
    }

    int input_fd = open(ip_file, O_RDONLY);
    if (input_fd == -1) {
        perror("Failed to open input file \n");
        goto thread_done;
    }

    int at_location = th_num * BUF_SIZE;
    printf("thread entered 	%lx \n",pthread_self()); 
    while(1){

        //printf("thread running  	%x \n",pthread_self()); 
        if(lseek(input_fd, at_location, SEEK_SET) < 0) 
            goto thread_done;

        read_in = read(input_fd, &buffer, BUF_SIZE);  
        if (read_in <= 0) {
            printf("DONE\n");
            break;
        }

        //printf("0%d -- %s", th_num, buffer);

        //if(
        lseek(output_fd, at_location, SEEK_SET);
        // < 0) //{
        wr_out = write(output_fd, &buffer, (ssize_t)read_in);
        if(wr_out != read_in){
            perror("write");   
            goto thread_done;
        }
        // }
        at_location += (NUM_THREADS * BUF_SIZE);
    }
    
    thread_done:
    close(output_fd);
    close(input_fd);
    printf("thread exiting 	%lx  %d \n",pthread_self(),getpid()); 
}
