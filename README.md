# Orchestrion - Projet de création d'un orchestre électronique

Le projet Orchestrion consiste en la création d'un orchestre électronique composé d'une variété d'instruments acoustiques, reproduits électroniquement à l'aide de microcontrôleurs Arduino, de moteurs, d'électroaimants et de servomoteurs.

L'orchestre électronique sera capable de reproduire la sonorité d'un orchestre complet, y compris les instruments à cordes frottées et à cordes pincées, les instruments à vents, les instruments à percussion et à clavier. La construction des instruments se fera à l'aide de l'impression 3D et de planches de bois, et chaque instrument sera équipé d'électronique pour contrôler les mouvements des cordes, des membranes et des clapets nécessaires pour produire les sons.

Ce dépôt GitHub regroupe les explications générales du projet, y compris l'interface Raspberry Pi, l'actionneur MIDI Arduino, les choix de matériaux et différents électroaimants, servomoteurs, électronique de puissance, etc.

Chaque type d'instrument aura un lien vers son propre dépôt pour l'instrument contenant les plans, fichiers et tutoriels spécifiques à chaque instrument.
Composition de l'orchestre électronique

## L'orchestre électronique est composé des types d'instruments suivants :

   - Instruments à cordes frottées : violon, alto, violoncelle, contrebasse.
   - Instruments à cordes pincées : harpe, guitare, mandoline.
   - Instruments à vents : flûte, piccolo, clarinette, hautbois, cor anglais, basson, saxophone, trompette, cornet, cor d'harmonie, trombone, tuba, orgue, harmonica, accordéon.
  -  Instruments à percussion : timbales, xylophone, marimba, vibraphone, glockenspiel, cymbales, gongs, triangle, tambourin, castagnettes, carillon.
  -  Instruments à clavier : piano, orgue, accordéon, harmonium.

## Contrôle de l'orchestre électronique

L'orchestre électronique peut être contrôlé à l'aide d'un ordinateur connecté à un microcontrôleur Arduino à l'aide de la bibliothèque MidiUSB.h. L'utilisateur peut sélectionner un fichier MIDI et assigner les différents canaux à chaque instrument. Le contrôle peut être effectué via une interface Web MIDI et envoyé via USB. Pour ce faire, un Raspberry Pi avec un shield peut être utilisé pour ajouter des ports USB supplémentaires.

# Contributions

Les contributions au projet sont les bienvenues. Les utilisateurs sont encouragés à soumettre des suggestions, des améliorations et des ajouts de nouvelles fonctionnalités. Les contributions doivent être soumises sous la forme de pull requests.

