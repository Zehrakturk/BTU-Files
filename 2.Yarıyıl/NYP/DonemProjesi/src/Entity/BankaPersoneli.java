package Entity;
import java.util.List;
import DonemProjesi.*;

public class BankaPersoneli extends Kisi{

	private int personelID;
	private List<Musteri> müsteriler;
	
	public BankaPersoneli(int tcKimlikNo, String ad, String soyad, String email, int telefonNumarasi) {
		super(tcKimlikNo, ad, soyad, email, telefonNumarasi);
		
	}

	public String toString() {
		return getAd();
	}
	
}
