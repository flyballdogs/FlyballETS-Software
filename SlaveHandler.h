// SlaveHandler.h

#ifndef _SLAVEHANDLER_h
#define _SLAVEHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include <WebSocketsClient.h>
#include "global.h"
#define CONNECT_CHECK 1000

class SlaveHandlerClass
{
protected:
   IPAddress _RemoteIP;
   bool _bConnected;
   bool _bIAmSlave;
   bool _bSlaveConfigured;
   bool _bWSConnectionStarted;
   bool _bSlaveAnnounced;
   unsigned long _ulLastConnectCheck;
   unsigned long _ulLastSystemDataReceived;
   WebSocketsClient _wsClient;

   void _ConnectRemote();
   void _WsEvent(WStype_t type, uint8_t * payload, size_t length);
   void _SetDisconnected();
   void _AnnounceSlaveIfApplicable();
   void _WsCloseConnection();
   bool _ConnectionNeeded();
   void _TestConnection();
   String _strJsonRaceData;

public:
   void init();
   void loop();
   void configureSlave(IPAddress ipSlaveIP);
   void removeSlave();
   bool slavePresent();
   void resetConnection();
   bool sendToSlave(String strMessage);
   bool GetConnectionStatus();
   String& getSlaveRaceData();
};

extern SlaveHandlerClass SlaveHandler;

#endif

