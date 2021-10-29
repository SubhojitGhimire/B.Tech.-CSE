class Animal {
    //overridden method
    public void display() {
        System.out.println ("I am an animal");
    }
}

class Dog extends Animal {
    //overriding method
    @Override 
    public void display() {
        System.out.println ("I am a dog");
    }

    public void printMessage() {
        display();
    }
}

class Main {
    public static void main (String[] args) {
        Dog dog1 = new Dog();
        dog1.printMessage();
    }
}