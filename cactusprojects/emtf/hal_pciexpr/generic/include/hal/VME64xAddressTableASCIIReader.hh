#ifndef __VME64xAddressTableASCIIReader
#define __VME64xAddressTableASCIIReader

#error Do not use the VME64xAddressTableASCIIReader anymore! Use the VMEAddressTableASCIIReader instead. The VMEAddressTableASCIIReader now inspects the file extension; If it finds a file ".xml" or ".XML" it interpretes the contents  as a XML AddressTable otherwise as a ASCII Table.

#include <string>

#include "hal/NoSuchFileException.hh"
#include "hal/AddressTableReader.hh"
#include "hal/VME64xHardwareAddress.hh"

namespace HAL {

/**
*
*
*     @short A class to read in an ASCII file with an 
*            AddressTable description.
*
*            The format of the file  must be strictly according to the
*            following  pattern   (lines  starting  with   a  "*"  are 
*            considered as comments) :
*
*            <pre>
*
*            *******************************************************************************************************
*            *     key              space  map  address      mask    read write description
*            ********************************************************************************************************
*            DaqActive              memory  0  00000000    00000001    1    1   This let data flow...
*            BxCount                memory  0  00000000    00000004    1    1   sets the dummy data generator in contineous
*            *                                                                  count mode (100MHz)
*            TriggerSourceSelector  memory  0  00000000    00000018    1    1   00 : selects software trigger
*            *                                                                  01 : selects external trigger
*            *                                                                  10 : selects internal trigger generator
*            *                                                                  11 : no trigger
*            DescriptorFifoCount    memory  0  00000008    000001ff    1    0   number of words currently in the DescriptorFifo
*            Busy                   memory  0  00000008    00010000    1    0   indicates that currently an event is processed
*            TriggerLevelReadback   memory  0  00000008    00020000    1    0   reads back the level of the trigger line
*            *                                                                  ( can be used to check the external trigger )
*            PagesAvailable         memory  0  00000008    00040000    1    0   indicates if there is space for more events
*            DescriptorFifoQUnvalid memory  0  00000008    00080000    1    0   the next read of the DescriptorFifo does NOT give
*            PendingTriggerCounter  memory  0  00000008    ff000000    1    0   number of pending triggers not yet treated
*            *                                                                  valid data (occurs after fifo has been empty)
*            DescriptorFifoCountQ   memory  1  00000000    0000ffff    1    0   read the Descriptorfifo and afterwards increment
*            *                                                                  readpointer
*            EventSize              memory  1  00000008    0000ffff    1    1   size of generated events in bytes
*            *                                
*            resetRui               memory  0  00000020    00000001    0    1   resets the logic of the RUI
*            flushData              memory  0  00000020    00000002    0    1   flushes all data from the RUI (including RAM)
*            Trigger                memory  0  00000020    00000004    0    1   triggers the generation of one event
*            clearDataGenerator     memory  0  00000020    00000008    0    1   clears the counter which generates dummy data
*            FreeRequest            memory  0  00000020    00000010    0    1   request to free one memory block
*            readData               memory  0  00000028    ffffffff    1    0   reads a data word and increment data counter (if not
*            *                                                                  in contineous mode anyway) used by DMA to SDRAM
*            TriggerCounterRate     memory  0  00000030    ffffffff    1    1   number of 10ns intervals between two triggers
*            *************************************************************************************************
*
*            </pre>
*            
*       @see AddressTable, AddressTableInterface            
*    @author Christoph Schwick
* $Revision: 1.1 $
*     $Date: 2007/03/05 18:02:10 $
*
*
**/

class VME64xAddressTableASCIIReader : public AddressTableReader {
public:
  VME64xAddressTableASCIIReader( std::string fileName ) 
    throw (NoSuchFileException,
	   IllegalValueException) ;
};

} /* namespace HAL */

#endif /* __VME64xAddressTableASCIIReader */
