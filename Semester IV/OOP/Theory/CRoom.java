class Room {
    private int room_no;
    private char room_type; //Type-A,B,C,...
    private double room_area;
    private boolean ACmachine;

    public void set_data (int num, char type, double area, boolean ac) {
        room_no = num;
        room_type = type;
        room_area = area;
        ACmachine = ac;
    }

    public void display_data () {
        System.out.println (room_no + " " + room_type + " " + room_area + " " + ACmachine);
    }
}

public class CRoom {
    public static void main (String[] args) {
        Room rum = new Room();
        rum.set_data (12, 'B', 32.43, false);
        rum.display_data();
    }
}