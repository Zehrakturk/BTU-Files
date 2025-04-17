package MyProject;

import java.util.Date;

public class YatirimHesap extends BankaHesap {

	
	String hesapTuru;
	int yatirimBakiye;
	String yatirimTuru;
	float kur;
	
	
	public String getHesapTuru() {
		return hesapTuru;
	}
	public void setHesapTuru(String hesapTuru) {
		this.hesapTuru = hesapTuru;
	}
	public int getYatirimBakiye() {
		return yatirimBakiye;
	}
	public void setYatirimBakiye(int yatirimBakiye) {
		this.yatirimBakiye = yatirimBakiye;
	}
	public String getYatirimTuru() {
		return yatirimTuru;
	}
	public void setYatirimTuru(String yatirimTuru) {
		this.yatirimTuru = yatirimTuru;
	}
	public float getKur() {
		return kur;
	}
	public void setKur(float kur) {
		this.kur = kur;
	}
	
	public YatirimHesap() {
		
	}
	
	public YatirimHesap(String hesapTuru, int yatirimBakiye, String yatirimTuru, float kur) {
		//super(iban, hesapAcilisTarih, yatirimBakiye, yatirimTuru, kur, hesapBilgisi);
		this.hesapTuru = hesapTuru;
		this.yatirimBakiye = yatirimBakiye;
		this.yatirimTuru = yatirimTuru;
		this.kur = kur;
	}
	

	
	public  double paraEkle(int yatirimBakiye, String yatirimTuru, float kur) {
		return 3.2; //islem sonucu yazilacak
	}
	
	public double paraBoz(int yatirimBakiye, String yatirimTuru,float kur) {
		return 3.2;//buraya işlem sonucu yazilacak
	}
	
	@Override
	public String toString() {
		return "YatirimHesap [hesapTuru=" + hesapTuru + ", yatirimBakiye=" + yatirimBakiye + ", yatirimTuru="
				+ yatirimTuru + ", kur=" + kur + "]";
	}
}
