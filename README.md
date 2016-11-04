# nRF24L01_MiRF_Sniffer_Serial_Leonardo

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
