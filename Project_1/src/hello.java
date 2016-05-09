import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;

public class hello{
	public static void main(String[] args){
		System.out.println("HelloWorld");
		Person p = new Person();
		p.say(1);
		tryin();
		tryout();
	}
	public static void tryin(){
		Scanner sc = new Scanner(System.in);
		try{
			int a=sc.nextInt();
			String b=sc.next();
			System.out.println(a);
			System.out.println(b);
		}
		catch(Exception e){
			System.out.println("Yeah");
		};
		
		System.out.println("Done");
	//	sc.close();
	}
	public static void tryout(){
		
	}
}