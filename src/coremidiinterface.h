#ifndef COREMIDIINTERFACE_H
#define COREMIDIINTERFACE_H

#include <MIDIServices.h>
#include "midiinterface.h"

class CoreMIDIInterface : public MIDIInterface
{
public:
    CoreMIDIInterface(MIDIEndpointRef endpoint, DirectionFlags flags, QObject *parent = NULL);

private:
    static QString getMidiDeviceName(MIDIEndpointRef endpoint);
};

#endif // COREMIDIINTERFACE_H