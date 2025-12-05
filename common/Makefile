-include config.mk

SHELL:=/usr/bin/bash
CC?=g++
LINK?=g++
CFLAGS?=-Wall -Wextra -O0 -ggdb3 $(EXTRA_CFLAGS)
RM?=rm -rf

ifeq ($(SRCS),)
$(error "$$SRCS must be defined")
endif

ifeq ($(APP),)
$(error "$$APP must be defined")
endif

OBJS=$(SRCS:.cc=.o)

$(APP): $(OBJS)
	$(LINK) $^ -o $@

%.o: %.cc
	$(CC) -c -o $@ $(CFLAGS) $<

PHONY+=clean
clean:
	$(RM) $(OBJS) $(APP)
