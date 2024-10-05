# Interface de controle du systeme 
 ce fichiers regroupe les differentes parties pour l'interface de controle des instruments.

# Partie Controleur host et interfaces 

l'objectif est d'avoir un systeme qui joue les fichiers midi le plus simplement possible sur les instruments connecté.  
idealement je souhaite faire fonctionner le systeme depuis un raspberry pi avec une interface tactile.

il faudrait utiliser un hub usb avec une alimentation isolé pour permettre de connecter plusieurs instruments 

il faut permettre plusieurs actions sur l'interface de controle :

- gestion des fichiers midi
  - uploader un fichier midi
  - selectionner un fichier midi
  - supprimer le fichier selectionné
  - creer un dossier
  - deplacer le fichier selectionné dans un dossier
    
- gestion de la lecture du fichier midi 
  - afficher les instruments utilisé dans le fichier midi
  - fait l'association automatique des intruments utilisé dans le fichier midi et les instruments connecté
  - permettre de selectionner un autre type d'instrument connecté comme sortie pour le chanel du fichier midi (et enregistrer le choix pour ce fichier ?)
  - envoi les messages midi a chaque instrument selectionné avec les delais adapté de chaque instrument

- reconnaitre et lister les instruments connecté
  - recuperer le type d'instrument
  - recuperer le delais pour activation
  - les informations sur les notes jouables (premiere note midi, nombre de note jouable, type de gamme utilisé, nombre de corde etc..)


