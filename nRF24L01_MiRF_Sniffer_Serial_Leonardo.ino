/**
 *  nRF24L01 Sniffer/ Serial Loger primariamente para uso c/ MetaRobot: https://garoa.net.br/wiki/Meta_Robot
 *  baseado lib Mirf e examples 
 *  envia pela serial dados recebidos
 *  
 *  - 1o byte deve conter número de bytes válidos à receber
 *  - r = reseta indo pro setup
 * 
 * Pins:
 * Hardware SPI (Arduino UNO/ PRO)
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 * 
 * Hardware SPI (Arduino Leonardo)
 * MISO -> 14
 * MOSI -> 16
 * SCK -> 15
 * 
 * Configurable:
 * CE -> 8
 * CSN -> 7
 * 
 *
 *  by Marcelo Campos - Garoa HC
 *  Rev.0 - Nov16
 *  Download e revisões: https://github.com/marcelocampos
 */



#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>


void setup()
{
  Serial.begin(115200);

  delay(100);
  
  // while (!Serial);  // para o Leonardo, aguarda serial disponibilizar

  Mirf.spi = &MirfHardwareSpi;  // Set the SPI Driver.

  Mirf.init();                  // Setup pins / SPI.
  
  // Configure reciving address. 
  Mirf.setRADDR((byte *)"serv1");
  
  // Set the payload length to sizeof(unsigned long) the
  // payload on client and server must be the same.   
  Mirf.payload = 0x20;
  Mirf.channel = 18;

  byte regSetup = B00100110;
  Mirf.configRegister(RF_SETUP, regSetup);
   
  Mirf.config();

  Serial.print("[Sniffer Init, Payload: ");
  Serial.print(Mirf.payload);
  Serial.print(", Ch: ");
  Serial.println(Mirf.channel);


  byte rf_setup_read = 0;
  Mirf.readRegister( RF_SETUP, &rf_setup_read, sizeof(rf_setup_read) );
  
  if ( rf_setup_read == regSetup )
  {
    Serial.println("[Radio Ok]"); 
  }
  else
  {
    Serial.println("[Radio FAIL]");
  }

  Serial.println("[Press. 'r' p/ Reset]");
  Serial.println("Listening..."); 

  
}

void loop()
{
  byte data[Mirf.payload];

  if ( Serial.available() )
  {
    Serial_Analiza();
  }

  if(!Mirf.isSending() && Mirf.dataReady())
  {
    // flush radio buffer
    //    for (int i = 0; i < Mirf.payload; i++)
    //      data[i] = 0;
      
    Mirf.getData(data);

    // data[0] contém número de bytes recebidos
    for(int i=1; i<(data[0]);i++)
      Serial.write(data[i]);

  }
}

void Serial_Analiza()
{
  if(Serial.read() == 'r') 
  {
    Serial.println("[Reseting ...]"); 
    setup();
  }  
}






