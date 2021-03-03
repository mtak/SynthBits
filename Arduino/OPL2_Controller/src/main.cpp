#include <OPL2.h>
#include <midi_instruments.h>
//#include <midi_instruments2_4op.h>
#include <MIDI.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include "instrumentNames.h"

// OLED
#define I2C_ADDRESS 0x3C
#define RST_PIN -1
#define OPTIMIZE_I2C 1
SSD1306AsciiAvrI2c oled;
#define DISPLAYWIDTH 128

// MIDI
MIDI_CREATE_DEFAULT_INSTANCE();
unsigned long lastMidiNote;
unsigned long lastMidiCC;

// OPL2
OPL2 opl2;
float t = 0.0;
#define NUM_OPL2_CHANNELS 9
#define NO_NOTE 255
const byte MIN_NOTE = 24;
const byte MAX_NOTE = 108;
byte oplChannel = 0;
byte oplNotes[NUM_OPL2_CHANNELS] = {
	NO_NOTE, NO_NOTE, NO_NOTE,
	NO_NOTE, NO_NOTE, NO_NOTE,
	NO_NOTE, NO_NOTE, NO_NOTE
};

// Header
void handleMIDINoteOn(byte channel, byte pitch, byte velocity);
void handleMIDINoteOff(byte channel, byte pitch, byte velocity);
void handleMidiCC(byte channel, byte number, byte value);
void playNote(byte note, byte velocity);
void changeInstrument(int instrumentNumber);
void showSplash();
void drawScreen();
void drawIndicators(unsigned long currentMillis);
void handleButtons(unsigned long currentMillis);

const char noteNames[12] = {'C', 'C', 'D', 'D', 'E', 'F', 'F', 'G', 'G', 'A', 'A', 'B'};
int selectedInstrument = 0;

bool setupDone = FALSE;
bool noteIndicatorActive = TRUE;
bool CcIndicatorActive = TRUE;

// Debounce
int leftButtonState;
int leftLastButtonState;
unsigned long leftLastDebounceTime = 0;
int rightButtonState;
int rightLastButtonState;
unsigned long rightLastDebounceTime = 0;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  showSplash();
  oled.setFont(Adafruit5x7);

	opl2.begin();
	opl2.setWaveFormSelect(true);
	for (byte i = 0; i < opl2.getNumChannels(); i ++) {
		opl2.setTremolo   (i, CARRIER, true);
		opl2.setVibrato   (i, CARRIER, true);
		opl2.setMultiplier(i, CARRIER, 0x04);
		opl2.setAttack    (i, CARRIER, 0x0A);
		opl2.setDecay     (i, CARRIER, 0x04);
		opl2.setSustain   (i, CARRIER, 0x02);
		opl2.setRelease   (i, CARRIER, 0x04);
		opl2.setVolume    (i, CARRIER, 0x00);
		opl2.setWaveForm  (i, CARRIER, 0x02);
		opl2.setMaintainSustain(i, CARRIER, false);
	}
  Instrument piano = opl2.loadInstrument(INSTRUMENT_PIANO1);
  for (int i = 0; i < opl2.getNumChannels(); i ++) {
    opl2.setInstrument(i, piano);
    opl2.setBlock(i, 4);
  }

  MIDI.begin(4);
  MIDI.turnThruOff();
  MIDI.setHandleNoteOn(handleMIDINoteOn);
  MIDI.setHandleNoteOff(handleMIDINoteOff);
  MIDI.setHandleControlChange(handleMidiCC);
  lastMidiNote = millis();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

}

void loop() {
  MIDI.read();
  unsigned long currentMillis = millis();

  if (!setupDone && currentMillis > 2000) {
    drawScreen();
    setupDone = TRUE;
  }

  drawIndicators(currentMillis);
  handleButtons(currentMillis);
}

void handleMIDINoteOn(byte channel, byte pitch, byte velocity) {
  oplNotes[oplChannel] = pitch;

  byte note = max(MIN_NOTE, min(pitch, MAX_NOTE));
	byte octave = 1 + (note - 24) / 12;
	note = note % 12;
	opl2.playNote(oplChannel, octave, note);

  oplChannel = (oplChannel + 1) % NUM_OPL2_CHANNELS;

  lastMidiNote = millis();
}

void handleMIDINoteOff(byte channel, byte pitch, byte velocity) {
  for (byte i = 0; i < NUM_OPL2_CHANNELS; i ++) {
		if (oplNotes[i] == pitch) {
			oplNotes[i] = NO_NOTE;
			opl2.setKeyOn(i, false);
		}
	}
}

void changeInstrument(int instrumentNumber) {
  Instrument instr = opl2.loadInstrument(midiInstruments[instrumentNumber]);
  for (int i = 0; i < opl2.getNumChannels(); i ++) {
    opl2.setInstrument(i, instr);
    opl2.setBlock(i, 4);
  }
  drawScreen();
}

