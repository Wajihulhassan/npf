CC = gcc -g
CFLAGS = -g -O2 -fPIC
LIBS = -lfl -luuid
LEX = flex
YACC = bison

OBJS = slog.o proxy

all: slog.a slog.o proxy format

#####################################
#   PROXY
#####################################

.c.o:
	$(CC) $(CFLAGS) -c $< $(LIB)

slog.a: $(OBJS)
	$(AR) rcs slog.a $(OBJS)
	@echo [-] Syncing static library
	sync

slog.o: slog.h slog.c

net_helpers.o: net_helpers.h net_helpers.c

proxy: proxy.c slog.o net_helpers.o
	$(CC) $(CFLAGS) -o proxy proxy.c slog.o net_helpers.o ${LIBS}

proxy_unix: proxy_unix.c slog.o net_helpers.o
	$(CC) $(CFLAGS) -o proxy_unix proxy_unix.c slog.o net_helpers.o ${LIBS}


#####################################
#   SQL PARSER
#####################################

format:	sql.tab.o sql.o adlist.o format.o sql.c sql.tab.h sql.l sql.y
	${CC} -o sqlprov format.o sql.tab.o sql.o adlist.o ${LIBS}

format.o:CFLAGS+= -D__FORMAT__
format.o:format.c format.h

sql.tab.o:CFLAGS += -DYYDEBUG

sql.tab.c sql.tab.h:	sql.y
	${YACC} -vd sql.y

sql.c:	sql.l
	${LEX} -o $@ $<

sql.o: sql.c sql.tab.h

.PHONY: clean

clean:
	rm -rf slog.a $(OBJS) *.log sqlprov  sql.tab.c sql.tab.h sql.c sql.tab.o sql.o *.o sql.output format_file

.SUFFIXES:	.l .y .c