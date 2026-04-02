# 📘 Praktikum Sistem Tertanam - Modul 1 Percabangan

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

## 4. (Permintaan tambahan) alur baru

### 🔹 Alur:

`Lambat → Cepat → Sedang → Mati` (tanpa reset langsung)

---

### 🔹 Source Code

```cpp
const int ledPin = 6;       // Menentukan pin LED
int timeDelay = 1000;       // Delay awal (lambat)

void setup() {
  pinMode(ledPin, OUTPUT); // Mengatur pin sebagai output
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(timeDelay);

  digitalWrite(ledPin, LOW);
  delay(timeDelay);

  if (timeDelay > 600) {
    timeDelay -= 200;
  } 
  else if (timeDelay > 300) {
    timeDelay -= 100;
  } 
  else if (timeDelay > 0) {
    timeDelay -= 100;
  } 
  else {
    while(true);
  }
}
```

---

## 🔹 Penjelasan Alur Program

### 1. Kondisi Awal

* `timeDelay = 1000 ms`
* LED berkedip lambat

---

### 2. Percepatan Bertahap

* Program masuk ke blok `if`
* `timeDelay` dikurangi (`-200`)
* LED menjadi lebih cepat

---

### 3. Kondisi Cepat

* Saat `timeDelay <= 600`
* Program masuk ke blok `else if`
* `timeDelay` dikurangi (`-100`)
* LED berkedip lebih cepat lagi

---

### 4. Kondisi Sedang

* Saat `timeDelay <= 300`
* Program tetap di blok `else if`
* Kecepatan mulai distabilkan menuju sedang

---

### 5. Kondisi Mati

* Saat `timeDelay <= 0`
* Program masuk ke blok `else`
* LED berhenti berkedip

---

### 6. Program Berhenti

* `while(true)` menjaga program tetap berhenti
* Tidak terjadi reset ulang


---

### 🔹 Hasil akhir

```
Lambat → Cepat → Sedang → Mati
```
