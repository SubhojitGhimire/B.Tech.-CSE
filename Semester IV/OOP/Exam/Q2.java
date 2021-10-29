import java.io.*;
import java.util.*;
import java.lang.*;

class Shape {
    protected static int L, B;

    public void enterDimension () {
        Scanner Scan = new Scanner (System.in);
        int l, b;
        System.out.print ("Enter length: ");
        l = Scan.nextInt ();
        System.out.print ("Enter Breadth: ");
        b = Scan.nextInt ();
        this.L = l;
        this.B = b;
    }

    double area () {
        return 0;
    };
}

class Circle extends Shape {
    double area () {
        int R = super.L;
        return (Math.PI*Math.pow(R, 2));
    }
}

class Rectangle extends Shape {
    double area () {
        int l, b;
        l = super.L;
        b= super.B;
        return l*b;
    }
}

class Trapezoid extends Shape {
    double area () {
        int h, b;
        h = super.L;
        b = super.B;
        return (0.5*h*b);
    }
}

public class Q2 {
    public static void main (String[] args) {
        Shape newShape = new Shape();
        newShape.enterDimension ();
        Circle C = new Circle ();
        System.out.println ("Area of the circle is " + C.area());
        Rectangle R = new Rectangle ();
        System.out.println ("Area of the Rectangle is " + R.area());
        Trapezoid T = new Trapezoid ();
        System.out.println ("Area of the Trapezoid is " + T.area());
    }   
}
