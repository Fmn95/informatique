# Programme a creer
PROG = project
# Fichiers sources
SRC = adopter.c ajouter.c day_clean.c get_current_year.c inv_age_asc.c main.c rechercher.c utils.c
# compile et execute
all : $(PROG)
	./$(PROG)

# compilation 
$(PROG) : $(SRC) includes.h
	gcc -Wall -o $(PROG) $(SRC)

# nettoyage
clean :
	rm -f $(PROG)