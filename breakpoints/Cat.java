package breakpoints;

public class Cat extends Animal{
	private static int totalMeows = 0;
	private String actions;
	
	public Cat() {
		super();
		setSpecies("Cat");
		setLifespan(15);
		actions = "Meow, scratch, sleep";
	}
	
	public Cat(String name, String traits) {
		super(name, "Cat", traits, 15);
		actions = "Meow, scratch, sleep";
	}
	
	public String getActions() {
		return actions;
	}
	
	public void setActions(String actions) {
		this.actions = actions;
	}
	
	public String perform() {
		totalMeows++;
		return "Meow~!";
	}
	
	public int checkMeows() {
		return totalMeows;
	}
}
