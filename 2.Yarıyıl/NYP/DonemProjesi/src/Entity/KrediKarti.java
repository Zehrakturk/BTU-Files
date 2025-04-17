package Entity;

import Business.KrediKartiManager;

public class KrediKarti implements KrediKartiManager{

	private int kartNumarasi;
	private double limit;
	private double guncelBorc;
	public int getKartNumarasi() {
		return kartNumarasi;
	}
	public void setKartNumarasi(int kartNumarasi) {
		this.kartNumarasi = kartNumarasi;
	}
	public double getLimit() {
		return limit;
	}
	public void setLimit(double limit) {
		this.limit = limit;
	}
	public double getGuncelBorc() {
		return guncelBorc;
	}
	public void setGuncelBorc(double guncelBorc) {
		this.guncelBorc = guncelBorc;
	}
	@Override
	public void KrediKartiEkle(int kartNumarasi, double limit) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void KrediKartiSil(int kartNumarasi, double limit, double guncelBorc) {
		// TODO Auto-generated method stub
		
	}
	
}
