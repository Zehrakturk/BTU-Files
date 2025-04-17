package MyProject;

import java.util.List;

public class Musteri extends Kisi{
	
	private int musteriNumarasi;

	List<BankaHesap> Hesaplar;
	List<KrediKarti> krediKartlari;
	
	public Musteri() {//parametresiz constructor
		
	}
	
	public Musteri(int tcKimlikNo, int musteriNumarasi,String ad,String soyad,String email,int telefonNumarasi) {
		super(tcKimlikNo, ad, soyad, email, telefonNumarasi);
	
		
	}

	
	public int getMusteriNumarasi() {
		return musteriNumarasi;
	}

	public void setMusteriNumarasi(int musteriNumarasi) {
		this.musteriNumarasi = musteriNumarasi;
	}

	public List<BankaHesap> getHesaplar() {
		return Hesaplar;
	}

	public void setHesaplar(List<BankaHesap> hesaplar) {
		Hesaplar = hesaplar;
	}

	public List<KrediKarti> getKrediKartlari() {
		return krediKartlari;
	}

	public void setKrediKartlari(List<KrediKarti> krediKartlari) {
		this.krediKartlari = krediKartlari;
	}

	public void  hesapEkle(int tckimlikNo, int musteriNumarasi, String ad, String soyad) {

		BankaHesap bankaHesap =new BankaHesap();
		if(bankaHesap.musteriNumarasi==this.musteriNumarasi)
		if(bankaHesap.getHesapTuru()=="VadesizHesap") {
			VadesizHesap vadesizHesap=new VadesizHesap();
			Hesaplar.add(vadesizHesap);
			System.out.println("vadesiz hesabınız olusturuldu");
		}
		if(bankaHesap.getHesapTuru()=="VadeliHesap") {
			VadeliHesap vadeliHesap=new VadeliHesap();
			Hesaplar.add(vadeliHesap);
			System.out.println("vadeli hesabınız olusturuldu");
		}
		
		if(bankaHesap.getHesapTuru()=="YatirimHesap") {
			YatirimHesap yatirimHesap=new YatirimHesap();
			Hesaplar.add(yatirimHesap);
		}
	}
	
	public void  hesapSil(int tckimlikNo, int musteriNumarasi, String ad, String soyad) {
		
		BankaHesap bankaHesap =new BankaHesap();
		if(bankaHesap.getToplamBakiye()>0) {
			System.out.println("Lutfen oncelikle bakiyenizi baska bir hesaba aktariniz");
		}
		else if(bankaHesap.getToplamBakiye()==0) {
			Hesaplar.remove(bankaHesap.getHesapTuru());
		}
	}

	@Override
	public String toString() {
		return "Musteri [musteriNumarasi=" + musteriNumarasi + ", Hesaplar=" + Hesaplar + ", krediKartlari="
				+ krediKartlari + "]";
	}

	public Musteri(int musteriNumarasi, List<BankaHesap> hesaplar, List<KrediKarti> krediKartlari) {
		super();
		this.musteriNumarasi = musteriNumarasi;
		Hesaplar = hesaplar;
		this.krediKartlari = krediKartlari;
	}

	
}

