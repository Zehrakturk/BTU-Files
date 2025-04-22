import sqlite3
from tkinter import messagebox
import tkinter as tk
from hamming_kodu_hesapla import HammingHesaplama

baglan = sqlite3.connect("veri_deposu.db")
veri = baglan.cursor()

def veri_girisi_yap():
    girdi_veri = entry_veri.get()
    
    try:
        # Veriyi depoya ekle
        hamming_kodu = HammingHesaplama.hamming_kodu_hesapla(girdi_veri)
        # Hesaplanan Hamming kodunu kullan
        # burada hamming kodu ve veriyi işleyebilirsiniz
        print("Hesaplanan Hamming Kodu:", hamming_kodu)
        messagebox.showinfo("Hamming kod hesaplandı.")
    except ValueError as e:
        # Hata durumunda mesaj göster
        messagebox.showerror("Hata", str(e))
    try:
        # Veriyi veritabanına ekle
        veri.execute('''
            INSERT INTO kullaniciverileri (veri,hammingkodu) VALUES (?, ?)
        ''', (girdi_veri, hamming_kodu))
        baglan.commit()
        messagebox.showinfo("Başarılı", "Veri başarıyla eklendi.")
    except Exception as e:
        # Hata durumunda mesaj göster
        messagebox.showerror("Hata", str(e))

def veri_sec():
    # Yeni pencere oluştur
    secim_penceresi = tk.Toplevel(root)
    secim_penceresi.title("Veri Seç")
    
    # Etiket ekleyerek kullanıcıya talimat ver
    talimat_etiketi = tk.Label(secim_penceresi, text="Hata yaratmak için veri seçin.")
    talimat_etiketi.pack()

    # Veritabanından tüm verileri al
    veri.execute("SELECT * FROM kullaniciverileri")
    rows = veri.fetchall()

    # Her veri için bir buton oluştur
    for row in rows:
        veri_id = row[0]
        veri_degeri = row[1]
        button = tk.Button(secim_penceresi, text=veri_degeri, command=lambda veri_id=veri_id, veri_degeri=veri_degeri: veri_degistir(secim_penceresi, veri_id, veri_degeri))
        button.pack(pady=5)

def sadece_bir_bit_degisti(secilen_veri, yeni_veri):
    farkli_bit_sayisi = 0
    for i in range(len(secilen_veri)):
        if secilen_veri[i] != yeni_veri[i]:
            farkli_bit_sayisi += 1
            if farkli_bit_sayisi > 1:
                return False
    return farkli_bit_sayisi == 1

def veri_degistir(pencere, veri_id, veri_degeri):
    # Yeni bir pencere oluştur
    degisiklik_penceresi = tk.Toplevel(pencere)
    degisiklik_penceresi.title("Veri Değiştir")

    # Veriyi göster
    label_veri = tk.Label(degisiklik_penceresi, text="Seçilen Veri: " + str(veri_degeri))
    label_veri.pack(pady=5)

    # Değiştirilecek veriyi al
    secilen_veri = veri.execute("SELECT veri FROM kullaniciverileri WHERE veri_no=?", (veri_id,)).fetchone()[0]

    # Her bir bit için bir değişken oluştur
    bit_degiskenleri = []
    secilen_bit_indeksi = None
    for i in range(len(secilen_veri)):
        bit_label = tk.Label(degisiklik_penceresi, text=f"Bit {i + 1}:")
        bit_label.pack()
        # Başlangıç değeri olarak seçilen verinin bitleri atanır
        bit_deger = int(secilen_veri[i])
        bit_degisken = tk.IntVar(value=bit_deger)  
        bit_degiskenleri.append(bit_degisken)  # Tüm bitlerin değerlerini içeren listeye ekle
        secenek_0 = tk.Radiobutton(degisiklik_penceresi, text="0", variable=bit_degisken, value=0)
        secenek_0.pack(anchor="w")
        secenek_1 = tk.Radiobutton(degisiklik_penceresi, text="1", variable=bit_degisken, value=1)
        secenek_1.pack(anchor="w")

    # Değişiklikleri kaydet butonu
    def degisiklikleri_kaydet():
        yeni_veri = ''.join(str(bit_deger.get()) for bit_deger in bit_degiskenleri)
        if sadece_bir_bit_degisti(secilen_veri, yeni_veri):
            try:
                # Değiştirilen bitin indeksini ve değerini belirle
                for i in range(len(secilen_veri)):
                    if secilen_veri[i] != yeni_veri[i]:
                        degisen_bit_indeksi = i + 1  # 1'den başlayan indeks
                        degisen_bit_degeri = yeni_veri[i]
                        break
                
                # Veriyi veritabanına kaydet
                veri.execute('''
                    INSERT INTO verilervehatalari (veri_no, hatabiti) VALUES (?, ?)
                ''', (veri_id, degisen_bit_indeksi))
                
                baglan.commit()
                messagebox.showinfo("Başarılı", "Değiştirilmiş veri başarıyla kaydedildi.")
            except Exception as e:
                # Hata durumunda mesaj göster
                messagebox.showerror("Hata", str(e))
        else:
            messagebox.showerror("Hata", "Yalnızca bir biti değiştiriniz.")

    kaydet_buton = tk.Button(degisiklik_penceresi, text="Değişiklikleri Kaydet", command=degisiklikleri_kaydet)
    kaydet_buton.pack(pady=5)

