package Entity;

import java.util.Date;

import Business.HesapManager;

public class BankaHesap implements HesapManager{

	private long iban;
	private Date HesapAcilirTarihi;
	private double toplamBakiye;
	private String hesapBilgisi;
	private double islemMiktar;
	private String hesapTuru;
	
	public BankaHesap(long iban, Date hesapAcilirTarihi, double toplamBakiye, String hesapBilgisi, double islemMiktar,
			String hesapTuru) {
		super();
		this.iban = iban;
		HesapAcilirTarihi = hesapAcilirTarihi;
		this.toplamBakiye = toplamBakiye;
		this.hesapBilgisi = hesapBilgisi;
		this.islemMiktar = islemMiktar;
		this.hesapTuru = hesapTuru;
	}

	@Override
	public void hesapGoruntuleme(int musteriNumarasi, String ad, String soyad, long iban, double toplamBakiye,
			String hesapBilgisi) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public String toString() {
		return hesapBilgisi;
	}

	
	
}
