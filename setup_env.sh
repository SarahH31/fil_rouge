#! /bin/bash

#Script shell de configuration de votre environnement
#Il faut l'invoquer par la commande 'source

WHOAMI=$0
if [ $WHOAMI != 'bash' ];
then
	echo "Le script doit être appelé par la commande source setup_env.sh"
	exit 1
fi

PS1='\w\n\$ '
export GNUMAKEFLAGS=--no-print-directory

clear
echo "Préparation de votre environnement"
echo "Pour produire l'exercice tttree : "
echo "choix 1) exécuter la commande <make tttree> depuis la racine"
echo "choix 2) descendre dans le répertoire tttree et exécuter <make>"

if [ $(pwd | wc -w) -gt 1 ]; then 
	echo "!! Attention Attention Attention Attention Attention Attention Attention Attention !!" 
	echo ""
	echo " Vous devriez travailler dans un répertoire dont le chemin ne contient AUCUN espace !"
	echo ""
	echo "!! Attention Attention Attention Attention Attention Attention Attention Attention !!"
	echo ""
fi 
