#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *message, char *key, int message_len) {
for (int i = 0; i < message_len; i++) {
message[i] = message[i] ^ key[i];
}
}

void decrypt(char *ciphertext, char *key, int message_len) {
encrypt(ciphertext, key, message_len);
}

int main() {
char message[] = "secret message";
char key[] = "key";
int message_len = strlen(message);
int key_len = strlen(key);

// Pad the key to match the length of the message
for (int i = key_len; i < message_len; i++) {
key[i % key_len] = key[i % key_len];
}

encrypt(message, key, message_len);
printf("Encrypted message: %s\n", message);

decrypt(message, key, message_len);
printf("Decrypted message: %s\n", message);

return 0;
}
