package MyProject;

import java.util.Date;
import java.util.Scanner;

public  class BankaHesap {
	
	long iban;
	Date hesapAcilisTarih;
	double toplamBakiye;
	String hesapBilgisi;
	double islemMiktar;
	String hesapTuru;
	public int musteriNumarasi;
	
	public long getIban() {
		return iban;
	}
	public void setIban(long iban) {
		this.iban = iban;
	}
	public Date getHesapAcilisTarih() {
		return hesapAcilisTarih;
	}
	public void setHesapAcilisTarih(Date hesapAcilisTarih) {
		this.hesapAcilisTarih = hesapAcilisTarih;
	}
	public double getToplamBakiye() {
		return toplamBakiye;
	}
	public void setToplamBakiye(double toplamBakiye) {
		this.toplamBakiye = toplamBakiye;
	}
	public String getHesapBilgisi() {
		return hesapBilgisi;
	}
	public void setHesapBilgisi(String hesapBilgisi) {
		this.hesapBilgisi = hesapBilgisi;
	}
	public double getIslemMiktar() {
		return islemMiktar;
	}
	public void setIslemMiktar(double islemMiktar) {
		this.islemMiktar = islemMiktar;
	}
	public String getHesapTuru() {
		return hesapTuru;
	}
	public void setHesapTuru(String hesapTuru) {
		this.hesapTuru = hesapTuru;
	}
	
	public BankaHesap() {//parametresiz constructor
		
	}
	
	
	public BankaHesap(long iban, Date hesapAcilisTarih, double toplamBakiye, String hesapBilgisi, double islemMiktar,
			String hesapTuru) {
		super();
		this.iban = iban;
		this.hesapAcilisTarih = hesapAcilisTarih;
		this.toplamBakiye = toplamBakiye;
		//this.hesapBilgisi = hesapBilgisi;
		this.islemMiktar = islemMiktar;
		//this.hesapTuru=hesapTuru;
		
		
		Scanner girdi = new Scanner(System.in);
		System.out.println("hesap turunu seciniz 1- maas hesabi 2- normal hesap");
		int hesap = girdi.nextInt();
		if(hesapTuru=="1") {
			this.hesapBilgisi = "maasHesabi";
		}
		else if(hesapTuru=="2") {
			this.hesapBilgisi = "normalHesabi";

		}
		
		
	}
	
	public void hesapGoruntuleme(int musteriNumarasi, String ad, long iban, double toplamBakiye,String hesapBilgisi) {
		
	}
	
	
	@Override
	public String toString() {
		return "BankaHesap [iban=" + iban + ", hesapAcilisTarih=" + hesapAcilisTarih + ", toplamBakiye=" + toplamBakiye
				+ ", hesapBilgisi=" + hesapBilgisi + ", islemMiktar=" + islemMiktar + ", hesapTuru=" + hesapTuru + "]";
	}
	
	
	
}
