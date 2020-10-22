package breakpoints;

public class Animal {
	
	private String name;
	private String species;
	private String traits;
	private int lifespan;
	
	public Animal() {
		name = "Unknown";
		species = "Unknown";
		traits = "Unknown";
		lifespan = 0;
	}
	
	public Animal(String name, String species, String traits, int lifespan) {
		this.name = name;
		this.species = species;
		this.traits = traits;
		this.lifespan = lifespan;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getSpecies() {
		return this.species;
	}
	
	public String getTraits() {
		return this.traits;
	}
	
	public String getLifespan() {
		return Integer.toString(lifespan);
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setSpecies(String species) {
		this.species = species;
	}
	
	public void setTraits(String traits) {
		this.traits = traits;
	}
	
	public void setLifespan(int lifespan) {
		this.lifespan = lifespan;
	}
	
	public String toString() {
		return "Name: " + getName()
				+ "\nSpecies: " + getSpecies()
				+ "\nTraits: " + getTraits()
				+ "\nLifespan: " + getLifespan();
	}
}
