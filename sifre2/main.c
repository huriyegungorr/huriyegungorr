#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void ile istediðimiz komutlarý kütüphanemize ekliyoruz sifrele komutu ile dosyamýzý kaydýrma yöntemi sayesinde þifreliyoruz
void sifrele(char *metin, int anahtar) {
    int i;
    for (i = 0; metin[i] != '\0'; i++) {
        metin[i] = metin[i] + anahtar;
    }
}

//  þifre çözme algoritmasý
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

    // Dosyadan metni okuyarak þifrelenecek metni alýrýz
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    // Tüm metni bir seferde okuma tüm metni tek seferde okuyarak dosyadaki tüm verilerin þifrelenip geri çözülmesini saðlýyoruz
    fseek(dosya, 0, SEEK_END);
    long dosyaUzunlugu = ftell(dosya);
    fseek(dosya, 0, SEEK_SET);

    fread(orijinalMetin, 1, dosyaUzunlugu, dosya);
    fclose(dosya);

    printf("Orijinal Metin: %s\n", orijinalMetin);

    // Metni þifreleme anahatar harflerde kaydýrma yapar bu sayede 3 birim ilerisini alýr ve metin þifrelenmiþ olur
    int anahtar = 3;
    strcpy(sifreliMetin, orijinalMetin); /* orijinal metni kopyala orjinal metnin bizde saklanabilmesi için bu kýsým gereklidir direkt orjinal 
metin üzerinde iþlem yapýlmasý bir sonraki çalýþmada þifrelenmiþ metin üzerinden iþlem yapmaya neden olur orjinal dosya kaybolmuþ olur*/
    sifrele(sifreliMetin, anahtar);

    printf("Sifreli Metin: %s\n", sifreliMetin);

    // Þifreli metni dosyaya yazma bu sayede þifrelenmiþ metni ayrý bir dosyada görebiliriz
    FILE *dosyaSifreli = fopen("sifreli_metin.txt", "w");
    if (dosyaSifreli == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    fprintf(dosyaSifreli, "%s", sifreliMetin);
    fclose(dosyaSifreli);

    // Þifreli metni dosyadan okuyarak çözülebilmesi için iþleme alýyoruz
    dosyaSifreli = fopen("sifreli_metin.txt", "r");
    if (dosyaSifreli == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    fgets(sifreliMetin, sizeof(sifreliMetin), dosyaSifreli);
    fclose(dosyaSifreli);

    // Þifreli metni çözme yapýlan iþlemler geri alýnarak eklenen anahtar çýkarýlarak dosya orjinal haline döner
    sifreCoz(sifreliMetin, anahtar);

    // Geri dönüþle orjinal metni baþka dosyaya yazarýz  
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
