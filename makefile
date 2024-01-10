TARGETS=$(shell ls -d tttree)
CLEANTARGETS=$(foreach dir,$(TARGETS),clean_$(dir))

all: 
	@echo "Veuillez choisir une cible parmi : $(TARGETS)"
	@echo "Les exécutables seront produits dans les sous-répertoires correspondants"
	@echo "N'oubliez pas d'exécuter la commande source setup_env.sh"

.PHONY: $(TARGETS)
$(TARGETS) :
	@echo Execution de make $@ :
	@cd $@; make

$(CLEANTARGETS) : 
	@echo Execution de clean $(subst clean_,,$@) :
	@cd $(subst clean_,,$@); make clean

clean: $(CLEANTARGETS)





































































tout: 
	@echo "Vous n'avez pas autre chose à faire que chercher des easter eggs dans un makefile ?"	

toutout: $(TARGETS)
