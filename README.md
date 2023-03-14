# Presentation 

Un Orchestrion est un instrument de musique mécanique complexe qui reproduit la sonorité d'un orchestre complet. Il peut comporter une grande variété d'instruments et nous alons adapter cet ancient systeme afin de le rendre connecté et modulaire, c'est a dire permettre de brancher plusieurs instruments 

## Voici les types d'instruments que l'on peut trouver dans un Orchestrion, classés par catégorie :
chaque instruments listé ci dessous est voué a etre retiré/adapté/combiné avec un autre si necessaire.

### Les instruments à cordes frotté :
- Violons
- Alto
- Violoncelle
- Contrebasse
   
### Les instruments à cordes pincé :
- Harpe
- Guitare acoustique 
- Gutare basse
- Mandoline

### Les instruments à vent :
- Flûte
- Piccolo
- Clarinette
- Hautbois
- Cor anglais
- Basson
- Saxophone
- Trompette
- Cornet
- Cor d'harmonie
- Trombone
- Tuba
- Orgue
- Accordéon
- Harmonium

### Les instruments à percussion :

- Vibraphone
- Marimba
- Glockenspiel
- Xylophone
- Carillon

- Timbales
- Cymbales
- Gongs
- Triangle
- Tambourin
- Castagnettes

- Piano
   
 

## Objectif de ce projet :
 Je cherche a utiliser des arduino / raspberry (ou autre version compatible)  pour jouer des fichiers midi sur differents instruments.
 l'idée est d'utiliser un serveur pour faire tourner WEBMIDI et d'envoyer les differents cannaux midi aux instrument selectionné par le biais de cables usb (peut etre meme wifi à l'avenir) 
 
 #### Contraintes :
 - penser à la securité electrique dans la conception :
   - Garder un faible voltage pour la securité (12 a 24V) 
   - fusible/disjoncteur adapté au systeme
   - diametres des cables adapté a la puissance
   - temperature electronique ( arete l'instrument et alume lad led erreur par exemple) 
-Il faut utiliser des electroaimants de faible puissance
 
 ## Etats du projet :
 je suis dans un stade en mix entre R&D et prototypage de quelques intruments que je vais ajouter en lien dans la liste ci dessus au fur et a mesure que j'avance.
 je vais presenter la version "parfaite" pour chaque instrument (gestion vélocité, pitch bend, volume, etc ...) mais je vais bien sur rester sur une version plus simplifié pour tester les differentes parties et garder un son correct avant tout !
Pour chaque typed'instrument je vais presenter des schemas ou modelisations 3d des idées mecanique ou electromecanique
 
