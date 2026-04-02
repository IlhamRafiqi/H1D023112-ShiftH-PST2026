# Pertanyaan Praktikum

1. Pada kondisi apa program masuk ke blok `if`?
2. Pada kondisi apa program masuk ke blok `else`?
3. Apa fungsi dari perintah `delay(timeDelay)`?
4. Jika program memiliki alur `mati → lambat → cepat → reset (mati)`, ubah menjadi `lambat → cepat → sedang → mati (tanpa reset langsung)` dan jelaskan setiap baris kode.

---

# Jawaban

## 1. Kondisi masuk ke blok `if`

Program masuk ke blok `if` ketika nilai `timeDelay <= 100`.

Penjelasan:

* Nilai awal `timeDelay = 1000`
* Setiap loop nilai `timeDelay` berkurang `100`
* Selama nilai masih lebih dari `100` → masuk ke `else`
* Saat `timeDelay` sudah `<= 100` → kondisi TRUE → masuk ke `if`

Contoh alur:

* Loop ke-1: `timeDelay = 1000` → kondisi FALSE → masuk `else`
* Loop ke-2: `timeDelay = 900` → kondisi FALSE → masuk `else`
* ...
* Loop ke-10: `timeDelay = 100` → kondisi TRUE → masuk `if`

---

## 2. Kondisi masuk ke blok `else`

Program masuk ke blok `else` ketika nilai `timeDelay > 100`.

Penjelasan:

* Selama nilai `timeDelay` masih lebih besar dari `100`, kondisi `if` tidak terpenuhi
* Program akan terus menjalankan bagian `else`
* Pada bagian ini, nilai `timeDelay` dikurangi `100` setiap loop (`timeDelay -= 100`)

Contoh alur:

* Loop ke-1: `timeDelay = 1000` → masuk `else` → menjadi `900`
* Loop ke-2: `timeDelay = 900` → masuk `else` → menjadi `800`
* Loop ke-3: `timeDelay = 800` → masuk `else` → menjadi `700`
* ...
* Hingga `timeDelay = 100`, barulah pindah ke blok `if`

---

## 3. Fungsi `delay(timeDelay)`

`delay(timeDelay)` berfungsi untuk memberikan jeda eksekusi program selama `timeDelay` milidetik.

Penjelasan:

* Saat LED `HIGH` → menentukan lama LED menyala
* Saat LED `LOW` → menentukan lama LED mati
* Semakin kecil nilai `timeDelay` → LED semakin cepat berkedip
* Semakin besar nilai `timeDelay` → LED semakin lambat berkedip

Contoh:

```cpp
void loop() {
  // Nyalakan LED
  digitalWrite(ledPin, HIGH);
  delay(timeDelay); // LED ON selama timeDelay ms

  // Matikan LED
  digitalWrite(ledPin, LOW);
  delay(timeDelay); // LED OFF selama timeDelay ms
}
```

---

## 4. (Permintaan tambahan) alur baru

### 🔹 Alur:

`Lambat → Cepat → Sedang → Mati` (tanpa reset langsung)

### 🔹 Source Code

```cpp
const int ledPin = 6;       // Menentukan pin LED
int timeDelay = 1000;       // Delay awal (lambat)

void setup() {
  pinMode(ledPin, OUTPUT); // Mengatur pin sebagai output
}

void loop() {
  // Menyalakan LED
  digitalWrite(ledPin, HIGH);
  delay(timeDelay); // LED ON

  // Mematikan LED
  digitalWrite(ledPin, LOW);
  delay(timeDelay); // LED OFF

  // Percabangan perubahan kecepatan
  if (timeDelay > 600) {
    timeDelay -= 200; // dari lambat ke cepat
  } 
  else if (timeDelay > 300) {
    timeDelay -= 100; // menuju kecepatan sedang
  } 
  else if (timeDelay > 0) {
    timeDelay -= 100; // semakin cepat
  } 
  else {
    while(true); // berhenti (mati)
  }
}
```

---

### 🔹 Penjelasan per baris

* `const int ledPin = 6;` → menentukan pin LED
* `int timeDelay = 1000;` → delay awal (lambat)
* `pinMode(ledPin, OUTPUT);` → set pin sebagai output
* `digitalWrite(HIGH/LOW);` → nyalakan/matikan LED
* `delay(timeDelay);` → atur kecepatan kedipan LED

Percabangan:

* `if (timeDelay > 600)` → fase lambat ke cepat
* `else if (timeDelay > 300)` → fase sedang
* `else if (timeDelay > 0)` → fase sangat cepat
* `else` → program berhenti (LED mati)

---

### 🔹 Hasil akhir

```
Lambat → Cepat → Sedang → Mati
```
