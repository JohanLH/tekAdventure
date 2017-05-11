# tekAdventure

Fichier de configuration dans le dossier conf.

Syntaxe:
	Creation d'une nouvelle regle avec ["type"] et fin de cette regle avec [END]
	Differentes regles principales:
	
	->	    [MAP] -> Obligatoire
		    	  contient un [GRAPH] -> Obligatoire
			  	   contient trois regles: [NODE] [LINK] [OUT]
			  contient une image -> obligatoire
			  
	->	    [PLAYER] -> obligatoire
		    	  contient un [SPAWN] -> Obligatoire
			  	   regle compose du node de depart
		          contient une [IMAGE] -> Obligatoire
			  
	->	    [OBJECT] -> bonus
		          contient une [ANIMATION] -> bonus
			  	   contient deux regles: [ACTION] -> obligatoire [IMAGE] -> bonus
		    	  contient une [IMAGE] -> Obligatoire

	Autres regles:

	->	    [IMAGE]
			contient differents arguments:
				 - name: chemin vers l'image a charger (Obligatoire) (char *)
				 - dimension: rectangle de l'image a charger (bonus) (int,int)
				 - scale: scale de l'image a charger (bonus) (float)
				 - position: position de l'image a charger (bonus) (int,int)
				 - incre-scale: incrementation du scale de l'image (bonus) (float,float)
				 - music: chemin vers la music a charger (bonus) (char *)

	->          [ACTION]
			contient differents arguments:
				 -type: type d'interaction avec l'animation (obligatoire) (char *)
				 -interaction: active animation (default off) (char *)