void showSplash() {
  oled.clear();
  
  oled.set1X();
  oled.setFont(CalBlk36);
  size_t size = oled.strWidth("TAK");
  oled.setCursor((oled.displayWidth()-size)/2, 1);
  oled.println("TAK");
  oled.setFont(Adafruit5x7);
  size = oled.strWidth("Instruments");
  oled.setCursor((oled.displayWidth()-size)/2, 6);
  oled.println("Instruments");
}

void drawScreen() {
  oled.clear();

  // Instrument name
  oled.set2X();
  char instrumentNameBuffer[10];
  strcpy_P(instrumentNameBuffer, (char *)pgm_read_word(&(instrumentNameTable[selectedInstrument])));

  size_t size = oled.strWidth(instrumentNameBuffer);
  oled.setCursor((oled.displayWidth()-size)/2, 0);
  oled.println(instrumentNameBuffer);

  // ADSR
  oled.set1X();
  int a = opl2.getAttack(0, CARRIER);
  int d = opl2.getDecay(0, CARRIER);
  int s = opl2.getSustain(0, CARRIER);
  int r = opl2.getRelease(0, CARRIER);
  bool t = opl2.getTremolo(0, CARRIER);
  bool v = opl2.getVibrato(0, CARRIER);
  int w = opl2.getWaveForm(0, CARRIER);

  oled.setCursor(0,3);
  oled.print("A: ");
  oled.print(a);

  oled.setCursor(42,3);
  oled.print("D: ");
  oled.print(d);

  oled.setCursor(84,3);
  oled.print("T: ");
  if (t == TRUE)
    oled.print("On ");
  if (t == FALSE)
    oled.print("Off");

  oled.setCursor(0,5);
  oled.print("S: ");
  oled.print(s);

  oled.setCursor(42,5);
  oled.print("R: ");
  oled.print(r);

  oled.setCursor(84,5);
  oled.print("V: ");
  if (v == TRUE)
    oled.print("On ");
  if (v == FALSE)
    oled.print("Off");

  oled.setCursor(0,7);
  oled.print("W: ");
  if (w == 0)
    oled.print("Full");
  if (w == 1)
    oled.print("3/4");
  if (w == 2)
    oled.print("1/2");
  if (w == 3)
    oled.print("1/4");
}

void drawIndicators(unsigned long currentMillis) {
  oled.setCursor(122,0);
  if (!noteIndicatorActive && currentMillis - lastMidiNote < 200) {
    oled.print("N");
    noteIndicatorActive = TRUE;
  } 
  if (noteIndicatorActive && currentMillis - lastMidiNote > 200 ) {
    oled.print(" ");
    noteIndicatorActive = FALSE;
  }
  oled.setCursor(122,1);
  if (!CcIndicatorActive && currentMillis - lastMidiCC < 200) {
    oled.print("C");
    CcIndicatorActive = TRUE;
  } 
  if (CcIndicatorActive && currentMillis - lastMidiCC > 200 ) {
    oled.print(" ");
    CcIndicatorActive = FALSE;
  }
}

