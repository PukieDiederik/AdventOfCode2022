SHELL=/bin/bash

#COLORS
BLACK			= \033[0;30m
RED				= \033[0;31m
GREEN			= \033[0;32m
ORANGE			= \033[0;33m
BLUE			= \033[0;34m
PURPLE			= \033[0;35m
CYAN			= \033[0;36m
GRAY			= \033[0;37m
WHITE			= \033[0;38m
RESET			= \033[0m


ECHO		= echo -e

SRC_DIR		= src/
INP_DIR		= inputs/
FILES		= d1p1.cpp d1p2.cpp \
			  d2p1.cpp d2p2.cpp \
			  d3p1.cpp d3p2.cpp \
			  d4p1.cpp d4p2.cpp \
			  d5p1.cpp d5p2.cpp \
			  d6p1.cpp d6p2.cpp \
			  d7p1.cpp

SRC			= $(addprefix $(SRC_DIR),FILES)
INPUTS		= $(addprefix $(INP_DIR),$(FILES))
NAMES		= $(basename $(FILES))
CXXFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
RUN			= 0


# FUNCTIONS

all: run

%: src/%.cpp
	@$(ECHO) "$(GREEN)>>> compiling $(WHITE)$<$(RESET)"
	@g++ $< $(CXXFLAGS) -o $@

run: $(NAMES)
ifeq ($(RUN), 0)
	@$(foreach x,$(NAMES),$(ECHO) "$(CYAN)Running $(WHITE)$x$(RESET)"; ./$x < $(INP_DIR)$x;)
else
	@$(ECHO) "$(CYAN)Running $(WHITE)$(RUN)$(RESET)"; ./$(RUN) < $(INP_DIR)$(RUN)
endif

clean:
		rm -f $(NAMES)
