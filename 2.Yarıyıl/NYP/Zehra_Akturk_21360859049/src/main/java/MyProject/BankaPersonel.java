package MyProject;

import java.util.List;

public class BankaPersonel extends Kisi{
	
	private int personelID;
	List<Musteri> müsteriler;
	
	public BankaPersonel() {
		
	}
	public BankaPersonel(int tcKimlikNo, String ad, String soyad, String email, int telefonNumarasi) {
		super(tcKimlikNo, ad, soyad, email, telefonNumarasi);
		
	}

	public String toString() {
		return getAd();
	}
	
	
	
}
