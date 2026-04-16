# 📘 Praktikum Sistem Tertanam - Modul 2 Pemrograman GPIO

# Pertanyaan Praktikum
1. Gambarkan rangkaian schematic yang digunakan pada percobaan!
2. Mengapa pada push button digunakan mode INPUT_PULLUP pada Arduino Uno? Apa keuntungannya dibandingkan rangkaian biasa?
3. Jika salah satu LED segmen tidak menyala, apa saja kemungkinan penyebabnya dari sisi hardware maupun software?
4. Modifikasi rangkaian dan program dengan dua push button yang berfungsi sebagai penambahan (increment) dan pengurangan (decrement) pada sistem counter dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

---

# Jawaban

## 1. Gambar rangkaian schematic
![Schematic Kontrol Counter](Schematic-Kontrol-Counter-Dengan-Push-Button.png)

---

## 2. Mengapa pada push button digunakan mode INPUT_PULLUP pada Arduino Uno? Apa keuntungannya dibandingkan rangkaian biasa?

Mode `INPUT_PULLUP` digunakan untuk mengaktifkan resistor pull-up internal yang sudah tersedia di dalam Arduino. Dengan mode ini, pin input secara default akan bernilai HIGH, dan akan berubah menjadi LOW ketika push button ditekan (terhubung ke GND).

Penjelasan:
- Tanpa `INPUT_PULLUP`, pin bisa dalam kondisi "floating" (tidak stabil)
- Dengan `INPUT_PULLUP`, tidak perlu resistor eksternal tambahan
- Logika menjadi lebih sederhana (tekan = LOW)

Keuntungan:
- Mengurangi komponen (tidak perlu resistor tambahan)
- Rangkaian lebih sederhana dan rapi
- Menghindari noise atau pembacaan sinyal yang tidak stabil

Kesimpulan: `INPUT_PULLUP` membuat sistem lebih stabil, sederhana, dan efisien.

---

## 3. Jika salah satu LED segmen tidak menyala, apa saja kemungkinan penyebabnya dari sisi hardware maupun software?

Jika salah satu segmen tidak menyala, terdapat beberapa kemungkinan penyebab:

#### 🔧 Dari sisi hardware:
- Kabel tidak terhubung dengan benar
- Resistor rusak atau tidak terpasang
- LED pada segmen tersebut rusak
- Salah koneksi pin pada seven segment
- Common (anode/cathode) tidak terhubung dengan benar

#### 💻 Dari sisi software:
- Kesalahan pada array `digitPattern`
- Urutan pin tidak sesuai dengan program
- Salah logika HIGH/LOW (common cathode vs anode)
- Pin belum di-set sebagai OUTPUT

Kesimpulan: Masalah bisa berasal dari wiring maupun program, sehingga perlu dicek keduanya secara menyeluruh.

---

## 4. Modifikasi rangkaian dan program dengan dua push button (increment & decrement) dan penjelasan kode

### Konsep Modifikasi

Rangkaian ditambahkan satu push button lagi:
- Tombol 1 → Increment (tambah)
- Tombol 2 → Decrement (kurang)

Kedua tombol menggunakan mode `INPUT_PULLUP`.

### Program Modifikasi

```cpp
const int segmentPins[8] = {7,6,5,11,10,8,9,4};

const int btnUp = 3;
const int btnDown = 2;

byte digitPattern[16][8] = {
  {1,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,1,1,0,1,0},
  {1,1,1,1,0,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,0,1,1,0},
  {1,0,1,1,1,1,1,0},
  {1,1,1,0,0,0,0,0},
  {1,1,1,1,1,1,1,0},
  {1,1,1,1,0,1,1,0},
  {1,1,1,0,1,1,1,0},
  {0,0,1,1,1,1,1,0},
  {1,0,0,1,1,1,0,0},
  {0,1,1,1,1,0,1,0},
  {1,0,0,1,1,1,1,0},
  {1,0,0,0,1,1,1,0}
};

int currentDigit = 0;

bool lastUp = HIGH;
bool lastDown = HIGH;

void displayDigit(int num){
  for(int i=0;i<8;i++){
    digitalWrite(segmentPins[i], !digitPattern[num][i]); // common anode
  }
}

void setup(){
  for(int i=0;i<8;i++){
    pinMode(segmentPins[i], OUTPUT);
  }

  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);

  displayDigit(currentDigit);
}

void loop(){
  bool upState = digitalRead(btnUp);
  bool downState = digitalRead(btnDown);

  // increment
  if(lastUp == HIGH && upState == LOW){
    delay(200);
    currentDigit++;
    if(currentDigit > 15) currentDigit = 0;
    displayDigit(currentDigit);
  }

  // decrement
  if(lastDown == HIGH && downState == LOW){
    delay(200);
    currentDigit--;
    if(currentDigit < 0) currentDigit = 15;
    displayDigit(currentDigit);
  }

  lastUp = upState;
  lastDown = downState;
}
```

### Penjelasan Program
- btnUp dan btnDown digunakan sebagai input tombol
- INPUT_PULLUP membuat tombol aktif saat ditekan (LOW)
- currentDigit menyimpan nilai angka yang ditampilkan
- Tombol UP menambah nilai (increment)
- Tombol DOWN mengurangi nilai (decrement)
- Jika lebih dari 15 → kembali ke 0
- Jika kurang dari 0 → kembali ke 15
- Fungsi displayDigit() mengatur tampilan seven segment

### Alur Program
- Tekan tombol UP → angka bertambah
- Tekan tombol DOWN → angka berkurang
- Nilai selalu berada di rentang 0 – 15
- Ditampilkan secara real-time pada seven segment
