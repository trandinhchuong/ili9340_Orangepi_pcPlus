
###############################################################
#author  : chuongtd4
#date    : 25/02/2019
#########################chuongtd4#############################

LGB             = ./scrip/logo.sh

RPI_SYS_DIR	=
TOOLS_DIR	=
NAME_MODULE	= Orange_pi
CXX		= arm-linux-gnueabihf-g++
CC		= arm-linux-gnueabihf-gcc
#CXX=g++
#CC=gcc
OBJ_DIR		= build_$(NAME_MODULE)

OPTIMIZE_OPTION	=	-O3
WARNNING_OPTION	+=	-Werror -Wno-error -W -Wno-missing-field-initializers \
                        -Wno-pointer-to-int-cast

-include source/app/Makefile.mk
-include source/driver/Makefile.mk


CFLAGS	+= -I/usr/local/include
CFLAGS	+= -I/usr/include

CXXFLAGS	+= -I/usr/local/include
CXXFLAGS	+= -I/usr/include

# CXX compiler option
CXXFLAGS	+= $(API_OPTION)        \
		$(OPTIMIZE_OPTION)	\
		$(WARNNING_OPTION)	\
                -std=c++11		\
		-Wall			\
		-Winline		\
		-pipe			\
		-lwiringPi              \
                -DSPI -DWPI             \
                -DSPI_DEBUG             \
                -Os                     \
                -pthread                \


# Library pathsls

LDFLAGS	+= -L/usr/local/lib
LDFLAGS	+= -L/usr/include
LDFLAGS += -L$(PWD)/lib
LDFLAGS	+= -Wl,-Map=$(OBJ_DIR)/$(NAME_MODULE).map


#Library libss
LDLIBS	+=	-lpthread		\
                -lrt			\
                -lm			\

all: create $(OBJ_DIR)/$(NAME_MODULE)
create:
	@bash ./scrip/logo.sh
	@echo mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@echo ---------- c++ compiler ----------
	@echo CXX $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
$(OBJ_DIR)/%.o: %.cxx
	@echo ---------- cxx compiler ----------
	@echo CXX $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
$(OBJ_DIR)/%.o: %.c
	@echo ---------- c   compiler ----------
	@echo CXX $<
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/$(NAME_MODULE): $(OBJ)
	@echo ------- START LINK PROJECT --------
	@echo $(CXX) -o $@ $^ $(CXXFLAGS)
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

.PHONY: copy
copy:
	@echo ------------ copy app ------------
#	cp source/CameraControllerApi/resources/./* $(OBJ_DIR)/
	scp -r build_Orange_pi/Orange_pi root@192.168.1.14:/root

.PHONY: flash
flash:
	@sudo LD_LIBRARY_PATH=/usr/local/lib/ $(OBJ_DIR)/$(NAME_MODULE)

.PHONY: debug
debug:
	sudo gdb $(OBJ_DIR)/$(NAME_MODULE)

.PHONY: install
install:
	cp $(OBJ_DIR)/$(NAME_MODULE) /usr/local/bin

.PHONY: clean
clean:
	@echo rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)



