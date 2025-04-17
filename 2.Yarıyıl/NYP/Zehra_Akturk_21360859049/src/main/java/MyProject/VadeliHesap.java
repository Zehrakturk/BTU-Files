package MyProject;

import java.util.Date;

public class VadeliHesap extends BankaHesap{

	
	String hesapTuru;
	double vadeliBakiye;
	float faizOrani;
	
	public String getHesapTuru() {
		return hesapTuru;
	}

	public void setHesapTuru(String hesapTuru) {
		this.hesapTuru = hesapTuru;
	}

	public double getVadeliBakiye() {
		return vadeliBakiye;
	}

	public void setVadeliBakiye(double vadeliBakiye) {
		this.vadeliBakiye = vadeliBakiye;
	}

	public float getFaizOrani() {
		return faizOrani;
	}

	public void setFaizOrani(float faizOrani) {
		this.faizOrani = faizOrani;
	}

	public VadeliHesap() {
		
	}
	
	public VadeliHesap(String hesapTuru,double vadeliBakiye, float faizOrani) {
		//super(getIban(), getHesapAcilisTarih(), vadeliBakiye, hesapTuru, vadeliBakiye, hesapTuru);
		this.hesapTuru=hesapTuru;
		this.vadeliBakiye=(int) vadeliBakiye;
		this.faizOrani=faizOrani;
	}
	
	public String toString() {
		return hesapTuru;//Burada bir şey yazdıracağımm.
	}
	
	
	
	
}
