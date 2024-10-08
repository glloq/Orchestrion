#ifndef MIDIHANDLER_H
#define MIDIHANDLER_H
/***********************************************************************************************
----------------------------    MIDI messages handler    ---------------------------------------
************************************************************************************************
Regoupe tout les fonctions qui peuvent etre utilisé dans le projet orchestrion => servira de base aux instruments
plus de fonctions peuvent etre décommenté dans le fichier midiHandler.cpp et ajouté ici 
Les fonctions devrons etre ajouté a l'objet Intrument pour pouvoir etre appelé depuis le midiHandler
 ************************************************************************************************/

#include <MIDIUSB.h> 
#include "instrument.h" // objet instrument utilisé
#include "settings.h" // reglages de reponses des parametres de l'instrument 

#define SYSEX_MAX_SIZE 12 // taille du buffer max pour les messages sysEx

class MidiHandler {
public:
  MidiHandler(Instrument &instrument);
  void readMidi();

private:
  Instrument &_instrument;
  void processMidiEvent(midiEventPacket_t midiEvent);

// la suite est pour le traitement des messages sysEx ( ID Request uniquement ) 
  void processSysExMessage();
  void sendIdentityReply();
  bool isReceivingSysEx = false;
  byte sysexBuffer[SYSEX_MAX_SIZE];
  int sysexIndex = 0;
};
#endif // MIDIHANDLER_H
