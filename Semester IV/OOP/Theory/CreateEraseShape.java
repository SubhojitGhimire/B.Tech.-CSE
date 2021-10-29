class Shape {
    void draw() {}
    void erase() {}
}

class Circle extends Shape {
    void draw () {
        System.out.println ("Circle Drawn");
    }
    void erase() {
        System.out.println ("Circle Erased");
    }
}

class Square extends Shape {
    void draw () {
        System.out.println ("Square Drawn");
    }
    void erase () {
        System.out.println ("Square Erased");
    }
}

class Triangle extends Shape {
    void draw () {
        System.out.println ("Triangle Drawn");
    }
    void erase () {
        System.out.println ("Triangle Erased");
    }
}