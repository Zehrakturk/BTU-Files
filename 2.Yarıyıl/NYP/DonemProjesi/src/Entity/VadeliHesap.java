package Entity;

import java.util.Date;

public class VadeliHesap extends BankaHesap{

	public VadeliHesap(long iban, Date hesapAcilirTarihi, double toplamBakiye, String hesapBilgisi, double islemMiktar,
			String hesapTuru) {
		super(iban, hesapAcilirTarihi, toplamBakiye, hesapBilgisi, islemMiktar, hesapTuru);
		// TODO Auto-generated constructor stub
	}
	
	private String hesapTuru;
	private int vadeliBakiye;
	private float faizOrani;
	
	
	
	@Override
	public String toString() {
		return hesapTuru;
	}
	
}
