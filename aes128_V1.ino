#include "mbedtls/aes.h"

/*
Akarawat.Tommy Verify Encrypt-Decrypt
- Board Lora : ESP32 Dev Module (Traves Gateway Board)
*/
void encrypt(char * plainText, char * key, unsigned char * outputBuffer){
 
  mbedtls_aes_context aes;
 
  mbedtls_aes_init( &aes );
  mbedtls_aes_setkey_enc( &aes, (const unsigned char*) key, strlen(key) * 8 );
  mbedtls_aes_crypt_ecb( &aes, MBEDTLS_AES_ENCRYPT, (const unsigned char*)plainText, outputBuffer);
  mbedtls_aes_free( &aes );
}
 
void decrypt(unsigned char * chipherText, char * key, unsigned char * outputBuffer){
 
  mbedtls_aes_context aes;
 
  mbedtls_aes_init( &aes );
  mbedtls_aes_setkey_dec( &aes, (const unsigned char*) key, strlen(key) * 8 );
  mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_DECRYPT, (const unsigned char*)chipherText, outputBuffer);
  mbedtls_aes_free( &aes );
}
 
void setup() {
 
  Serial.begin(115200);
 
  //กำหนด Keys
  char * key = "&op0-e3UI9@)(*#)";
 
  char *plainText = "Tech tutorials x";
  unsigned char cipherTextOutput[16];//จะต้องกำหนด ขนาดตวามความยาวทั้ง encrypt-decrypt
  unsigned char decipheredTextOutput[16];//จะต้องกำหนด ขนาดตวามความยาวทั้ง encrypt-decrypt
 
  encrypt(plainText, key, cipherTextOutput);
  decrypt(cipherTextOutput, key, decipheredTextOutput);
 
  Serial.println("\nOriginal plain text:");
  Serial.println(plainText);
 
  Serial.println("\nCiphered text:");
  for (int i = 0; i < 16; i++) {
 
    char str[3];
 
    sprintf(str, "%02x", (int)cipherTextOutput[i]);
    Serial.print(str);
  }
 
  Serial.println("\n\nDeciphered text:");
  for (int i = 0; i < 16; i++) {
    Serial.print((char)decipheredTextOutput[i]);
  }
}
 
void loop() {}
