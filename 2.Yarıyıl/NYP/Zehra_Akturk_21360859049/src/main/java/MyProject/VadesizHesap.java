package MyProject;

import java.util.Date;

public class VadesizHesap extends BankaHesap{

	
	String hesapTuru;
	double vadesizBakiye;
	
	
	public String getHesapTuru() {
		return hesapTuru;
	}
	public void setHesapTuru(String hesapTuru) {
		this.hesapTuru = hesapTuru;
	}
	public double getVadesizBakiye() {
		return vadesizBakiye;
	}
	public void setVadesizBakiye(double vadesizBakiye) {
		this.vadesizBakiye = vadesizBakiye;
	}
	
	public VadesizHesap() {
		
	}
	
	public VadesizHesap(String hesapTuru, double vadesizBakiye) {
		//super(iban, hesapAcilisTarih, vadesizBakiye, hesapTuru, vadesizBakiye, hesapTuru);
		this.hesapTuru = hesapTuru;
		this.vadesizBakiye = vadesizBakiye;
	}
	
	
	@Override
	public String toString() {
		return "VadesizHesap [hesapTuru=" + hesapTuru + ", vadesizBakiye=" + vadesizBakiye + "]";
	}
	
	public double paraTransfer(String hesapTuru,long iban,double vadesizBakiye,int islemMiktar) {
		return vadesizBakiye;//şimdilik vadesizBakiye yi döndürdüm sonrasında işlem sonucunu döndüreceğim
	}
	
	double krediKartiBorcOdeme(double vadesizBakiye, double guncelBorc) {
		KrediKarti kredi = new KrediKarti();
		guncelBorc = kredi.getGuncelBorc();
		if(guncelBorc>vadesizBakiye) {
			vadesizBakiye=0;
			guncelBorc=guncelBorc-vadesizBakiye;
			return guncelBorc;
			
		}
		else if(guncelBorc==vadesizBakiye) {
			vadesizBakiye = 0;
			return guncelBorc = 0;
			
		}else {
			vadesizBakiye  = vadesizBakiye - guncelBorc;
			return guncelBorc = 0;
			
			
		}
		
	}
}
