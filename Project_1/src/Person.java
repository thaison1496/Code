
public class Person {
	public Person(int c){
		System.out.println(c);
	}
	public Person(){
		
	}
	String b="Lol";
	public void say(int a){
		System.out.println(b);
	}
	private static int age;
	public void setAge(){
		age=10;
	}
	public void growup(){
		age++;
	}
	public void getAge(){
		System.out.println(age);
	}
}