void handleMidiCC(byte channel, byte number, byte value) {
  // oled.setCursor(75,7);
  // oled.print(number);
  // oled.setCursor(100,7);
  // oled.print(value);

  // Attack
  if (number == 10) {
    if (value > 0 && value < 16) {
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setAttack(i, CARRIER, value);
      }
      oled.setCursor(0,3);
      oled.print("A:   ");
      oled.setCursor(0,3);
      oled.print("A: ");
      oled.print(value);
    } else {
      if (value >= 16) 
        value = 15;
      if (value == 0)
        value = 1;
      oled.setCursor(0,3);
      oled.print("A: ");
      oled.setInvertMode(TRUE);
      oled.print(value);
      oled.setInvertMode(FALSE);
    }
  }

  // Decay
  if (number == 74) {
    if (value < 16) {
      int opl2value = 15 - value; // Invert parameter
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setDecay(i, CARRIER, opl2value);
      }
      oled.setCursor(42,3);
      oled.print("D:   ");
      oled.setCursor(42,3);
      oled.print("D: ");
      oled.print(value);
    } else {
      if (value >= 16) 
        value = 15;
      oled.setCursor(42,3);
      oled.print("D: ");
      oled.setInvertMode(TRUE);
      oled.print(value);
      oled.setInvertMode(FALSE);
    }
  }

  // Sustain
  if (number == 114) {
    if (value < 16) {
      int opl2value = 15 - value; // Invert parameter
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setSustain(i, CARRIER, opl2value);
      }
      oled.setCursor(0,5);
      oled.print("S:   ");
      oled.setCursor(0,5);
      oled.print("S: ");
      oled.print(value);
    } else {
      if (value >= 16) 
        value = 15;
      if (value == 0)
        value = 1;
      oled.setCursor(0,5);
      oled.print("S: ");
      oled.setInvertMode(TRUE);
      oled.print(value);
      oled.setInvertMode(FALSE);
    }
  }

  // Release
  if (number == 18) {
    if (value < 15) {
      int opl2value = 15 - value; // Invert parameter
      if (opl2value == 15) // Avoid infinite sound
        opl2value = 14;
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setRelease(i, CARRIER, opl2value);
      }
      oled.setCursor(42,5);
      oled.print("R:   ");
      oled.setCursor(42,5);
      oled.print("R: ");
      oled.print(value);
    } else {
      if (value >= 15) 
        value = 14;
      oled.setCursor(42,5);
      oled.print("R: ");
      oled.setInvertMode(TRUE);
      oled.print(value);
      oled.setInvertMode(FALSE);
    }
  }

  // Tremolo
  if (number == 71) {
    if (value < 3) {
      bool enable;
      if (value == 0)
        enable = FALSE;
      if (value > 0)
        enable = TRUE;
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setTremolo(i, CARRIER, enable);
      }
      if (value == 2) {
        opl2.setDeepTremolo(true);
      } else {
        opl2.setDeepTremolo(false);
      }

      oled.setCursor(84,3);
      oled.print("T: ");
      if (value == 2)
        oled.print("On+");
      if (value == 1)
        oled.print("On ");
      if (value == 0)
        oled.print("Off");
    } else {
      if (value >= 3) 
        value = 2;
      oled.setCursor(84,3);
      oled.print("T: ");
      oled.setInvertMode(TRUE);
      if (value == 2)
        oled.print("On+");
      if (value == 0)
        oled.print("Off");
      oled.setInvertMode(FALSE);
    }
  }

  // Vibrato
  if (number == 19) {
    if (value < 3) {
      bool enable;
      if (value == 0)
        enable = FALSE;
      if (value > 0)
        enable = TRUE;
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setVibrato(i, CARRIER, enable);
      }
      if (value == 2) {
        opl2.setDeepVibrato(true);
      } else {
        opl2.setDeepVibrato(false);
      }
      opl2.setDeepVibrato(enable);
      oled.setCursor(84,5);
      oled.print("V: ");
      if (value == 2)
        oled.print("On+");
      if (value == 1)
        oled.print("On ");
      if (value == 0)
        oled.print("Off");
    } else {
      if (value >= 3) 
        value = 2;
      oled.setCursor(84,5);
      oled.print("V: ");
      oled.setInvertMode(TRUE);
      if (value == 2)
        oled.print("On+");
      if (value == 0)
        oled.print("Off");
      oled.setInvertMode(FALSE);
    }
  }

  // Waveform
  if (number == 76) {
    if (value < 4) {
      for (byte i = 0; i < opl2.getNumChannels(); i ++) {
        opl2.setWaveForm(i, CARRIER, value);
      }
      oled.setCursor(0,7);
      oled.print("W:     ");
      oled.setCursor(0,7);
      if (value == 0)
        oled.print("W: Full");
      if (value == 1)
        oled.print("W: 3/4");
      if (value == 2)
        oled.print("W: 1/2");
      if (value == 3)
        oled.print("W: 1/4");
    } else {
      oled.setCursor(0,7);
      oled.print("W:     ");
      oled.setCursor(0,7);
      oled.print("W: ");
      oled.setInvertMode(TRUE);
      oled.print("1/4");
      oled.setInvertMode(FALSE);

    }
  }

  // Instrument selection
  if (number == 16) {
    if (value < 128) {
      selectedInstrument = value;
      changeInstrument(selectedInstrument);
    }
  }

  lastMidiCC = millis();
}

void handleButtons(unsigned long currentMillis) {
    leftButtonState = digitalRead(2);
  if (leftButtonState != leftLastButtonState)
    leftLastDebounceTime = currentMillis;

  if ((currentMillis - leftLastDebounceTime) > 100 ) {
    if (leftButtonState == LOW) {
      if (selectedInstrument > 0) {
        selectedInstrument--;
      }
      changeInstrument(selectedInstrument);
    }
    leftLastButtonState = leftButtonState;
  }

  rightButtonState = digitalRead(3);
  if (rightButtonState != rightLastButtonState)
    rightLastDebounceTime = currentMillis;

  if ((currentMillis - rightLastDebounceTime) > 100 ) {
    if (rightButtonState == LOW) {
      if (selectedInstrument < 127) {
        selectedInstrument++;
      }
      changeInstrument(selectedInstrument);
    }
    rightLastButtonState = rightButtonState;
  }

}
