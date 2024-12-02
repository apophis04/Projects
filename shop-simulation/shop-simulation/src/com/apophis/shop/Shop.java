package src.com.apophis.shop;

import java.util.concurrent.*;
import java.util.Random;

public class Shop {
    private Semaphore waitingAreaSemaphore;
    private Semaphore serverSemaphore;
    private Semaphore cashierSemaphore;
    private Semaphore[] serverResourceSemaphores;
    private Random random = new Random();

    public Shop() {
        // Initialize Semaphores and other data structures
        waitingAreaSemaphore = new Semaphore(15); // Max capacity of the waiting area
        serverSemaphore = new Semaphore(4); // Number of servers
        cashierSemaphore = new Semaphore(1); // Only one customer can pay at a time
        serverResourceSemaphores = new Semaphore[]{
            new Semaphore(2), // Server 1 can make max 2 products
            new Semaphore(4), // Server 2 can make max 4 products
            new Semaphore(3), // Server 3 can make max 3 products
            new Semaphore(2)  // Server 4 can make max 2 products
        };
    }

    public void enterShop(Customer customer) {
        try {
            waitingAreaSemaphore.acquire(); // Acquire a spot in the waiting area
            System.out.println(customer + " entered the shop.");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public Server waitForServer() {
        try {
            serverSemaphore.acquire(); // Wait for a server to become available
            for (int i = 0; i < serverResourceSemaphores.length; i++) {
                if (serverResourceSemaphores[i].tryAcquire()) {
                    return new Server(i);
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        return null;
    }

    public void serveCustomer(Server server, Customer customer) {
        try {
            System.out.println(customer + " is requesting service from " + server + ".");
            Thread.sleep(random.nextInt(1000)); // Simulate product production time
            System.out.println(customer + " has been served by " + server + ".");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            serverResourceSemaphores[server.getServerNumber()].release(); // Release the server resource
        }
    }

    public void payAndLeave(Customer customer) {
        try {
            cashierSemaphore.acquire(); // Acquire the cashier
            System.out.println(customer + " is paying.");
            System.out.println(customer + " is leaving the shop.");
            cashierSemaphore.release(); // Release the cashier for the next customer
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            waitingAreaSemaphore.release(); // Release the spot in the waiting area
            serverSemaphore.release(); // Release the server
        }
    }
}
