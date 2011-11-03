package cautruclap;

import java.util.Scanner;

/**
 * @author KEM
 *
 */
public class Bai12 {
	
	public void nhap()
	{		
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap mot so nguyen:" );
		int n = sc.nextInt();
		System.out.print("So "+ n +" la so chinh phuong: " + laNguyenTo(n));
	}
	public static boolean laNguyenTo(double n)
	{
		int s = (int) Math.sqrt(n);
		return (s == Math.sqrt(n));
	}
	public static void main( String [] args)
	{
		Bai12 b12 = new Bai12();
		b12.nhap();
	}

}
