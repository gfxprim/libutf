LIB=utf
LIB_SRCS=libutfconv.c cp1250.c cp1251.c cp1252.c cp1253.c cp1254.c cp1255.c\
         cp1256.c cp1257.c cp1258.c libutfcase.c
LIB_HEADERS=$(wildcard *.h)

libutfcase.c: data/CaseFolding.txt data/gen_casefold.py
	./data/gen_casefold.py > libutfcase.c

CLEAN+=libutfcase.c
