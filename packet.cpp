#include <iostream>
#include <fstream>

using namespace std;

#include "OrderedList.cpp"

// Reads a series of packets, formats them into a message, and
// outputs the message.

class Packet {
public:
    static const int PACKET_SIZE = 6;  // Number of characters in a packet
    // including null ('\0') terminator,
    // but excluding the key (1st char in each line).
    int position;              // (Key) Packet's position w/in message
    char body[PACKET_SIZE];    // Characters in the packet
    
    int getKey () const
    { return position; }   // Returns the key field
};

//--------------------------------------------------------------------

int main()
{
    ifstream messageFile ("message.dat");   // Message file
    OrderedList<Packet,int> message;        // Message
    Packet currPacket;                      // Message packet
    int j;                                  // Loop variable
    
    // Read in the packets
    currPacket.body[Packet::PACKET_SIZE-1] = '\0';
    while ( messageFile >> currPacket.position )
    {
        // currPacket.position has just been read from the input
        
        messageFile.getline(currPacket.body,Packet::PACKET_SIZE,'\n');
        // currPacket.body has just been read from the input
        
        // I/O problem could happen during getline.
        // Check that I/O problem-free before inserting packet.
        if ( messageFile )
            // Insert currPacket into the OrderedList
        /****** YOUR CODE HERE ******/
        {
            message.insert();
        }
    }
    
    
    
    // Output the message packet-by-packet.
    
    
    
    return 0;
}

