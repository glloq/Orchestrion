//base du code midiHandler.cpp pour les instrument de l'Orchestrion

MidiHandler::MidiHandler(Instrument &instrument) : _instrument(instrument) {
  if (DEBUG) {
    Serial.println("DEBUG : midiHandler--creation");
  } 
}

void MidiHandler::readMidi() {
  midiEventPacket_t midiEvent;
  do {
    midiEvent = MidiUSB.read();
    if (midiEvent.header != 0) {
      processMidiEvent(midiEvent);
    }
  } while (midiEvent.header != 0);
}

void MidiHandler::processMidiEvent(midiEventPacket_t midiEvent) {

  // Si c'est un message SysEx (commence par 0xF0)
  if (midiEvent.byte1 == 0xF0) { // Début de SysEx
    isReceivingSysEx = true;
    sysexIndex = 0;
    sysexBuffer[sysexIndex++] = midiEvent.byte1;
  } else if (isReceivingSysEx) {
    // Continuer à recevoir les données SysEx
    sysexBuffer[sysexIndex++] = midiEvent.byte1;
    sysexBuffer[sysexIndex++] = midiEvent.byte2;
    sysexBuffer[sysexIndex++] = midiEvent.byte3;

    // Si la fin de SysEx est atteinte ( fini par un byte 0xF7), traiter le message complet
    if ( midiEvent.byte1 == 0xF7 || midiEvent.byte2 == 0xF7 || midiEvent.byte3 == 0xF7) || sysexIndex >= SYSEX_BUFFER_SIZE) {
        processSysExMessage();
	isReceivingSysEx=false
    }
  }else{
// on vient traiter tout les autres types de messages midi 
	  
  byte messageType = midiEvent.byte1 & 0xF0;
  byte channel = midiEvent.byte1 & 0x0F;
  byte note = midiEvent.byte2;
  byte velocity = midiEvent.byte3;

  switch (messageType) {
    case 0x90: // Note On
      if (velocity > 0) {
        _instrument.noteOn(note, velocity);
      } else {
        // Note Off
        _instrument.noteOff(note);
      }
      break;
    case 0x80: // Note Off
      _instrument.noteOff(note);
      break;
    case 0xE0: // Pitch Bend
      //int pitchBendValue = (midiEvent.byte3 << 7) | midiEvent.byte2;
      //_instrument.pitchBend(pitchBendValue);
      break;
    case 0xA0: // Channel Pressure (Aftertouch)
      //int channelPressureValue = midiEvent.byte2;
      //_instrument.channelPressure(channelPressureValue);
      break;
    case 0xD0: // Polyphonic Key Pressure
      //int polyKeyPressureValue = midiEvent.byte3;
      //_instrument.polyKeyPressure(polyKeyPressureValue);
      break;
    case 0xB0: // Control Change
      processControlChange(note, velocity);
    
  }
 }
}
/*------------------------------------------------------------------
--------------        process Control Change             ----------
------------------------------------------------------------------*/
void MidiHandler::processControlChange(byte controller, byte value) {
  // Add logic for handling Control Change messages
  // You can switch on the controller value to handle specific control changes
  switch (controller) {
    case 1:
    case 91:
    case 92:
    case 94: // Gestion du vibrato
      //_instrument.modulationWheel(value);
      break;
	case 2: // breath controller
	 //_instrument.breathController(value);
      break;
	case 5: // Portamento Time
      //_instrument.portamento(value);
      break;  
    case 7: // Volume
      //_instrument.volumeControl(value);
      break;
	case 11: // Expression
      //_instrument.expression(value);
     break;
	case 74: // Brightness
      //_instrument.brightness(value);
     break;
    case 121: // Réinitialisation de tous les contrôleurs
      //_instrument.reset();
      break;
    case 123: // Désactiver toutes les notes
      //_instrument.mute();
      break;
  }
}

void MidiHandler::processSysExMessage() {
  //  Traitement d'une ID Request
  if (sysexBuffer[1] == 0x7E && sysexBuffer[3] == 0x06 && sysexBuffer[4] == 0x01) {
    if (DEBUG) {Serial.println("ID Request Received, sending Identity Reply...");}
    sendIdentityReply();
  }

  // Réinitialiser le buffer et l'index après le traitement
  sysexIndex = 0;
}

void MidiHandler::sendIdentityReply() {
//code a adapter en fonction des caracteristiques de l'instrument => a voir dans InstrumentID.md 
	
    byte identityReply[] = {
    0xF0,        // Start SysEx
    0x7E,        // Non-real time
    0x00,        // Device ID => code de l'instrument utilisé
    0x06,        // Sub-ID1 (General Information)
    0x02,        // Sub-ID2 (Identity Reply)
    0x7D,        // Manufacturer ID (7D is for educational or experimental use)
    0x7D,	 // previent que c'est un instrument compatible avec l'interface Orchestrion (j'ai mis ca a 7D mais il faut voir si ca ne pose pas de problemes) 
    55,	 	 // premiere note midi de l'instrument
    16,	 	 // Nombre de note jouable de l'instrument 
    0,  	 // Type de gamme de l'intrument => 0 chromatique, 1 diatonique 
    1,		 //nombre de note jouable en meme temps (de 1 a 128) 
    2, 120,  // delais d'action de l'instrument (temps pour jouer une note) => dans ce cas 2 x 120 ms
    0xF7         // End SysEx
  };

  // Envoi du message SysEx via MIDIUSB
  for (int i = 0; i < sizeof(identityReply); i += 3) {
    midiEventPacket_t midiEvent = {0x04, identityReply[i], identityReply[i + 1], identityReply[i + 2]};
    MidiUSB.sendMIDI(midiEvent);
  }
  MidiUSB.flush();  // Envoyer tout le message
}
