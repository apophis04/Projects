package src.com.apophis.shop;

public class Server extends Thread {
    private int serverNumber;

    public Server(int serverNumber) {
        this.serverNumber = serverNumber;
    }

    public int getServerNumber() {
        return serverNumber;
    }

    @Override
    public String toString() {
        return "Server-" + serverNumber;
    }
}

