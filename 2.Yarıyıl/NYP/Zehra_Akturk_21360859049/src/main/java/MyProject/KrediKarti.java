package MyProject;

public class KrediKarti {

	private int kartNumarasi;
	double limit;
	double guncelBorc;
	
	
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
	
	
	public KrediKarti() {//parametresiz constuctor
		
	}
	
	public KrediKarti(int kartNumarasi, double limit, double guncelBorc,int kullanılabilirLimit) {
		super();
		this.kartNumarasi = kartNumarasi;
		this.limit = limit;
		this.guncelBorc = guncelBorc;
		kullanılabilirLimit=(int)(limit-guncelBorc);
	}
	
	Musteri musteri =new Musteri();
	KrediKarti karti=new KrediKarti(); //çok saçma burayi düzeltmen gerekiyor.


	public void krediKartiEkle(int kartNumarasi,double limit) {
		musteri.krediKartlari.add(karti);
	}
	
	public void krediKartiSil(int kartNumarasi,double limit) {
		if(guncelBorc==0) {
			musteri.krediKartlari.remove(karti);
		}
		else {
			System.out.println("Lutfen once borc odemesi yapiniz");
		}
	}
	
	public double kullanilabilirLimit(int kartNumarasi, double guncelBorc) {
		return karti.limit;
	}
	
	
	@Override
	public String toString() {
		return "KrediKarti [kartNumarasi=" + kartNumarasi + ", limit=" + limit + ", guncelBorc=" + guncelBorc + "]";
	}
	
	
	
	
}
