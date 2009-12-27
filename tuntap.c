/**
 A simple program that reads bytes from a tun/tap device and dumps them to the dumpfile. (and sends them out to the network.)
 it's a primitive local traffic sniffer.

 tun/tap kext must be loaded. 
	sudo kextload /Library/Extensions/tun.kext
	sudo kextload /Library/Extensions/tap.kext
  http://tuntaposx.sourceforge.net/
 
 specifing /dev/tap0 in DEVICE_BSDPATH will give you the tap0 network device which will receive ethernet traffic.
 /dev/tun0 will give you the tun0 network device which will receive IP traffic. (no full ethernet frames)
  
 after uid 0 running this programm you have to:
 sudo ifconfig tun0 up 10.0.0.1
 
 now if you have running local ssh you could ssh 10.0.0.1 and your ssh traffic would be logged to disk. (how useful!)
 
*/


#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>

#define BUFFER_SIZE 1501
#define DEVICE_BSDPATH "/dev/tun0"

int tunFD = 0;


FILE *foutDump = 0;
unsigned char *dumpBuffer = 0;

int main (int argc, char *argv[])
{
	tunFD = open (DEVICE_BSDPATH, O_RDWR | O_FSYNC);
	
	foutDump = fopen("out.hex","a+");

	dumpBuffer = (unsigned char*)malloc(BUFFER_SIZE);
	memset(dumpBuffer, 0x00, BUFFER_SIZE);
	int bytesRead = 0;

	while (1) 
	{
		bytesRead = read (tunFD, dumpBuffer, BUFFER_SIZE);
		
		if (bytesRead > 0)
		{	
			printf ("read %i bytes\n", bytesRead);
			fwrite (dumpBuffer,1, bytesRead,foutDump);
			fclose(foutDump);
			foutDump = fopen("out.hex","a+");
			
			write (tunFD, dumpBuffer, bytesRead);
		}

		memset(dumpBuffer,0x00,BUFFER_SIZE);
	}

	close(tunFD);

	return 0;
}

