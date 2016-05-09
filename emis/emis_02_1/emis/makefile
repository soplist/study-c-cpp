CC=g++
EXEC=emis
OBJS=main.o managerview_console_impl.o  manager.o \
managerservice_impl.o
all:$(EXEC)
$(EXEC):$(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f $(EXEC) $(OBJS)

