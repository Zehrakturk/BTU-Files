package Entity;

import java.util.Date;

public class VadesizHesap extends BankaHesap {

	public VadesizHesap(String hesapTuru, Date hesapAcilirTarihi ) {
		super(iban, hesapAcilirTarihi, toplamBakiye, hesapBilgisi, islemMiktar, hesapTuru);
		// TODO Auto-generated constructor stub
	}
	
	private String hesapTuru;
	private double vadesizBakiye;

	@Override
	public String toString() {
		return hesapTuru;
	}
	
	
	
}
