#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void ile istedi�imiz komutlar� k�t�phanemize ekliyoruz sifrele komutu ile dosyam�z� kayd�rma y�ntemi sayesinde �ifreliyoruz
void sifrele(char *metin, int anahtar) {
    int i;
    for (i = 0; metin[i] != '\0'; i++) {
        metin[i] = metin[i] + anahtar;
    }
}

//  �ifre ��zme algoritmas�
void sifreCoz(char *sifreliMetin, int anahtar) {
    int i;
    for (i = 0; sifreliMetin[i] != '\0'; i++) {
        sifreliMetin[i] = sifreliMetin[i] - anahtar;
    }
}

int main() {
    char dosyaAdi[] = "input_1.txt";
    char orijinalMetin[1000];
    char sifreliMetin[1000];

    // Dosyadan metni okuyarak �ifrelenecek metni al�r�z
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    // T�m metni bir seferde okuma t�m metni tek seferde okuyarak dosyadaki t�m verilerin �ifrelenip geri ��z�lmesini sa�l�yoruz
    fseek(dosya, 0, SEEK_END);
    long dosyaUzunlugu = ftell(dosya);
    fseek(dosya, 0, SEEK_SET);

    fread(orijinalMetin, 1, dosyaUzunlugu, dosya);
    fclose(dosya);

    printf("Orijinal Metin: %s\n", orijinalMetin);

    // Metni �ifreleme anahatar harflerde kayd�rma yapar bu sayede 3 birim ilerisini al�r ve metin �ifrelenmi� olur
    int anahtar = 3;
    strcpy(sifreliMetin, orijinalMetin); /* orijinal metni kopyala orjinal metnin bizde saklanabilmesi i�in bu k�s�m gereklidir direkt orjinal 
metin �zerinde i�lem yap�lmas� bir sonraki �al��mada �ifrelenmi� metin �zerinden i�lem yapmaya neden olur orjinal dosya kaybolmu� olur*/
    sifrele(sifreliMetin, anahtar);

    printf("Sifreli Metin: %s\n", sifreliMetin);

    // �ifreli metni dosyaya yazma bu sayede �ifrelenmi� metni ayr� bir dosyada g�rebiliriz
    FILE *dosyaSifreli = fopen("sifreli_metin.txt", "w");
    if (dosyaSifreli == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    fprintf(dosyaSifreli, "%s", sifreliMetin);
    fclose(dosyaSifreli);

    // �ifreli metni dosyadan okuyarak ��z�lebilmesi i�in i�leme al�yoruz
    dosyaSifreli = fopen("sifreli_metin.txt", "r");
    if (dosyaSifreli == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    fgets(sifreliMetin, sizeof(sifreliMetin), dosyaSifreli);
    fclose(dosyaSifreli);

    // �ifreli metni ��zme yap�lan i�lemler geri al�narak eklenen anahtar ��kar�larak dosya orjinal haline d�ner
    sifreCoz(sifreliMetin, anahtar);

    // Geri d�n��le orjinal metni ba�ka dosyaya yazar�z  
    FILE *dosyaCozulmus = fopen("cozulmus_metin.txt", "w");
    if (dosyaCozulmus == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    fprintf(dosyaCozulmus, "%s", sifreliMetin);
    fclose(dosyaCozulmus);

    printf("Cozulmus Metin: %s\n", sifreliMetin);

    return 0;
}
