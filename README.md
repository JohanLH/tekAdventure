# tekAdventure

Synthaxe ./tekaventure conf/configuration.conf

Fichier de configuration dans le dossier conf.

Synthaxe fichier de config principale:

	 Une regle:

	 ->         [FILE] -> Obligatoire
	 	    	   contient deux types de donnes:
		    	     -name: nom de la map (char *)
			     -path: chemin vers le fichier de configuration secondaire (char *)
			
Syntaxe fichier de config secondaire: 
	Creation d'une nouvelle regle avec ["type"] et fin de cette regle avec [END]
	Commentaire possible avec symbole '#'
	
	Differentes regles principales:
	
	->	    [MAP] -> Obligatoire
		    	  contient un [GRAPH] -> Obligatoire
			  	   contient trois regles: [ROOM] [LINK] [OUT]
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
				 - incre-dim: incrementation du rectangle affichant le sprite (bonus) (int,int)
				 - max: nombre maximum d'incrementation du rectangle (bonus) (int)

	->          [ACTION]
			contient differents arguments:
				 -type: type d'interaction avec l'animation (obligatoire) (char *)
				 -interaction: active animation (default off) (char *)
				 -action: action a faire sur l'objet (char *)
	->	    [OUT]
		       contient les sorties vers d'autres maps
		       		-name: nom de la map venant du fichier de configuration principale (char *)
				-start: debut de la zone de click (int, int)
				-end: fin de la zone de click (int, int)
				-lock: bloque la porte (char *)
				-node: node connecte a la porte (char *,...)
				-object: objet debloquant la porte (char *)