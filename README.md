**huriyegungorr
Kırklareli Üniversitesi Yazılım mühendisliği bölümünde okuyorum ve yeni proglamlama öğreniyorum yüklediğim ilk çalışmam dosya şifreleme programı:
Kullanıcı yapması gereken: bu program devC++ uygulamasında geliştirilmiştir kullanıcı bu uygulamayı indirip projeyi çalıştırabilir.
kullanıcı şifrelemek istediği dosyayı şifre dosyasının içine ekler ardından kod sayfasında char dosyaAdi kısmına "" içerisine dosyasını yazar ardından programı çalıştırır.
Program içeriği ve özellikleri:
Yüklediğim şifreleme dosyası sayesinde istediğimiz dosyayı şifreleyip daha sonra şifresini çözebiliriz.
Komutları kütüphanemize eklemekle başlarız .   
fopen sayesinde girdiğimiz dosyayı program okur "r" ifadesi sadce okuma yapması için işaretlenmiştir.   
fseek fonksiyonu sayesinde dosya metni başlangıçtan sona kadar okunması için gereklidir aksi halde her satıra tek tek işlem uygular.    
strcpy fonksiyonu sayesinde orjinal metin kopyalanarak saklanır sifrele komutu ile metin şifrelenir yine fopen ile şifreli metin okunur.   
fprint fonksiyou ile okunan şifreli metin yeni şifreli dosyaya yazılır .   
şifre çözme işleminde yine fopen ile şifreli dosya okunur fgets ile işleme alınır,  
sifrecöz komutu ile anahtar değerinde ileri kaydırdığımız işlemi ters yaparız ve geriye dönmüş oluruz,    
fopen ile çözülmüş metni okur fprint ile ayrı çözülmüş dosyaya yazdırırız ve dosyayı kapatırız.      
Aynı zamanda printf ile orjinal metin şifreli metin ve çözülmüş metni ekrana yazdırabiliriz.

