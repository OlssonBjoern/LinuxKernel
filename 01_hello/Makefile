# objectfiles that are behind the obj-m variable will be built as kernel modules
obj-m += hello.o 

# Default target, calling a makefile in the folder below where shell uname-r is the currently running kernel
# M=$(PWD) should look for buildable kernel modules in the present working directory
all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
#Clean all compile and generated files
clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)

