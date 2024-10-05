# Nom de l'exécutable
EXEC = Trie

# Les fichiers sources
SRCS = main.c

# Les fichiers objets (générés à partir des fichiers sources)
OBJS = $(SRCS:.c=.o)

# Le compilateur
CC = gcc

# Les options de compilation
CFLAGS = -Wall -Wextra -g

# Règle par défaut : compilation de l'exécutable
all: $(EXEC)

# Règle pour compiler l'exécutable
$(EXEC): $(OBJS)
	$(CC) -o $@ $^

# Règle pour compiler les fichiers objets à partir des fichiers sources
%.o: %.c structures.h
	$(CC) $(CFLAGS) -c $<

# Nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

# Tout nettoyer, y compris les fichiers temporaires de sauvegarde
mrproper: clean
	rm -f *~
