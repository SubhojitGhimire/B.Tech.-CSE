import java.util.Scanner;

class Area {
    public static float dimension1, dimension2;

    private class Circle {
        public Circle () {
            System.out.println ("The area of the circle is: " + Math.PI*Math.pow(dimension1, 2));
        }
    }

    private class Rectangle {
        public Rectangle () {
            System.out.println ("The area of the rectangle is: " + dimension1*dimension2);
        }
    }

    private class Triangle {
        public Triangle () {
            System.out.println ("The area of the triangle is: " + (0.5*dimension1*dimension2));
        }
    }

    void areaCircle () {
        Circle objCircle = new Circle();
    }

    void areaRectangle () {
        Rectangle objRect = new Rectangle();
    }

    void areaTriangle () {
        Triangle objTri = new Triangle();
    }
}

public class ComputeArea {
    public static void main (String[] args) {
        Scanner Scan = new Scanner(System.in);
        Area objArea = new Area();
        System.out.print ("Enter Dimension 1: ");
        objArea.dimension1 = Scan.nextInt();
        System.out.print ("Enter Dimenstion 2: ");
        objArea.dimension2 = Scan.nextInt();
        objArea.areaCircle();
        objArea.areaRectangle();
        objArea.areaTriangle();
    }
}
