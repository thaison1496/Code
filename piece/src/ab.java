
public class ab {
	public static void main(String[] args){
		TPoint[] points = new TPoint[4];
		points[0] = new TPoint(0,0);
		points[1] = new TPoint(1,1);
		points[2] = new TPoint(1,0);
		points[3] = new TPoint(0,1);
		//System.out.println(points[0].x);
		Piece p = new Piece(points);
		Piece p2 = new Piece("0 0	0 1	 0 2  0 3");
	}
}
