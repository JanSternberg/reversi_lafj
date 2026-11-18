TARGET = sysprak-client


# all c-files which we want to compile
SRC = main.c

# basic orders
all: 
		gcc $(SRC) -o $(TARGET) -Wall -Wextra -Werror
		@echo "Compiling successful! Start with ./$(TARGET)



# clean up everything
clean:
	rm -f $(TARGET)