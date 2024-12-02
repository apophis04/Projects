package src.com.apophis.shop;

import java.util.Random;

public class Customer extends Thread {
    private int orderSize;
    private Shop shop;

    public Customer(Shop shop) {
        this.shop = shop;
        this.orderSize = new Random().nextInt(25) + 1; // Random order size between 1 and 25
    }

    @Override
    public void run() {
        shop.enterShop(this);

        for (int i = 0; i < orderSize; i++) {
            Server server = shop.waitForServer();
            if (server != null) {
                shop.serveCustomer(server, this);
                shop.payAndLeave(this);
            }
        }
    }

    @Override
    public String toString() {
        return "Customer-" + getId();
    }
}

