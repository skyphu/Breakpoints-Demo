package breakpoints;

public class Test {
	public static void main(String[] args) {
		Animal blueJay = new Animal("Bluji", "Blue Jay", "blue and black bird", 15);
		
		blueJay.setName("Blueberry");
		
		System.out.println(blueJay.toString());
		System.out.println(blueJay.getName());
		
		Cat sanny = new Cat("Sanny", "white with heterochromia");
		System.out.println(sanny.toString());
		System.out.println(sanny.perform());
		System.out.println(sanny.checkMeows());
		System.out.println(sanny.perform());
		
	}
}
