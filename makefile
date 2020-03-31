# Author: Ammar Shahin
# Date:   31/3/2020

############################### Variables #######################################

######### change The File Names here ########
_DEPS =                           #The includes[.h and .hpp]
_OBJ  = HelloProgram.o
_EXC  = app       
#################################################################################
 
CC = g++
CFLAGS = -I$(IDIR)

IDIR = .\inc
ODIR = .\obj
LDIR = .\lib
SDIR = .\src

LIBS = -lm

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ  = $(patsubst %,$(ODIR)/%,$(_OBJ))


#******************************* Rules *******************************
all: git clean printStartMsg app running sizeOfProg
	
sizeOfProg: 
	@echo -------------Final Statics: -------------
	size $(_EXC)
printStartMsg: 
	@echo -------------Building...-------------

app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

git:
	@echo -------------Quick Saving...-------------
	git add .
	git commit -a -m "Quick Save" 

running:
	@echo -------------running...-------------
	@$(_EXC)

$(ODIR)/%.o: $(SDIR)/%.c++ $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	@echo -------------Cleaning...-------------
	del *.exe $(ODIR).\*.o