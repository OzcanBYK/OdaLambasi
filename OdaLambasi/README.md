# _Akıllı Oda Lambası_

ESP32 kullanılarak Bluetooth aracılığı ile telefondan oda lambasının kontrolü

## Componentler Nasıl Kullanılır
### AppDataTransfer
AppDataTransferConfig.h içinde yer alan tanımlamalar ile ayar yapabilirsiniz.Bunlar;
 - IS_DATATRANMISSION_LOGI_ENABLE: Terminale bilgilendirme yazılarını aktif veya pasif etmek için kullanılır.
 - DEVICE_NAME: Cİhazın Bluetooth adını belirler.
 - BLE_RX_QUEUE_LENGTH: Bluetooth okunan verileri bir kuyruğa ekler ve main fonksiyonunda o kuyruktan okunmasını bekler. Bu değişken o kuyruğun uzunluğunu belirtir. Yani son kaç frame bluetooth verisinin hafızada tutulacağını belirler. 
 
 Eğer başka bir projede bleutoothtan veri okuma ve yazma için kullanacaksanız main dosyanızda bir task oluşturup o taskte kuyruğu kontrol ederek bluetoothtan gelen verileri okuyabilirsiniz.Okurken kuyruktaki veri tipi AppDataTransfer.h dosyasındaki "BleRxData" yapısıdır. Yazmak için ise "AppDataTransfer_BleSendData(BleTxData)" fonksiyonu ile yazabilirsiniz. "BleTxData" AppDataTransfer.h dosyasında tanımlanmış bir yapıdır. Bu yapıyı kullanarak veri yazabilirsiniz.
### LedDriver
LedDriverConfig.h içinde yer alan tanımlamalar ile ayar yapabilirsiniz.Bunlar;
 - IS_STANDART_ACTIVE: Beyaz Led çıkışının kullanılıp kullanılmadığı belirtir.
 - GPIO_NUM_WHITE: Eğer Beyaz Led çıkışı kullanılıyor ise pin numarasını belirtir.
 - IS_RGB_ACTIVE: RGB Led çıkışının kullanılıp kullanılmadığını belirtir.
 - GPIO_NUM_RED: Eğer RGB Led çıkışı kullanılıyor ise kırmızı çıkışın pin numarasını belirtir.
 - GPIO_NUM_GREEN: Eğer RGB Led çıkışı kullanılıyor ise yeşil çıkışın pin numarasını belirtir.
 - GPIO_NUM_BLUE: Eğer RGB Led çıkışı kullanılıyor ise mavi çıkışın pin numarasını belirtir.
 - DUTY_RESOLUTION_BIT: Çıkışların pwm çözünürlüğünün kaç bit olduğunu belirtir. Led sürerken yazdığınız değerler bu değer üzerinden değerlendirilir. Yani beyaz lede 127 yazdığınızda bu değer 8 bitse %50 dolulukla, eğer 9 bitse %25 dolulukla sürülür. 
 - IS_LEDDRIVER_LOGI_ENABLE: Terminale bilgilendirme yazılarını aktif veya pasif etmek için kullanılır.
## Klasör İçerikleri

```
├── CMakeLists.txt
├── components
│   ├── AppDataTransfer
│   │   ├── include
│   │   │   ├── AppDataTransfer.h
│   │   │   └── AppDataTransferConfig.h
│   │   ├── AppDataTransfer.c
│   │   └── CMakeLists.txt
│   └── LedDriver
│       ├── include
│       │   ├── LedDriver.h
│       │   └── LedDriverConfig.h
│       ├── LedDriver.c
│       └── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  Şuan Okuduğunu Dosya
```
