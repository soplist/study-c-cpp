CC=g++
EXEC=emis
OBJS=main.o managerview_console_impl.o  manager.o \
managerservice_impl.o tools.o \
managerdao_file_impl.o employee.o \
department.o
all:$(EXEC)
$(EXEC):$(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f $(EXEC) $(OBJS)

