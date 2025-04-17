package Entity;

public class Kisi {
	
	private int tcKimlikNo;
	private String ad;
	private String soyad;
	private String email;
	private int telefonNumarasi;
	
	
	public int getTcKimlikNo() {
		return tcKimlikNo;
	}
	
	public void setTcKimlikNo(int tcKimlikNo) {
		this.tcKimlikNo = tcKimlikNo;
	}
	
	public String getAd() {
		return ad;
	}
	
	public void setAd(String ad) {
		this.ad = ad;
	}
	
	public String getSoyad() {
		return soyad;
	}
	
	public void setSoyad(String soyad) {
		this.soyad = soyad;
	}
	
	public String getEmail() {
		return email;
	}
	
	public void setEmail(String email) {
		this.email = email;
	}
	
	public int getTelefonNumarasi() {
		return telefonNumarasi;
	}
	
	public void setTelefonNumarasi(int telefonNumarasi) {
		this.telefonNumarasi = telefonNumarasi;
	}

	public Kisi(int tcKimlikNo, String ad, String soyad, String email, int telefonNumarasi) {
		
		this.tcKimlikNo = tcKimlikNo;
		this.ad = ad;
		this.soyad = soyad;
		this.email = email;
		this.telefonNumarasi = telefonNumarasi;
	}
	 

	public String toString() {
		return ad;
		
	 }
	
}
