package Entity;

import java.util.List;

import Business.MusteriManager;

public class Musteri extends Kisi implements MusteriManager{

	public Musteri(int tcKimlikNo, String ad, String soyad, String email, int telefonNumarasi) {
		super(tcKimlikNo, ad, soyad, email, telefonNumarasi);
		
	}
	private int musteriNumarasi;
	private List<hesap> Hesaplar;
	
	public void  hesapEkle(int tckimlikNo, int musteriNumarasi, String ad, String soyad) {
		
	}
	
	public void  hesapSil(int tckimlikNo, int musteriNumarasi, String ad, String soyad) {
		
	}
	
	public String toString() {
		String a="Buraya bir şey yazacağım";
		return a;
	}
}