def hamming_kodu_onayla(hamming_kodu, pencere):
    try:
        # Veritabanında Hamming kodunu kontrol et
        veri.execute("SELECT veri FROM kullaniciverileri WHERE hammingkodu=?", (hamming_kodu,))
        sonuc = veri.fetchone()

        if sonuc:
            veri_bul = sonuc[0]
            messagebox.showinfo("Doğrulama", f"Girdiğiniz Hamming kodu şu veri ile eşleşiyor:\nVeri: {veri_bul}\nHamming Kodu: {hamming_kodu}")
        else:
            messagebox.showerror("Hata", "Girdiğiniz Hamming kodu veritabanındaki hiçbir veri ile eşleşmiyor.")
        
        pencere.destroy()  # Pencereyi kapat
    except Exception as e:
        # Hata durumunda mesaj göster
        messagebox.showerror("Hata", str(e))

def hamming_kodu_girisi_ac():
    # Yeni pencere oluştur
    hamming_pencere = tk.Toplevel(root)
    hamming_pencere.title("Hamming Kodu Girişi")
    
    # Pencere boyutunu ayarla
    hamming_pencere.geometry("400x200")  # Genişlik: 400 piksel, Yükseklik: 200 piksel
    
    # Hamming kodu giriş alanı
    entry_hamming = tk.Entry(hamming_pencere)
    entry_hamming.pack(pady=5)
    
    # Hamming kodu onay butonu
    button_onay = tk.Button(hamming_pencere, text="Onayla", command=lambda: hamming_kodu_onayla(entry_hamming.get(), hamming_pencere))
    button_onay.pack(pady=5)


def veri_kontrol_et():
    # Yeni pencere oluştur
    kontrol_penceresi = tk.Toplevel(root)
    kontrol_penceresi.title("Veri Kontrol Et")
    
    # Etiket ekleyerek kullanıcıya talimat ver
    talimat_etiketi = tk.Label(kontrol_penceresi, text="Kontrol etmek istediğiniz veriyi girin.")
    talimat_etiketi.pack()
    
    # Veri giriş alanı
    entry_veri_kontrol = tk.Entry(kontrol_penceresi)
    entry_veri_kontrol.pack(pady=5)
    
    # Onay butonu
    button_onay = tk.Button(kontrol_penceresi, text="Onayla", command=lambda: kontrol_et(entry_veri_kontrol.get(), kontrol_penceresi))
    button_onay.pack(pady=5)

def kontrol_et(girdi_veri, pencere):
    try:
        # Kullanıcıdan girilen veriyle veritabanındaki veriyi kontrol et
        veri.execute("SELECT veri_no, veri, hammingkodu FROM kullaniciverileri")
        veriler = veri.fetchall()

        veri_bulundu = False
        hatali_veri_bilgisi = None
        hatabiti = None

        for veri_no, orijinal_veri, hamming_kodu in veriler:
            veri.execute("SELECT hatabiti FROM verilervehatalari WHERE veri_no=?", (veri_no,))
            hatalar = veri.fetchall()
            
            for hata in hatalar:
                hatabiti = hata[0] - 1  # Veritabanındaki bit pozisyonu 1 tabanlı olduğundan 0 tabanlı hale getir
                
                # Orijinal veriyi hatalı hale getir
                hatali_veri = list(orijinal_veri)
                hatali_veri[hatabiti] = '1' if hatali_veri[hatabiti] == '0' else '0'
                hatali_veri = ''.join(hatali_veri)
                
                # Kullanıcının girdisiyle kontrol et
                if girdi_veri == hatali_veri:
                    veri_bulundu = True
                    hatali_veri_bilgisi = (orijinal_veri, hatabiti + 1, hatali_veri, hamming_kodu)  # 1 tabanlı hale getirmek için +1
                    break
            
            if veri_bulundu:
                break

        if veri_bulundu:
            orijinal_veri, hatabiti, hatali_veri, hamming_kodu = hatali_veri_bilgisi
            messagebox.showinfo("Doğrulama", f"Girdiğiniz veri hatalı veri ile eşleşiyor.\n"
                                             f"Orijinal Veri: {orijinal_veri}\n"
                                             f"Hata Biti: {hatabiti}\n"
                                             f"Hatalı Veri: {hatali_veri}\n"
                                             f"Hamming Kodu: {hamming_kodu}")
        else:
            messagebox.showerror("Hata", "Girdiğiniz veri hatalı veri ile eşleşmiyor.")
        
        pencere.destroy()  # Pencereyi kapat
    except Exception as e:
        # Hata durumunda mesaj göster
        messagebox.showerror("Hata", str(e))



baglan = sqlite3.connect("veri_deposu.db")
veri = baglan.cursor()

root = tk.Tk()
root.title("Hamming Kodu Uygulamasi")

label_veri = tk.Label(root, text="Veri Giriniz:", width="40")
label_veri.pack(pady=5)

entry_veri = tk.Entry(root)
entry_veri.pack(pady=5)

frame_veri = tk.Frame(root)
frame_veri.pack(pady=5)

button_veri = tk.Button(frame_veri, text="Veri Girişi Yap", command=veri_girisi_yap)
button_veri.pack(side="left", padx=5)

button_veri = tk.Button(frame_veri, text="Veri Seç", command=veri_sec)
button_veri.pack(side="left", padx=5)

button_kontrol = tk.Button(frame_veri, text="Veriyi Kontrol Et", command=veri_kontrol_et)
button_kontrol.pack(side="left", padx=5)

hamming_kodu_label = tk.Label(root, text="")
hamming_kodu_label.pack(pady=10)

button_hamming_girisi = tk.Button(root, text="Hamming Kodu Girişi", command=hamming_kodu_girisi_ac)
button_hamming_girisi.pack(pady=5)

root.mainloop()
