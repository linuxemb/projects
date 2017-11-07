
#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <execinfo.h>
#include <syslog.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>

/* Saved pointers to the real init, main, destructor, and runtime loader destructor functions. */
static void (*real_init)(void);
static int (*real_main)(int, char **, char **);

static void sig(int s)
{
    std::string filename = "/proc/"+std::to_string(getpid())+"/cmdline";
    printf("filename = %s\n", filename.c_str());
    FILE* file = fopen(filename.c_str(), "r");
    if (file == NULL)
        printf("opening failed\n");
    int len = 2048;
    char *name = new char[len + 1];
    fseek(file, 0, SEEK_SET);
    fgets(name, len, file);
    name[len] = 0;
    fclose(file);
	printf("Signal catched appdi(%d, %s) %d: \n", getpid(), name, s);
	syslog( LOG_INFO, "Signal catched appid (%d, %s) %d: \n", getpid(), name, s);
    delete []name;

	void* trace[20];
	int tn = backtrace(trace, 20);
    int fd= open("log.txt", O_CREAT|O_WRONLY, 0666);
	if (fd < 0 )
    {
        printf("cant open file \n");
        exit(-1);
    }   
 
        printf("fd = open file %d\n" , fd);
    backtrace_symbols_fd(trace, tn, fd);
    //backtrace_symbols_fd(trace, tn, 1);
	if (s == SIGSEGV)
	    close(fd);
        exit(-1);
}

static void wrapper_init(void)
{

	signal(SIGSEGV, sig);

	/* Call the real init function */
	if(real_init)
		real_init();
}


static int wrapper_main(int argc, char **argv, char **envp)
{
	/* Call the real main function.
	 * Note that we call our reimplementation of the exit function,
	 * because returning would cause glibc to invoke the exit_group
	 * system call, which is not allowed in SECCOMP mode. */
	int n;
	n = real_main(argc, argv, envp);
	exit(n);
	return -1;
}


extern "C" int __libc_start_main (
	int (*main)(int, char **, char **),
	int argc,
	char ** ubp_av,
	void (*init)(void),
	void (*fini)(void),
	void (*rtld_fini)(void),
	void (* stack_end)) //__attribute__ ((visibility ("default")))
{
	void *libc_handle;

	int (*real_libc_start_main)(
		int (*main) (int, char **, char **),
		int argc,
		char ** ubp_av,
		void (*init)(void),
		void (*fini)(void),
		void (*rtld_fini)(void),
		void (* stack_end));

	/* Save pointers to the real init, main, destructor, and runtime loader destructor functions */
	real_init = init;
	real_main = main;


	/* get a pointer to the real __libc_start_main function */
	libc_handle = dlopen("libc.so.6", RTLD_LOCAL | RTLD_LAZY);
	if (libc_handle == 0) {
		exit(-1);
	}

	*(void **) (&real_libc_start_main) = dlsym(libc_handle, "__libc_start_main");


	/* Delegate to the real __libc_start_main, but provide our
	 * wrapper init, main, destructor, and runtime loader destructor functions */
	return real_libc_start_main(wrapper_main, argc, ubp_av,
		wrapper_init, fini, rtld_fini, stack_end);
}
