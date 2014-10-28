EXEC1:=secant
EXEC2:=newton1
EXEC3:=newton2
SRC1:=$(wildcard *t.c)
SRC2:=$(wildcard *1.c)
SRC3:=$(wildcard *2.c)
OBJ1:=$(patsubst %.c,%.o,$(SRC1))
OBJ2:=$(patsubst %.c,%.o,$(SRC2))
OBJ3:=$(patsubst %.c,%.o,$(SRC3))


CC:=icc
CFLAGS:=
LDFLAGS:= # -L$$TACC_MKL_LIB 
LDLIBS:= # -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread


$all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(OBJ1)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
$(EXEC2): $(OBJ2)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
$(EXEC3): $(OBJ3)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	$(RM) $(EXEC1) $(EXEC2) $(EXEC3) $(OBJ) *.o



