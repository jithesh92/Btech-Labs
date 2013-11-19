import java.io.*;
abstract class shape {
    int a, b;
    public abstract double area();
    public abstract double peri();
}
class rect extends shape {
    rect() {
        a = 0;
        b = 0;
    }
    rect(int x, int y) {
        a = x;
        b = y;
    }
    public double area() {
        return (a * b);
    }
    public double peri() {
        return (2 * (a + b));
    }
}
class squ extends rect {
    squ() {
        super(0, 0);
    }
    squ(int x) {
        super(x, x);
    }
}
class ellipse extends shape {
    ellipse() {
        a = 0;
        b = 0;
    }
    ellipse(int x, int y) {
        a = x;
        b = y;
    }
    public double area() {
        return (3.14 * a * b);
    }
    public double peri() {
        float z = (a * a + b * b) / 2;
        return (2 * 3.14 * Math.sqrt(z));
    }
}
class circle extends ellipse {
    circle() {
        super(0, 0);
    }
    circle(int x) {
        super(x, x);
    }
}
class Shapee {
    public static void main(String args[]) throws IOException {
        int ch = 0;
        int a, b;
        double area, peri;
        System.out.println("1.rectangle 2.square 3.ellipse 4.circle 5.exit");
        BufferedReader r = new BufferedReader(new InputStreamReader(System. in ));
        shape sh = new rect();
        while (ch != 5) {
            System.out.println("enter your choice");
            ch = Integer.parseInt(r.readLine());
            switch (ch) {
            case 1:
                {
                    System.out.println("enter length and breadth");
                    a = Integer.parseInt(r.readLine());
                    b = Integer.parseInt(r.readLine());
                    sh = new rect(a, b);
                    area = sh.area();
                    peri = sh.peri();
                    System.out.println("area=" + area);
                    System.out.println("perimeter=" + peri);
                    break;
                }
            case 2:
                {
                    System.out.println("enter length ");
                    a = Integer.parseInt(r.readLine());
                    sh = new squ(a);
                    area = sh.area();
                    peri = sh.peri();
                    System.out.println("area=" + area);
                    System.out.println("perimeter=" + peri);
                    break;
                }
            case 3:
                {
                    System.out.println("enter major and minor axis");
                    a = Integer.parseInt(r.readLine());
                    b = Integer.parseInt(r.readLine());
                    sh = new ellipse(a, b);
                    area = sh.area();
                    peri = sh.peri();
                    System.out.println("area=" + area);
                    System.out.println("perimeter=" + peri);
                    break;
                }
            case 4:
                {
                    System.out.println("enter radius");
                    a = Integer.parseInt(r.readLine());
                    sh = new circle(a);
                    area = sh.area();
                    peri = sh.peri();
                    System.out.println("area=" + area);
                    System.out.println("perimeter=" + peri);
                    break;
                }
            case 5:
                System.exit(0);
                break;
            default:
                System.out.println("Invalid choice");
                break;
            }
        }
    }
}