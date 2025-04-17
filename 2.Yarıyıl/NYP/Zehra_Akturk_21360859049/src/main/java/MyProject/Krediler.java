package MyProject;

import java.util.List;

public class Krediler {

	private int krediID;
	double krediMiktar;
	double taksitMiktar;

	Musteri musteri = new Musteri();

	public Krediler() {//parametresiz constructor
		
	}
	public Krediler(int krediID, int musteriNumarasi, int krediMiktar) {
		super();
		this.krediID = krediID;
		this.krediMiktar = krediMiktar;
		musteriNumarasi = musteri.getMusteriNumarasi();

		int bakiye = 0;
		List<BankaHesap> hesap;
		hesap = musteri.Hesaplar;
		for (BankaHesap bankaHesap : hesap) {
			bakiye += bankaHesap.getToplamBakiye();
		}
		krediMiktar = bakiye * (50 / 100);

	}
	// public void kampanya(KrediKartiLimit) {

	// }

	public String toString() {
		return "Buraya bir şey yazmalıyım.";
	}

}
