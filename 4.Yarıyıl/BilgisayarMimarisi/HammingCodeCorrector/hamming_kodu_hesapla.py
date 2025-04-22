class HammingHesaplama:
    @staticmethod
    def hamming_kodu_hesapla(veri):
        # Veri uzunluğunu kontrol etme
        Veri = [int(digit) for digit in veri]
        n = len(Veri)
        
        for i in Veri:
            if i != 0 and i != 1:
                raise ValueError("Girilen veri sadece 0 ve 1 içermelidir")

        # Hamming kodu uzunluğunu hesaplama
        m = 0
        while 2 ** m < n + m + 1:
            m += 1

        # Parity bitlerini hesaplama
        hamming_kodu = [0] * (n + m)
        j = 0
        for i in range(1, n + m + 1):
            if i & (i - 1) == 0:
                continue
            hamming_kodu[i - 1] = Veri[j]
            j += 1

        # Hata bitini hesaplama
        for i in range(m):
            parity_index = 2 ** i - 1
            parity = 0
            for j in range(parity_index, n + m, 2 * (parity_index + 1)):
                for k in range(parity_index + 1):
                    if j + k < n + m:
                        parity ^= hamming_kodu[j + k]
            hamming_kodu[parity_index] = parity

        # Hamming kodunu dize olarak birleştirme
        hamming_kodu_str = ''.join(map(str, hamming_kodu))

        return hamming_kodu_str

    def hata_bul(hamming_kodu):
        # Hata bitini bulma
        m = len(hamming_kodu)
        n = m
        while 2 ** n < m + n + 1:
            n += 1

        error_bit = 0
        for i in range(n):
            parity_index = 2 ** i - 1
            parity = 0
            for j in range(parity_index, m, 2 * (parity_index + 1)):
                for k in range(parity_index + 1):
                    if j + k < m:
                        parity ^= hamming_kodu[j + k]
            error_bit += parity * (2 ** i)

        if error_bit != 0:
            print("Hata bulundu, hata biti:", error_bit)
            # Hatanın olduğu biti değiştir
            hamming_kodu[error_bit - 1] = 1 - hamming_kodu[error_bit - 1]

        return hamming_kodu
